#include <avr/io.h>
#include <stdio.h>
#include "src/uart.h"
#include "src/spi_master.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
/*
void SPI_MasterInit(void);
char SPI_MasterTransceive(char data);
char SPI_MasterReceive(void);

#define CS_ENABLE()     PORTB &= ~(1 << PB2)
#define CS_DISABLE()    PORTB |= (1 << PB2)

#define DC_LOW()        PORTB &= ~(1 << PB1)
#define DC_HIGH()       PORTB |= (1 << PB1)


#define RST_ENABLE()    PORTB &= ~(1 << PB0)
#define RST_DISABLE()   PORTB |= (1 << PB0)
*/

int main(){
UART_init(BaudRate(9600));
SPI_MasterInit();


while(1){

//SPI_MasterTransceive('A');
char bval = SPI_MasterReceive();
Write_char(bval);
  }

}


/*
void SPI_MasterInit(void) {
    DDRB |= (1 << DDB5) | (1 << DDB3) | (1 << DDB2); // SCK, MOSI, SS as output
    DDRB &= ~(1 << DDB4); // MISO as input
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master mode, fosc/16
}



char SPI_MasterTransceive(char data) {
    SPDR = data; // Start transmission
    while (!(SPSR & (1 << SPIF))); // Wait for transfer complete
    return SPDR; // Return received data
}


// SPI Master Receive Function
char SPI_MasterReceive(void) {
    // Drive Slave Select low to select the slave PORTB &= ~(1 << PB2); 
    CS_ENABLE();
    // Write dummy data to SPDR to initiate clock and receive data
    SPDR = 0xFF; 

    // Wait for reception complete (SPIF flag set)
    while (!(SPSR & (1 << SPIF)));

    // Return received data
    char received_data = SPDR;

    // Drive Slave Select high to deselect the slave PORTB |= (1 << PB2);
    CS_DISABLE(); 

    return received_data;
}
*/
