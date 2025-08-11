
#include <avr/io.h>
#include "spi_master.h"



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
    // Drive Slave Select low to select the slave
    PORTB &= ~(1 << PB2); 

    // Write dummy data to SPDR to initiate clock and receive data
    SPDR = 0xFF; 

    // Wait for reception complete (SPIF flag set)
    while (!(SPSR & (1 << SPIF)));

    // Return received data
    char received_data = SPDR;

    // Drive Slave Select high to deselect the slave
    PORTB |= (1 << PB2); 

    return received_data;
}
