/* 
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 12 de julio de 2023, 21:39
 */
#include "Display.h"

int d1;
int d2;

int display(int lecADC, int disp){
    if (disp == 1){
        d1 = convdisp((lecADC & 0x0F));
        return d1;
    }
    else if (disp == 2){
        d2 = convdisp((lecADC & 0x0F));
        return d2;
        
    }
}

int convdisp(int valor){
    if (valor == 0){
        return 0b11000000;//0
    }
    else if (valor == 1){
        return 0b11111001;//1
    }
    else if (valor == 2){
        return 0b10100100;//2
    }
    else if (valor == 3){
        return 0b10110000;//3
    }
    else if (valor == 4){
        return 0b10011001;//4
    }
    else if (valor == 5){
        return 0b10010010;//5
    }
    else if (valor == 6){
        return 0b10000010;//6
    }
    else if (valor == 7){
        return 0b11111000;//7
    }
    else if (valor == 8){
        return 0b10000000;//8
    }
    else if (valor == 9){
        return 0b10010000;//9
    }
    else if (valor == 10){
        return 0b10001000;//10
    }
    else if (valor == 11){
        return 0b10000011;//11
    }
    else if (valor == 12){
        return 0b11000110;//12
    }
    else if (valor == 13){
        return 0b10100001;//13
    }
    else if (valor == 14){
        return 0b10000110;//14
    }
    else if (valor == 15){
        return 0b10001110;//15
    }
}
