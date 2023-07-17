/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */
#include "ADC.h"
#define _XTAL_FREQ 4000000 //Variables para el oscilador 

void setup_ADC(void){
    PORTAbits.RA0 = 0;
    TRISAbits.TRISA0 = 1; //RA0 es entrada
    ANSELbits.ANS0 = 1;//RA0 es analogico
    
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;//Habilitar interrupcion del ADC 
    PIR1bits.ADIF = 0;
    
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 = 1;//Fosc/8
    
    ADCON1bits.VCFG1 = 0;//Referencia VSS
    ADCON1bits.VCFG0 = 0;//Referencia VDD
    
    ADCON1bits.ADFM = 0;//se justifica en la izquierda
    
    ADCON0bits.ADON = 1;//Hablitar el convertidor ADC
    __delay_us(100);
}

void iniciarADC(int channel){
    if(channel ==1){
        ADCON0bits.CHS = 0b0000;//El canal analogico es 0
        __delay_us(100);
        ADCON0bits.GO = 1;//Se inicia la conversion ADC
        
    }
}
