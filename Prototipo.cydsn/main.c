#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"

const int MAXDIRI=4435; 
const int MINDIRI=3695;

const int CENDIRI=4065;
const int CENDIRD=2225;

const int MAXDIRD=2595;
const int MINDIRD=1855;

const int DDIRI=37;
const int DDIRD=37;


char buffer2[12]={};
int16 temp,count;
unsigned char valor;
unsigned char velo=105;
volatile unsigned int direcciond=2240;//
volatile unsigned int direccioni=4080;//CENTRO
volatile bool banderaS=false,banderaG=false,banderaAC=false,banderaMA=false,banderaA=false, banderaDoor = false,banderaR=false,banderaL=false,banderaAT=false,banderaD=false;
volatile char dato;
unsigned char cont=0; 




void TurnRight(){//Giro Izquierda
    banderaMA=true;
    while (direccioni<MAXDIRI)
    {
        direccioni=direccioni+DDIRI;
        PWM_Dir_WriteCompare2(direccioni);
        direcciond=direcciond+DDIRD;
        PWM_Dir_WriteCompare1(direcciond);
        CyDelay(80);
    }
    INMD_Write(1);
    INMI_Write(1);
    PWM_Motores_WriteCompare2(70);
    PWM_Motores_WriteCompare1(210);
            
}

void TurnLefth(){
    banderaMA=true;
    while(direccioni>MINDIRI)
    {   
        direccioni=direccioni-DDIRI;
        PWM_Dir_WriteCompare2(direccioni); 
        direcciond=direcciond-DDIRD;
        PWM_Dir_WriteCompare1(direcciond);
        CyDelay(80);
    }   
    INMD_Write(1);
    INMI_Write(1);
    PWM_Motores_WriteCompare2(220);
    PWM_Motores_WriteCompare1(80);
}

void Adelante(){
    banderaMA=true;
    if(direcciond!=2240){
        direccioni=4080;
        direcciond=2240;
        PWM_Dir_WriteCompare1(2240);
        PWM_Dir_WriteCompare2(4080);
        CyDelay(100);
    }
    INMD_Write(1);
    INMI_Write(1);
    velo=105;
    PWM_Motores_WriteCompare1(velo);
    PWM_Motores_WriteCompare2(velo);
    banderaAC=true;
}

CY_ISR(InterrupRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case 'g':{
            //Pide datos de sensor
            banderaG=true;        
            break;
        }
        case '0':{
        //Adelante Inicio
            banderaA=true;
            break;
        }
        case '1':{
            //Atras Inicio
            banderaAT=true;            
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
            PWM_Motores_WriteCompare1(0);
            PWM_Motores_WriteCompare2(0);
            INMD_Write(0);
            INMI_Write(0);
            banderaMA=false;
            break;
        }
        case '5':{
            // Atras Fin
            PWM_Motores_WriteCompare1(0);
            PWM_Motores_WriteCompare2(0);
            INMD_Write(0);
            INMI_Write(0);
            banderaMA=false;
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
                PWM_Door_WriteCompare1(5500); //Pasa a 180 grados
                banderaDoor=false;
            }else{
                PWM_Door_WriteCompare1(2000); // pasa a 0 grados
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
    INMD_Write(0);
    INMI_Write(0);
    PWM_Motores_WriteCompare1(0);
    PWM_Motores_WriteCompare2(0);
    PWM_Dir_Start();
    PWM_Dir_WriteCompare1(direcciond);//en cero
    PWM_Dir_WriteCompare2(direccioni);//en cero
    PWM_Door_Start();
    PWM_Door_WriteCompare1(5500); 
    //0 grados = 5500
    //90 grados = 3200
    //180 grados = 2000
    // Ascensor
    PWM_Door_WriteCompare2(0);
    INMA_Write(0);
    //DS_init(0x40);//Inicia sensor de distancia
    for(;;)
    {
        if(banderaAC){
            if((velo<255)&&(banderaMA)){
                velo=velo+10;
                PWM_Motores_WriteCompare1(velo);
                PWM_Motores_WriteCompare2(velo);
            }else{
                banderaAC=false;
            }  
        }
        
        if(banderaA){
            Adelante();
            banderaA=false;
        }
        
        if(banderaL){
            TurnLefth();
            banderaL=false;
        }
        
        if(banderaR){
            TurnRight();
            banderaR=false;
        }
        if(banderaAT){
            if(direcciond!=2240){
                direccioni=4080;
                direcciond=2240;
                PWM_Dir_WriteCompare1(2240);
                PWM_Dir_WriteCompare2(4080);            
                CyDelay(100);
            }
            INMD_Write(2);
            INMI_Write(2);
            PWM_Motores_WriteCompare1(100);
            PWM_Motores_WriteCompare2(100);
            banderaMA=true;
            banderaAT=false;
        }
        if(banderaS){
            INMA_Write(1);
            PWM_Door_WriteCompare2(23500);
            CyDelay(2200);
            PWM_Door_WriteCompare2(0);
            banderaS=false;
        }
        if(banderaD){
            INMAD_Write(1);
            Lanzamiento_Write(1);
            CyDelay(800);
            Lanzamiento_Write(0);
            banderaD=false;
        }
        if(!banderaMA){
                PWM_Motores_WriteCompare1(0);
                PWM_Motores_WriteCompare2(0);
                INMD_Write(0);
                INMI_Write(0);
                velo=105;
        }else{
            cont=cont+1;
            if(cont==30){
                banderaMA=false;
                cont=0;
            }
            CyDelay(100);
        }
    }
}

/* [] END OF FILE */
