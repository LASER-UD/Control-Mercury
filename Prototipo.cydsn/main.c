#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define GP2Y0E          (0x80)>>1
#define SHIFT_BYTE      0x02 //64 cm shift = 2 128 cm shift = 1
#define SHIFT_ADDR      0x35
#define DISTANCE_ADDR1  0x5E
#define DISTANCE_ADDR2  0x5F
#define RIGHT_EDGE_ADDR 0xF8 // C
#define LEFT_EDGE_ADDR  0xF9 // A
#define PEAK_EDGE_ADDR  0xFA // B

char buffer[12]={};
int16 temp,count;
unsigned char valor;
volatile uint16 direccion;
volatile bool banderag=false,bandera1=false,banderaS=false;
volatile char dato;
char datai2c[2]={0,0};
char distance_cm=0;


void DS_beginread (void){
        do{
                //Espera mienstras el esclavo le responde
        }while(I2C_MasterSendStart(GP2Y0E, I2C_WRITE_XFER_MODE)!=I2C_MSTR_NO_ERROR);
}
void DS_beginwrite(void){
        do{
                //Espera mienstras el esclavo le responde
    }while(I2C_MasterSendStart(GP2Y0E, I2C_READ_XFER_MODE)!=I2C_MSTR_NO_ERROR);
}
void DS_init(void){
    //Funcion de configuracion o de escritura de registros
    DS_beginread();
    I2C_MasterWriteByte(SHIFT_ADDR);//Pone direccion de memoria que quiere leer 
    I2C_MasterSendStop(); 
    DS_beginwrite();
    sprintf(buffer,"shift %02X\n\r",I2C_MasterReadByte(I2C_NAK_DATA));//lo codifica en ascci
    I2C_MasterSendStop();
    UART_PutString(buffer);
}

void DS_get_data(){                   
    DS_beginread();
    I2C_MasterWriteByte(DISTANCE_ADDR1);//Pone direccion de memoria que quiere leer 
    I2C_MasterSendStop(); 
    DS_beginwrite();
    datai2c[0]=I2C_MasterReadByte(I2C_NAK_DATA);//lo codifica en ascci
    datai2c[1]=I2C_MasterReadByte(I2C_NAK_DATA);
    I2C_MasterSendStop();
    distance_cm = (datai2c[0]*16+datai2c[1])/64;//calculo de distancia
}


char DS_read(char adress){                   
    char data;
    DS_beginread();
    I2C_MasterWriteByte(adress);//Pone direccion de memoria que quiere leer 
    I2C_MasterSendStop(); 
    DS_beginwrite();
    data=I2C_MasterReadByte(I2C_NAK_DATA);//lo codifica en ascci
    I2C_MasterSendStop();
    return data;
}

void DS_write(char adress, char load){
DS_beginwrite();
I2C_MasterWriteByte(adress);
I2C_MasterWriteByte(load);
I2C_MasterSendStop();
}

static void e_fuse_stage1() {
    DS_write(0xEC, 0xFF);
    vpp_distance_Write(1);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 2
 * Data=0x00 is set in Address=0xC8.
 */
void e_fuse_stage2() {

    DS_write(0xC8, 0x00);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 3
 * Data=0x45 is set in Address=0xC9.
 * + programming bit #: 5 => 5 - 1 = 4
 * + bank value: 5 => Bank E
 */
void e_fuse_stage3() {
  
    DS_write(0xC9, 0x45);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 4
 * Data=0x01 is set in Address=0xCD.
 * (Data=0x01 for slave address being changed to 0x10(write) and 0x11(read))
 * @param new_address 0-15 (Default address is 8, 0x80 for writing and 0x81 for reading)
 */
void e_fuse_stage4(uint8_t new_address) {
    
    DS_write(0xCD, new_address);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 5
 * Data=0x01 is set in Address=0xCA.
 * Wait for 500us.
 */
void e_fuse_stage5() {
   
    DS_write(0xCA, 0x01);
    CyDelay(500);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 6
 * Data=0x00 is set in Address=0xCA.
 * Vpp terminal is grounded.
 */
void e_fuse_stage6() {
   
    DS_write(0xCA, 0x00);
    vpp_distance_Write(0);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 7
 * Data=0x00 is set in Address=0xEF.
 * Data=0x40 is set in Address=0xC8.
 * Data=0x00 is set in Address=0xC8.
 */
void e_fuse_stage7() {
   
    DS_write(0xEF, 0x00);
    DS_write(0xC8, 0x40);
    DS_write(0xC8, 0x00);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 8
 * Data=0x06 is set in Address=0xEE.
 */
void e_fuse_stage8() {
   
    DS_write(0xEE, 0x06);
}

/*
 * (Fig.40 E-Fuse Program Flow)
 * Stage 9
 * Data=0xFF is set in Address=0xEC.
 * Data=0x03 is set in Address=0xEF.
 * Read out the data in Address=0x27.
 * Data=0x00 is set in Address=0xEF.
 * Data=0x7F is set in Address=0xEC.
 *
 * @return 0 for success, 1 for failure : 0x27[4:0] & 0b10000(0x10)
 */
uint8_t e_fuse_stage9() {
   
    // Table.20 List of E-Fuse program flow and setting value
    DS_write(0xEF, 0x00); // add this though it's missing in 12-6 Example of E-Fuse Programming
    DS_write(0xEC, 0xFF);
    DS_write(0xEF, 0x03);
    //const uint8_t check_value = _i2c_read(0x27);
    //const uint8_t check = check_value & 0x1f;
   
    //const uint8_t success = check & 0x10;
    // When lower 5bits data[4:0] is 00001, E-Fuse program is finished.
    // When lower 5bits data[4:0] is not 00001, go to stage10(bit replacement).
    DS_write(0xEF, 0x00);
    DS_write(0xEC, 0x7F);
    // Check Result
    return success;
}



void TurnLefth(){//Giro Izquierda

     if (direccion<=5700)//(5700 azul) maximo 784 (180°)
    {
        //con una adiccion de 20 cambia 5° y con 40 cambia 10°
        direccion=direccion+40;
        PWM2_WriteCompare(direccion);
    }
    PWM_WriteCompare1(100);//Activa el motor
    CyDelay(100);
    PWM_WriteCompare1(0);
    direccion=3650;//la mitad para que quede en el centro
    PWM2_WriteCompare(direccion);
}

void TurnRight(){//Giro Derecha
     if (direccion>=1600)//(1600 azul) minimo 154 (0°)
    {
        //con una adiccion de 20 cambia 5° y con 40 cambia 10°
        direccion=direccion-40;
        PWM2_WriteCompare(direccion);
    }
    PWM_WriteCompare2(100);//Activa el motor
    CyDelay(100);
    PWM_WriteCompare2(0);
    direccion=3650;//la mitad para que quede en el centro
    PWM2_WriteCompare(direccion);
}

CY_ISR(InterrupRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case 'g':{
            //Pide datos de sensor
            banderag=true;        
            break;
        }
        case '1':{
            //Adelante Inicio
            
            break;
        }
        case '2':
        {
            //Atras Fin
            
            
            break;
        }
        case '3':{
            //Deracha  10 °
            
            
            break;
        }
         case '4':{
            //Izquierda 10 °
            
            break;
        }
        case '5':{
            // Adelante Fin
            
            
            break;
        }
        
        case '6':
        {   // Atras Fin
            
            
            break;
        }
        case 'X':
        {   // Giro 90 ° Izquierda
            for(char i=0;i<9;i++){
                TurnLefth();
            }
            
            break;
        }
        case 'Z':
        {   // Giro 90 ° Derecha
            for(char i=0;i<9;i++){
                TurnRight();
            }
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
        {   //Activar plataforma para subir bola
            
            
            break;
        }
        case 'D':{
            //Lanzar Bola
            
            break;
        }
        case 'A':{
            //Sprint 
            
            break;
        }
        default:
        {
            break;
        }
    }
}


int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    IRQRX_StartEx(InterrupRx);
    PWM_Start();
    PWM2_Start();
    ADC_Start();
    I2C_Start();
    PWM_WriteCompare1(255);
    PWM_WriteCompare2(255);
    /* Codigo para controlar desde App
    UART_PutString("*.kwl\r\n");
    UART_PutString("clear_panel()\r\n");
    UART_PutString("set_grid_size(15,9)\r\n");
    UART_PutString("add_text(3,1,medium,L,\"Amarillo Luces --\\nAzul Toma Bola --\\nRojo Sube Bola -- \\nVerde Lanza Bola\",245,240,245,)\r\n");
    UART_PutString("add_button(7,6,2,0,4)\r\n");
    UART_PutString("add_button(7,8,3,1,5)\r\n");
    UART_PutString("add_button(9,8,5,2,)\r\n");
    UART_PutString("add_button(9,6,11,X,)\r\n");
    UART_PutString("add_button(5,6,10,Z,)\r\n");
    UART_PutString("add_button(5,8,4,3,)\r\n");
    UART_PutString("add_button(13,7,28,F,)\r\n");
    UART_PutString("add_button(13,1,30,S,)\r\n");
    UART_PutString("add_button(0,1,27,S,)\r\n");
    UART_PutString("add_button(0,7,29,D,)\r\n");
    UART_PutString("add_monitor(5,2,5,,1)\r\n");
    UART_PutString("set_panel_notes(,,,)\r\n");
    UART_PutString("run()\r\n");
    UART_PutString("*"\r\n);*/
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia
    //DS_beginread();
    UART_PutString("Salio\r\n");
    for(;;)
    {
        if(banderag){
            ADC_StartConvert();
            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
            temp=ADC_GetResult16(); // actualiza Roll Graph
            valor=((50*temp)/255);
            sprintf(buffer,"%d\n",valor);//lo codifica en ascci
            UART_PutString(buffer);
            banderag=false;
        }
        DS_get_data();     
        sprintf(buffer,"%d\n\r",distance_cm);//lo codifica en ascci
        UART_PutString(buffer);
        CyDelay(500);         // velocidad de sensado
        
    }
}

/* [] END OF FILE */
