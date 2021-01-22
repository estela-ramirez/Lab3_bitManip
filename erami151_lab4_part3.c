/*      Author: Estela Ramirez Ramirez
 *      Partner(s) Name: 
 *      Lab Section:22
 *      Assignment: Lab #4  Exercise #3
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, CLOSED, PRESS2, RELEASE2, PRESS1, OPEN} state;

unsigned char tmpB = 0x00;
unsigned char A7;
unsigned char choices;

void Tick(){
    switch(state){
        case Start:
            tmpB = 0x00;
            state = CLOSED; break;
        case CLOSED:
            tmpB = 0x00;
            if (((choices & 0x07) == 0x04) & !A7) {
                state = PRESS2;
            }else{
                state = CLOSED; break;
            }
            break;
        case PRESS2:
            if (((choices & 0x07) == 0x04) & !A7) {
                state = PRESS2;
            }else if (((choices & 0x07) == 0x00) & !A7){
                state = RELEASE2; 
            }else{
                state = CLOSED;
            }
            break;
        case RELEASE2:
            if (((choices & 0x07) == 0x02) & !A7) {
                state = PRESS1;
            }else if (((choices & 0x07) == 0x00) & !A7){
                state = RELEASE2; 
            }else{
                state = CLOSED;
            }
            break;
        case PRESS1:
            state = OPEN;
            break;
        case OPEN:
            tmpB = 0x01;
            if (!A7) {
                state = OPEN;
            }else{
                state = CLOSED;
            }
            break;
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
        choices = PINA & 0x07;
        A7 = PINA & 0x80;
        Tick();
        PORTB = tmpB;
        
    }
    return 0;
}