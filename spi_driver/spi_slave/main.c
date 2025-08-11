#include <avr/io.h>
#include <stdio.h>
#include "src/uart.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);
//char buff;
void spi_slave_transmit(char data);
int main(){
UART_init(BaudRate(9600));
SPI_SlaveInit();
DDRB |= (1<<PB5);

while(1){

//char buff = SPI_SlaveReceive();
//Write_char(buff);
spi_slave_transmit('A');
}

}


void SPI_SlaveInit(void) {
    DDRB &= ~((1 << DDB5) | (1 << DDB3) | (1 << DDB2)); // SCK, MOSI, SS as input
    DDRB |= (1 << DDB4); // MISO as output
    SPCR = (1 << SPE); // Enable SPI, Slave mode
}


// Slave Receive Example
char SPI_SlaveReceive(void) {
    while (!(SPSR & (1 << SPIF))); // Wait for transfer complete
    return SPDR; // Return received data
}

void spi_slave_transmit(char data) {
    SPDR = data; // Load data to be sent
}
