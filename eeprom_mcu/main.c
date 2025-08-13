#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdio.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include "src/uart.h"



int main(){
UART_init(BaudRate(9600));
DDRB |= (1<<PB5);
uint8_t read_value;
//uint16_t eeprom_address = 0x08; 


// Example address
/*for (uint16_t i = 0; i < E2END; i++) { // E2END is a macro for the last EEPROM address
        eeprom_write_byte((uint8_t*)i, 0x00); // Write 0xFF to the current address
    }*/
    // Read a byte from EEPROM address 0x00
//eeprom_write_byte((uint8_t*)eeprom_address, 143);

for(uint16_t eeprom_address=0; eeprom_address < E2END; eeprom_address++){

read_value = eeprom_read_byte((const uint8_t *)eeprom_address);
Write_dec(read_value);
Write_char('\n');

}

}
