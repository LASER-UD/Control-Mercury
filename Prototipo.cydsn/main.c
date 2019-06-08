#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"

char buffer2[12]={};
int16 temp,count;
unsigned char valor;
volatile unsigned int direccion=4272;
volatile bool banderag=false,bandera1=false,banderaS=false;
volatile char dato;


void TurnLefth(){//Giro Izquierda

     if (direccion<4992)//(150°)
    {
        //con una adiccion de 20 cambia 5° y con 40 cambia 10°
        direccion=direccion+180;
        PWM_Dir_WriteCompare(direccion);
    }
}

void TurnRight(){//Giro Derecha
    
     if (direccion>3552)//(90°)
    {   //con una adiccion de 20 cambia 5° y con 40 cambia 10°
        direccion=direccion-180;
        PWM_Dir_WriteCompare(direccion); 
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
            
            break;
        }
        case '1':{
            //Atras Inicio
            
            break;
        }
        case '3':
        {
            //Izquierda 10 °
            TurnLefth();
            sprintf(buffer2,"*T%d*\r\n",direccion);
            UART_PutString(buffer2);
            break;
        }
        case '2':{
            //Deracha  10 °
            TurnRight();
            sprintf(buffer2,"*T%d*\r\n",direccion);
            UART_PutString(buffer2);
            break;
        }
         case '4':{
            //Adelante Fin   
            
            break;
        }
        case '5':{
            // Atras Fin
                        
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
    PWM_WriteCompare1(255);
    PWM_WriteCompare2(255);
    PWM_Dir_Start();
    PWM_Dir_WriteCompare(4272);//en cero
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
