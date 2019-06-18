#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"

const int MAXDIRI=4450; 
const int MINDIRI=3710;

const int MAXDIRD=2590;
const int MINDIRD=1870;

const int DDIRI=37;
const int DDIRD=36;


char buffer2[12]={};
int16 temp,count;
unsigned char valor;
volatile unsigned int direcciond=2230;//
volatile unsigned int direccioni=4080;//CENTRO
volatile bool banderag=false,bandera1=false;
volatile char dato;


void TurnLefth(){//Giro Izquierda

      if (direccioni<MAXDIRI)
    {
        direccioni=direccioni+DDIRI;
        PWM_Dir_WriteCompare2(direccioni);
    }
    
     if (direcciond<MAXDIRD)
    {
        direcciond=direcciond+DDIRD;
        PWM_Dir_WriteCompare1(direcciond);
    }
  
        
}

void TurnRight(){


    
      if (direccioni>MINDIRI)
        {   
        direccioni=direccioni-DDIRI;
        PWM_Dir_WriteCompare2(direccioni); 
    }
    
    if (direcciond>MINDIRD)
    {   
        direcciond=direcciond-DDIRD;
        PWM_Dir_WriteCompare1(direcciond); 
    }  
    
   
}

CY_ISR(InterrupRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case 'g':{
            //Pide datos de sensor
            banderag=true;        
            break;
        }
        case '0':{
        //Adelante Inicio
            PWM_Motores_WriteCompare1(100);
            PWM_Motores_WriteCompare2(100);
            INMD_Write(1);
            INMI_Write(1);       
            
            break;
        }
        case '1':{
            //Atras Inicio
            PWM_Motores_WriteCompare1(100);
            PWM_Motores_WriteCompare2(100); 
            INMD_Write(2);
            INMI_Write(2);
            
            break;
        }
        case '3':
        {
            //Izquierda 10 °
            TurnLefth();
            sprintf(buffer2,"*T%d*Der: ",direcciond);
            UART_PutString(buffer2);
            UART_PutString("\r\n");
            sprintf(buffer2,"*T%d*Iz: ",direccioni);
            UART_PutString(buffer2);
            UART_PutString("\r\n");
            break;
        }
        case '2':{
            //Deracha  10 °
            TurnRight();
            sprintf(buffer2,"*T%d*Der: ",direcciond);
            UART_PutString(buffer2);
            UART_PutString("\r\n");
            sprintf(buffer2,"*T%d*Iz: ",direccioni);
            UART_PutString(buffer2);
            UART_PutString("\r\n");
            break;
        }
         case '4':{
            //Adelante Fin   
            PWM_Motores_WriteCompare1(0);
            PWM_Motores_WriteCompare2(0);
            INMD_Write(0);
            INMI_Write(0);
            break;
        }
        case '5':{
            // Atras Fin
            PWM_Motores_WriteCompare1(0);
            PWM_Motores_WriteCompare2(0);
            INMD_Write(0);
            INMI_Write(0);            
            break;
        }
        
        case '6':
        {   
            
            
            break;
        }
        case 'X':
        {   // Giro 90 ° Izquierda
//            for(char i=0;i<9;i++){
//                TurnLefth();
//            }
            
            break;
        }
        case 'Z':
        {   // Giro 90 ° Derecha
//            for(char i=0;i<9;i++){
//                TurnRight();
//            }
            break;
        }
        case 'F':
        {   // Enceder o Agapar luces
            LED_Write(~LED_Read());  
            break;
        }
        case 'S':
        {   //Activar motores de Recojer Bola se deben desactivar solos
            
            break;
        }
        case 'W':
        {   //Activar plataforma para subir bola
            Ascensor_Write(1);
            INMD_Write(1);
            INMI_Write(0);
            CyDelay(5000);
            Ascensor_Write(0);
            INMD_Write(0);
            INMI_Write(0);
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
    PWM_Motores_Start();
    ADC_Start();
    INMD_Write(0);
    INMI_Write(0);
    PWM_Motores_WriteCompare1(0);
    PWM_Motores_WriteCompare2(0);
    PWM_Dir_Start();
    PWM_Dir_WriteCompare1(direcciond);//en cero
    PWM_Dir_WriteCompare2(direccioni);//en cero
    // Ascensor
    Ascensor_Write(0);
    INMD_Write(0);
    INMI_Write(0); 
    
    /* Codigo para controlar desde App*/
    UART_PutString("*.kwl\r\n");
    UART_PutString("clear_panel()\r\n");
    UART_PutString("set_grid_size(15,9)\r\n");
    UART_PutString("add_text(3,1,medium,L,\"Amarillo Luces --\\nAzul Toma Bola --\\nRojo Sube Bola -- \\nVerde Lanza Bola\",245,240,245,)\r\n");
    UART_PutString("add_button(7,6,2,0,4)\r\n");
    UART_PutString("add_button(7,8,3,1,5)\r\n");
    UART_PutString("add_button(9,8,5,2,)\r\n");
    UART_PutString("add_button(5,8,4,3,)\r\n");
    UART_PutString("add_button(9,6,11,X,)\r\n");
    UART_PutString("add_button(5,6,10,Z,)\r\n");
    UART_PutString("add_button(13,7,28,F,)\r\n");
    UART_PutString("add_button(13,1,30,S,)\r\n");
    UART_PutString("add_button(0,1,27,S,)\r\n");
    UART_PutString("add_button(0,7,29,D,)\r\n");
    UART_PutString("add_monitor(5,2,5,T,1)\r\n");
    UART_PutString("set_panel_notes(,,,)\r\n");
    UART_PutString("run()\r\n");
    //DS_init(0x40);//Inicia sensor de distancia
    
    for(;;)
    {
        if(banderag){
            ADC_StartConvert();
            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
            temp=ADC_GetResult16(); // actualiza Roll Graph
            valor=((50*temp)/255);
            sprintf(buffer2,"%d\n",valor);//lo codifica en ascci
            UART_PutString(buffer2);
            banderag=false;
        }
        //DS_get_data(0x40);
    }
}

/* [] END OF FILE */
