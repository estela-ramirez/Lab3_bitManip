/*	Author: erami151
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    /* Insert your solution below */
    while (1) {

        tmpA = PINA & 0x0F;
       
        if ( tmpA ==  3 && tmpA == 4){ 
            tmpC = tmpC | 0x30;    //00110000
            
        }else if ( tmpA == 5 && tmpA == 6){
            tmpC = tmpC | 0x38;    //00111000
        }else if ( tmpA >= 7 && tmpA <= 9){
            tmpC = tmpC | 0x3C; //00111100
        }else if (tmpA >= 10 && tmpA <= 12){
            tmpC = tmpC | 0x3E;  // 00111110
        }else if (tmpA >= 13 && tmpA <= 15){
            tmpC = tmpC | 0x3F;  //00111111
        }else{
            tmpC = tmpC;
        }
        if (tmpA < 4){
            tmpC = tmpC | 0x40;
        }  // going here even if tmpA is not less than 4
        PORTC = tmpC;
    }
    return 1;
}
