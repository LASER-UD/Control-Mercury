#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char buffer[12]={};
int16 temp;
unsigned char valor;
volatile unsigned char cont;
volatile bool bandera=false;
volatile char dato;

CY_ISR(InterrupRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case 'g':
        {
            bandera=true;
            LED_Write(~LED_Read());           
            break;
        }
        case 'x':{
            break;
        }
        
        case 'y':
        {   
            break;
        }
        case 'z':{
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
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start(); 
    IRQRX_StartEx(InterrupRx);
    PWM_Start();
    ADC_Start();
    PWM_WriteCompare1(255);
    PWM_WriteCompare2(255); 
    UART_PutString("Inicio");
    for(;;)
    {
        if(bandera){
            ADC_StartConvert();
            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
            temp=ADC_GetResult16(); // actualiza Roll Graph
            valor=((50*temp)/255);
            sprintf(buffer,"%d\n",valor);//lo codifica en ascci
            UART_PutString(buffer);
            bandera=false;
        }
    }
}

/* [] END OF FILE */
