#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"

//const int MAXDIRI=4435; 
//const int MINDIRI=3695;

//const int CENDIRI=4065;
//const int CENDIRD=2225;

//const int MAXDIRD=2595;
//const int MINDIRD=1855;

//const int DDIRI=37;
//const int DDIRD=37;


char buffer2[12]={};
int16 temp,count;
unsigned char valor;
unsigned char velo=105;
//volatile unsigned int direcciond=2240;//
//volatile unsigned int direccioni=4080;//CENTRO
volatile bool banderaS=false,banderaG=false,banderaForward=false,banderaPause=false,banderaDoor=false,banderaR=false,banderaL=false,banderaSpeed=false,banderaD=false,banderaBack=false,banderaMax=false,banderaInfra=false;
volatile char dato;
unsigned char cont=0;







void TurnRight(){
    IMPD_Write(1);// 1 ADELANTE 2 ATRAS
    IMAD_Write(1);
    IMPI_Write(2);
    IMAI_Write(2);
    PWM_Motores_A_WriteCompare1(100);
    PWM_Motores_A_WriteCompare2(255);
    PWM_Motores_P_WriteCompare1(100);
    PWM_Motores_P_WriteCompare2(255);
}



void TurnLefth(){
    IMPD_Write(2);// 1 ADELANTE 2 ATRAS
    IMAD_Write(2);
    IMPI_Write(1);
    IMAI_Write(1);
    PWM_Motores_A_WriteCompare1(255);
    PWM_Motores_A_WriteCompare2(100);
    PWM_Motores_P_WriteCompare1(255);
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

CY_ISR(InterruptINFRA){
    if(!banderaInfra){
        PWM_D_A_WriteCompare1(2000);
    }       
    INFRA_ClearInterrupt();
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
            banderaPause=false;
            break;
        }
        case '5':{
            // Atras Fin
            banderaPause=false;
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
            if(banderaDoor){                
                PWM_D_A_WriteCompare1(5500); //Pasa a 180 grados
                banderaInfra=false;
                banderaDoor=false;
            }else{
                PWM_D_A_WriteCompare1(2000); // pasa a 0 grados
                banderaDoor=true;
            }
            
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


int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    IRQRX_StartEx(InterruptRx);
    IRQINFRA_StartEx(InterruptINFRA);
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
    for(;;)
    {
        if(banderaSpeed){
            if((velo<255)&&(!banderaPause)){
                PWM_Motores_A_WriteCompare1(velo);
                PWM_Motores_A_WriteCompare2(velo);
                PWM_Motores_P_WriteCompare1(velo);
                PWM_Motores_P_WriteCompare2(velo);
                velo=velo+10;
            }else{
                banderaSpeed=false;
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
            CyDelay(100);
        }
}


/* [] END OF FILE */
