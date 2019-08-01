#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"
#define GP2Y0Ed         0x40//default
#define GP2Y0E          0x40//default
#define SHIFT_BYTE      0x02 //64 cm shift = 2 128 cm shift = 1
#define SHIFT_ADDR      0x35
#define DISTANCE_ADDR1  0x5E
#define DISTANCE_ADDR2  0x5F
#define RIGHT_EDGE_ADDR 0xF8 // C
#define LEFT_EDGE_ADDR  0xF9 // A
#define PEAK_EDGE_ADDR  0xFA // B   

volatile uint16 cf=1;
const uint8 frecuencia=10;
uint8 n=0;
volatile _Bool muestreo=false;
char buffer2[12]={};
volatile char dato;
char distance_cm=0;
char buffer[12]={};
_Bool inicio=false;
//const int MAXDIRI=4435; 
//const int MINDIRI=3695;

//const int CENDIRI=4065;
//const int CENDIRD=2225;

//const int MAXDIRD=2595;
//const int MINDIRD=1855;

//const int DDIRI=37;
//const int DDIRD=37;



int16 temp,count;
unsigned char valor;
unsigned char velo=105;
//volatile unsigned int direcciond=2240;//
//volatile unsigned int direccioni=4080;//CENTRO
volatile bool banderaS=false,banderaG=false,banderaForward=false,banderaPause=false,banderaDoor=true,banderaR=false,banderaL=false,banderaSpeed=false,banderaD=false,banderaBack=false,banderaMax=false,banderaW=false;
volatile char dato;
unsigned char cont=0;

CY_ISR(INTTIMER){
    if(cf==frecuencia){
        muestreo=true;cf=1;
    }else{cf=cf+1;}
}
bool DS_beginread (char sladress){
    bool out=true;
    if(I2C_MasterSendStart(sladress, I2C_READ_XFER_MODE)!=I2C_MSTR_NO_ERROR){
        I2C_MasterSendStop();
        out=false;
        I2C_Stop();
        I2C_Start();
        //UART_PutString("Tiempo exedido READ\r\n"); 
    }
    return out;
}      //sladress= direccion del esclavo
bool DS_beginwrite(char sladress){
    bool out=true;
    if(I2C_MasterSendStart(sladress, I2C_WRITE_XFER_MODE)!=I2C_MSTR_NO_ERROR){
        I2C_MasterSendStop();
        I2C_Stop();
        I2C_Start();
        out=false;
        //UART_PutString("Tiempo exedido WRITE\r\n");  
    }
    return out;
}
unsigned char DS_get_data(char sladress){   
    unsigned char distance_cm='0',    datai2c[2]={0,0};
    if(DS_beginwrite(sladress)){            // inicia comunicacion
        I2C_MasterWriteByte(DISTANCE_ADDR1);//Pone direccion de memoria que quiere leer 
        I2C_MasterSendStop(); 
        DS_beginread(sladress);
        datai2c[0]=I2C_MasterReadByte(I2C_NAK_DATA);//captura el dato 1 con nak salta un registro para leer el siguiente espacio de memoria
        datai2c[1]=I2C_MasterReadByte(I2C_NAK_DATA);// lee el siguiente espacio de memoria
        I2C_MasterSendStop();
        distance_cm = (datai2c[0]*16+datai2c[1])/64;//calculo de distancia
    }else{
        distance_cm =99;
    }
    return distance_cm;
}


void TurnRight(){
    IMPD_Write(1);// 1 ADELANTE 2 ATRAS
    IMAD_Write(1);
    IMPI_Write(2);
    IMAI_Write(2);
    PWM_Motores_A_WriteCompare1(100);
    PWM_Motores_A_WriteCompare2(150);
    PWM_Motores_P_WriteCompare1(100);
    PWM_Motores_P_WriteCompare2(150);
}



void TurnLefth(){
    IMPD_Write(2);// 1 ADELANTE 2 ATRAS
    IMAD_Write(2);
    IMPI_Write(1);
    IMAI_Write(1);
    PWM_Motores_A_WriteCompare1(150);
    PWM_Motores_A_WriteCompare2(100);
    PWM_Motores_P_WriteCompare1(150);
    PWM_Motores_P_WriteCompare2(100);
}

void Forward(){
    IMPD_Write(1);// 1 ADELANTE 2 ATRAS
    IMAD_Write(1);
    IMPI_Write(1);
    IMAI_Write(1);
    if(!banderaMax){
        banderaSpeed=true;
    }
}

void Back(){
    IMPD_Write(2);// 1 ADELANTE 2 ATRAS
    IMAD_Write(2);
    IMPI_Write(2);
    IMAI_Write(2);
    PWM_Motores_A_WriteCompare1(200);
    PWM_Motores_A_WriteCompare2(200);
    PWM_Motores_P_WriteCompare1(200);
    PWM_Motores_P_WriteCompare2(200);

}





CY_ISR(InterruptRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case '0':{
        //Adelante Inicio
            banderaForward=true;
            break;
        }
        case '1':{
            //Atras Inicio
            banderaBack=true;            
            break;
        }
        case '2':
        {
            //Derehcha 10 °
            banderaR=true;
            break;
        }
        case '3':{
            //Izquierda  10 °
            banderaL=true;
            break;
        }
         case '4':{
            //Adelante Fin
            velo=0;
            banderaPause=true;
            banderaSpeed=false;
            break;
        }
        case '5':{
            // Atras Fin
            velo=0;
            banderaPause=true;
            banderaSpeed=false;
            break;
        }
        case 'X':
        {               
            break;
        }
        case 'Z':
        {   
            break;
        }
        case 'F':
        {   // Enceder o Agapar luces
            LED_Write(~LED_Read());  
            break;
        }
        case 'S':
        {   //Activar motores de Recojer Bola se deben desactivar solos
            banderaS=true;
            break;
        }
        case 'W':
        {   //Ingreso de bola

            banderaW=true;
            break;
        }
        case 'D':{
            //Lanzar Bola
            banderaD=true;
            break;
        }
        case 'A':{
            //Sprint
            if(!banderaMax){
                velo=255;
                banderaMax=true;
            }else{
                velo=105;
                banderaMax=false;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

CY_ISR(InterruptFoto){
    if(!banderaDoor){
        PWM_D_A_WriteCompare1(2000);
        banderaDoor=true;
    }
    INFRA_ClearInterrupt();
}

int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    LED_Write(0);
    UART_Start(); 
    IRQRX_StartEx(InterruptRx);
    //---Motores----//
    PWM_Motores_A_Start();
    PWM_Motores_A_WriteCompare1(0);
    PWM_Motores_A_WriteCompare2(0);
    IMAD_Write(0);
    IMAI_Write(0);
    PWM_Motores_P_Start();
    PWM_Motores_P_WriteCompare1(0);
    PWM_Motores_P_WriteCompare2(0);
    IMPD_Write(0);
    IMPI_Write(0);
    //----Ascensor---
    PWM_D_A_Start();
    PWM_D_A_WriteCompare1(0);
    IMAS_Write(0);
    //---Puerta-----
    PWM_D_A_WriteCompare1(5500);
    //----Lanzamiento---
    IML_Write(0);
    //--- SENSOR---
    //DS_init(0x40);//Inicia sensor de distancia
    //--Sensor de puerta----
    I2C_Start();
    ISR_TIMER_StartEx(INTTIMER);
    TIMER_Start();
    CyDelay(500);
    ISR_FOTO_StartEx(InterruptFoto);
    banderaDoor=false;
    for(;;)
    {
        if(banderaSpeed&&muestreo){
            if((velo<255)&&(!banderaPause)){
                PWM_Motores_A_WriteCompare1(velo);
                PWM_Motores_A_WriteCompare2(velo);
                PWM_Motores_P_WriteCompare1(velo);
                PWM_Motores_P_WriteCompare2(velo);
                velo=velo+5;
            }else{
                banderaSpeed=false;
               // banderaPause=true;
            }
        }
        
        if(banderaPause){
                PWM_Motores_A_WriteCompare1(0);
                PWM_Motores_A_WriteCompare2(0);
                PWM_Motores_P_WriteCompare1(0);
                PWM_Motores_P_WriteCompare2(0);
                IMPD_Write(0);// 1 ADELANTE 2 ATRAS
                IMAD_Write(0);
                IMPI_Write(0);
                IMAI_Write(0);
                if(!banderaMax){
                    velo=105;
                }
                banderaPause=false;
        }
        
        
        if(banderaForward){
            Forward();
            banderaForward=false;
        }
        
        if(banderaL){
            TurnLefth();
            banderaL=false;
        }
        
        if(banderaR){
            TurnRight();
            banderaR=false;
        }
        
        if(banderaBack){
            Back();
            banderaBack=false;
            
        }
        if(banderaS){//Ascensor
            IMAS_Write(1);
            PWM_D_A_WriteCompare2(24000);
            CyDelay(2200);
            PWM_D_A_WriteCompare2(0);
            banderaS=false;
        }
        if(banderaD){
            IML_Write(1);
            Lanzamiento_Write(1);
            CyDelay(800);
            Lanzamiento_Write(0);
            banderaD=false;
        }
        
        if(banderaW){
            if(banderaDoor){                
                PWM_D_A_WriteCompare1(5500); //Pasa a 180 grados
                CyDelay(500);
                banderaDoor=false;
            }else{
                PWM_D_A_WriteCompare1(2000); // pasa a 0 grados
                banderaDoor=true;
            }
            banderaW=false;
            
        }
            
        if(muestreo){
            int sensor1=(int)DS_get_data(0x68);
            int sensor2=(int)DS_get_data(0x68);
            int sensor3=(int)DS_get_data(0x68);
            int sensor4=(int)DS_get_data(0x68);
            int sensor5=(int)DS_get_data(0x68);
            n=n+1;
            if(n==4){
            n=0;
            sprintf(buffer2,"%d\r\n",sensor1);
        	UART_PutString(buffer2);
            sprintf(buffer2,"%d\r\n",sensor2);
        	UART_PutString(buffer2);
            sprintf(buffer2,"%d\r\n",sensor3);
        	UART_PutString(buffer2);
            sprintf(buffer2,"%d\r\n",sensor4);
        	UART_PutString(buffer2);
            sprintf(buffer2,"%d\r\n",sensor5);
        	UART_PutString(buffer2);
            }
            muestreo=false;
        }
}
}

/* [] END OF FILE */
