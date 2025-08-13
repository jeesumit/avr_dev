#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile unsigned int timer_o = 0;
void init_timer0_ms();
void delay(unsigned int de);

ISR(TIMER0_COMPA_vect){

timer_o++;

}



int main(){

DDRB |= (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2);
init_timer0_ms();

while(1){


PORTB |= (1<<PB5);
delay(250);
PORTB |= (1<<PB4);
delay(250);
PORTB |= (1<<PB3);
delay(250);
PORTB |= (1<<PB2);
delay(250);
PORTB &= ~(1<<PB5);
delay(250);
PORTB &= ~(1<<PB4);
delay(250);
PORTB &= ~(1<<PB3);
delay(250);
PORTB &= ~(1<<PB2);
delay(250);
      }
}

void init_timer0_ms() {
    // Configure Timer0 for CTC mode
    TCCR0A |= (1 << WGM01); // CTC mode

    // Set prescaler to 64
    TCCR0B |= (1 << CS01) | (1 << CS00);

    // Calculate OCR0A for 1ms interrupt
    // (F_CPU / (Prescaler * Target_Frequency)) - 1
    // (16,000,000 / (64 * 1000)) - 1 = 250 - 1 = 249
    OCR0A = 249;

    // Enable Timer0 Compare Match A Interrupt
    TIMSK0 |= (1 << OCIE0A);

    sei(); // Enable global interrupts
}



void delay(unsigned int de){
timer_o = 0;
while(timer_o < de);
}
