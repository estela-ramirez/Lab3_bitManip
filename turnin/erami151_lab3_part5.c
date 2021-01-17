/*	Author: Estela Ramirez Ramirez
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: car's passenger-seat weight sensor outputs a 9-bit value and connects to input PD7..PD0PB0. 
 *  If the weight is >= 70 pounds, the airbag should be enabled (PB1 = 1). 
 *  If weight > 5 && < 70, the airbag should be disabled and an "Airbag disabled" icon enabled ( PB2 = 1).
 *  (Neither B1 nor B2 should be set if the weight is 5 or less, as there is no passenger). 

 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRD = 0x00; PORTD = 0xFF; // Configure port D's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
    unsigned char tmpD = 0x00;
	unsigned char tmpB = 0x00;
	
    	while (1) {
		
		tmpD = PIND;   
		tmpB = 0x00;  

        if (PINB == 0x00) {
            if (PIND >= 0x46) {                              
				tmpB = 0x02;
			}else{
                // shift PIND to left 1 time & place PB0 as least sig. bit
				tmpD = (tmpD << 1) | 0x00;  
                if (tmpD >= 0x46) {                           // if tmpD > 70
					tmpB = 0x02;            
			    }else if (tmpD > 0x05 && tmpD < 0x46) {       // if 5 < tmpD < 70
					tmpB = 0x04;
				}else { 
					tmpB = 0x00;
				}	
            }

        }else{
            if (PIND >= 0x46) {                                // if weight >= 70, B1 = 1
				tmpB = 0x02;
			}else {
                // shift PIND to left 1 time & place PB0 as least sig. bit
				tmpD = (tmpD << 1) | 0x01; 
				if (tmpD >= 0x46) {                             // if tmpD > 70
					tmpB = 0x02;
				}else if (tmpD > 0x05 && tmpD < 0x46) {         // if 5 < tmpD < 70
					tmpB = 0x04;
				}else {
					tmpB = 0x00;
				}
			}
        }
        
		PORTB = tmpB;
    	}
    	return 0;
}
