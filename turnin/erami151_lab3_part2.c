/*	Author: Estela Ramirez Ramirez
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #2
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
    unsigned char tmpA = 0x00; // Temporary variable to hold A's (3-0) bits
    unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    /* Insert your solution below */
    while (1) {

        tmpA = PINA & 0x0F;
       
        if (tmpA == 0x01 || tmpA == 0x02){
            tmpC =  0x20;
        }else if ( tmpA ==  0x03 || tmpA == 0x04){ 
            tmpC = 0x30;    //00110000
        }else if ( tmpA == 0x05 || tmpA == 0x06){
            tmpC = 0x38;    //00111000
        }else if ( tmpA >= 0x07 && tmpA <= 0x09){
            tmpC =  0x3C; //00111100
        }else if (tmpA >= 0x0A && tmpA <= 0x0C){
            tmpC =  0x3E;  // 00111110
        }else if (tmpA >= 0x0D && tmpA <= 0x0F){
            tmpC = 0x3F;  //00111111
        }else{
            tmpC = 0x00;
        }
        if (tmpA <= 4){
            tmpC = tmpC | 0x60;  //01000000
        }  // going here even if tmpA is not less than 4

        
        PORTC = tmpC;
    }
    return 1;
}
