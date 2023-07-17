/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */

#include "oscilador.h"

void setupINTOSC(uint8_t IRCF){
    if(IRCF == 7){
        OSCCONbits.IRCF = 0b111;//Oscilador de 8 MHz
    }
    if(IRCF == 6){
        OSCCONbits.IRCF = 0b110;//Oscilador de 4 MHz
    }  
    if(IRCF == 5){
        OSCCONbits.IRCF = 0b101;//Oscilador de 2 MHz
    }
    if(IRCF == 4){
        OSCCONbits.IRCF = 0b100;//Oscilador de 1 MHz
    }
    if(IRCF == 3){
        OSCCONbits.IRCF = 0b011;//Oscilador de 500 KHz
    }
    if(IRCF == 2){
        OSCCONbits.IRCF = 0b010;//Oscilador de 250 KHz
    }
    if(IRCF == 1){
        OSCCONbits.IRCF = 0b001;//Oscilador de 125 KHz
    }
    if(IRCF == 0){
        OSCCONbits.IRCF = 0b000; //Oscilador de 31 KHz
    }
    
    OSCCONbits.SCS = 1; //Oscilador interni
}
