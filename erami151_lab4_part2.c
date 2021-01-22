/*      Author: Estela Ramirez Ramirez
 *      Partner(s) Name: 
 *      Lab Section:22
 *      Assignment: Lab #4  Exercise #2
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, WAIT, INCREMENT, DECREMENT, INCREMENT_WAIT, DECREMENT_WAIT, UNPRESS, RESET} state;

unsigned char tmpC = 0x07;
unsigned char buttons;

void Tick(){
    switch(state){
        case Start:
            state = WAIT; break;
        case WAIT:
            if ((buttons & 0x03) == 0x01){
                state = INCREMENT;
            }else if ((buttons & 0x03) == 0x02){
                state = DECREMENT;
            }else if ((buttons & 0x03) == 0x03){
                state = RESET;
            }else{
                state = WAIT;  // == 0x00
            }
            break;
        case INCREMENT:
            state = INCREMENT_WAIT; break;
        case DECREMENT:
            state = DECREMENT_WAIT; break;
        case INCREMENT_WAIT:
            if ((buttons & 0x03) == 0x01){
                state = INCREMENT_WAIT;
            }else if ((buttons & 0x03) == 0x02){
                state = DECREMENT;
            }else if ((buttons & 0x03) == 0x03){
                state = RESET;
            }else{
                state = UNPRESS;  // == 0x00
            }
            break;
         case DECREMENT_WAIT:
            if ((buttons & 0x03) == 0x01){
                state = INCREMENT;
            }else if ((buttons & 0x03) == 0x02){
                state = DECREMENT_WAIT;
            }else if ((buttons & 0x03) == 0x03){
                state = RESET;
            }else{
                state = UNPRESS;   // == 0x00
            }
            break;
        case RESET:
            if ((buttons & 0x03) == 0x01){
                state = INCREMENT;
            }else if ((buttons & 0x03) == 0x02){
                state = DECREMENT;
            }else if ((buttons & 0x03) == 0x00){
                state = UNPRESS;
            }else{
                state = WAIT;   // == 0x03
            }
            break;
        case UNPRESS:
            if ((buttons & 0x03) == 0x01){
                state = INCREMENT;
            }else if ((buttons & 0x03) == 0x02){
                state = DECREMENT;
            }else if ((buttons & 0x03) == 0x03){
                state = RESET;
            }else{
                state = UNPRESS;   // == 0x00
            }
            break;
        default:
            state = Start;
            break;
   }
   

   switch(state){
        case Start:
            tmpC = 0x07;
            break;
        case INCREMENT:
            if (tmpC < 9){
                tmpC += 1;
            }
            break;
        case DECREMENT:
            if (tmpC > 0){
                tmpC -= 1;
            }
            break;
        case RESET:
            tmpC = 0x00;
            break;
        default:
            break;
   }
   
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs

    state = Start;
    /* Insert your solution below */
    while (1) {
      buttons = PINA & 0x03;
      Tick();
      PORTC = tmpC;
    }
    return 1;
}