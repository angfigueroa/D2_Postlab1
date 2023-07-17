/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */

// CONFIG1
#pragma config FOSC = EXTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#include "oscilador.h"
#include "puertos.h"
#include "ADC.h"
#include "TMR0.h"
#include "display.h"

#define _XTAL_FREQ 4000000 //Variables para el oscilador 
#define vTMR0 10//Variables para el TMR

int cont;
int lecADC;

void __interrupt() isr (void){
    if(INTCONbits.RBIF){
        if(PORTBbits.RB7 == 0){
            cont = 1;
        }
        if(PORTBbits.RB6 == 0){
            cont = 2;
        }
        INTCONbits.RBIF = 0;
    }
    if(PIR1bits.ADIF){
        lecADC = ADRESH;
        ADIF = 0; //apaga la bandera del ADC
    }
    if(INTCONbits.T0IF){
        
        if(PORTEbits.RE0){
            PORTD = display(lecADC,2);
            PORTEbits.RE0 = 0;
            PORTEbits.RE1 = 1;
        }
        else {
            PORTD = display(lecADC,1);
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
        }
        
        TMR0 = vTMR0; //Carga el valor al Timer
        INTCONbits.T0IF = 0;
    }
    
}
//Codigo principal
void main(void){
    //llamamos a las funciones de las librerias
    configpuertos();
    setupINTOSC(6); //Oscilador a 4 MHz
    setup_ADC();
    setupTMR0(64,vTMR0);//Prescaler de 64
    cont=0;
    
    PORTEbits.RE0 = 1;
    PORTEbits.RE1 = 0;
    
    ANSELbits.ANS5 = 0;
    ANSELbits.ANS6 = 0;
    
    while(1){
        //CONTADOR (PRELAB)
        if((cont==1) & PORTBbits.RB7){ //Revisa para ver que se solto el 
            PORTC ++;                  //Boton antirebote
            cont = 0;
        }
        if((cont==2) & PORTBbits.RB6){
            PORTC --;                  
            cont = 0;
        }
        
        //ADC (LAB)
        iniciarADC(1);//Iniciamos la lectura ADC
        
        if(lecADC > PORTC){ //Comparo para la alarma
            PORTBbits.RB0 = 1;
        }
        else{
            PORTBbits.RB0 = 0;
        }
    }
}
    
