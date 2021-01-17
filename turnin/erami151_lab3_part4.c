/*	Author: Estela Ramirez Ramirez
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: Outputs how many numbers of 1 on ports A and B.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, intialize to 0s
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s

	unsigned char tmpB = 0x00;  // Temporary variable to hold B's value
	unsigned char tmpC = 0x00;  // Temporary variable to hold C's value

    	while (1) {
	
		//1) read inputs
		tmpB = PINA & 0xF0;
		tmpC = PINA & 0x0F;

		tmpB = tmpB >> 4;
        tmpC = tmpC << 4;
		//2) set output

		PORTB = (tmpB & 0xF0) | tmpB;
        PORTC = (tmpC & 0x0F) | tmpC ;

    	}
    	return 0;
}
