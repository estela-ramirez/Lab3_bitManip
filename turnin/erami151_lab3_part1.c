/*	Author: Estela Ramirez Ramirez
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Outputs how many numbers of 1 on ports A and B.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char y);


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s

    unsigned char count = 0x00; // Temporary variable to hold output
	unsigned char tmpA = 0x00;  // Temporary variable to hold A's value
	unsigned char tmpB = 0x00;  // Temporary variable to hold B's value
	unsigned char i;
	
    	while (1) {
		//1) read inputs
		tmpA = PINA;
		tmpB = PINB;

		//2) compute 
		for (i = 0; i < 8; i++) {

			if (GetBit(tmpA, i)) {   // if A's ith bit == 1
				count = count + 1;
			}

			if (GetBit(tmpB, i)) {   // if B's ith bit == 1
				count = count + 1;
			}
		}
		//3) set output
		PORTC = count;
    	}
    	return 0;
}

unsigned char GetBit(unsigned char x, unsigned char y) {
	return ((x & (0x01 << k)) != 0);
}