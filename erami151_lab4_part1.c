/*      Author: Estela Ramirez Ramirez
 *      Partner(s) Name: 
 *      Lab Section:22
 *      Assignment: Lab #4  Exercise #1
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, OFF_RELEASE, ON_PRESS, ON_RELEASE, OFF_PRESS} state;

unsigned char tmpB = 0x01;
unsigned char A0;

void Tick(){
    switch(state){
        case Start:
            tmpB = 0x01;
            state = OFF_RELEASE; break;
        case OFF_RELEASE:
            if (A0){
                tmpB = 0x02;
                state = ON_PRESS; break;
            }else{
                state = OFF_RELEASE; break;
            }
        case ON_PRESS:
            state = A0? ON_PRESS : ON_RELEASE; break;
        case ON_RELEASE:
            if (A0){
                tmpB = 0x01;
                state = OFF_PRESS; break;
            }else{
                state = ON_RELEASE; break;
            }
        case OFF_PRESS:
            state = A0? OFF_PRESS : OFF_RELEASE; break;
        default:
            state = Start;
            break;
   }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
    
    state = Start;
    while (1) {
        A0 = PINA & 0x01;
        Tick();
        PORTB = tmpB;
        
    }
    return 0;
}