#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char buffer[12]={};
int16 temp,count;
unsigned char valor;
volatile uint16 direccion;
volatile bool banderag=false,bandera1=false,banderaS=false;
volatile char dato;


void Sprint(){


    
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
    UART_Start(); 
    IRQRX_StartEx(InterrupRx);
    PWM_Start();
    PWM2_Start();
    ADC_Start();
    /*Inicia los Modulos */
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
    
    
    
    UART_PutString("Inicio");
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
    }
}

/* [] END OF FILE */
