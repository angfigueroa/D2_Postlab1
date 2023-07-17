/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */

#include "puertos.h"

void configpuertos(void){
    //Configuramos el puerto B (Interrupciones)
    TRISB = 0b11000000;
    PORTB = 0b11000000;
    INTCONbits.GIE = 1;//se habilitan interrupciones globales
    INTCONbits.RBIE = 1;//Habilitamos la interrupcion en el puerto B
    INTCONbits.RBIF = 0;// Apagamos la bandera de interrupcion del puerto B
    IOCB = 0b11000000;//Habilita la interrupcion del puerto B
    WPUB = 0b11000000;//WEAK PULL UP en el puerto B
    OPTION_REGbits.nRBPU = 0;//Se desabilita el bit
    
    
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
     
}
