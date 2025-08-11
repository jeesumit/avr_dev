#include <avr/io.h>
#include <stdio.h>
#include "src/uart.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
char buff[128]={'\0'};
int main(){
UART_init(BaudRate(9600));
DDRB |= (1<<PB5);

while(1){
//PORTB |= (1<<PB5);
if(UART_Available()==1){
char val = Read_char();
//sprintf(buff,"%c\n",val);
Write_char(val);
}


  }

}
