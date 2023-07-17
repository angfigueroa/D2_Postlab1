/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */
#include "TMR0.h"
#define _XTAL_FREQ 4000000

void setupTMR0(uint8_t PRES, uint8_t valTMR0){
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0;
    
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 0;
    if(PRES == 2){
        OPTION_REGbits.PS = 0b000;
    }
    else if(PRES == 4){
        OPTION_REGbits.PS = 0b001;
    }
    else if(PRES == 8){
        OPTION_REGbits.PS = 0b010;
    }
    else if(PRES == 16){
        OPTION_REGbits.PS = 0b011;
    }
    else if(PRES == 32){
        OPTION_REGbits.PS = 0b100;
    }
    else if(PRES == 64){
        OPTION_REGbits.PS = 0b101;
    }
    else if(PRES == 128){
        OPTION_REGbits.PS = 0b110;
    }
    else if(PRES == 256){
        OPTION_REGbits.PS = 0b111;    
    }
    TMR0 = valTMR0;    
}

