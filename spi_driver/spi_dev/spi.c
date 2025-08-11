/*
 * spi.c
 *
 * Created: 15-10-2024 15:49:03
 *  Author: kishan.shivhare
 */ 
#include "spi.h"

void SPI_MInit(){
	DDR_SPI |= (1<<MOSI)|(1<<SCK)|(1<<SS)|(1<<RST)|(1<<DC);
	DDR_SPI &= ~(1<<MISO);
	SPCR |=(1<<SPE)|(1<<MSTR)|(1<<SPR0);  
	//SPSR |= (1<<SPI2X); // DISABLE SPEED DOUBLER // OPTIONAL LINE
}

void MASTER_SPI_Write(uint8_t rdata){
	
	char flush_buffer;
	SPDR = rdata;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	flush_buffer = SPDR;		/* Flush received data */
	
	
}


char SPI_SRead(void){
	while(!(SPSR &(1<<SPIF)))
	;
	return SPDR;
}


void SPI_MTransmit(char cData){
	/* Master Transmit character data */
	CS_ENABLE();
	for (int n=0; n<256;n+=1);
	SPDR = cData;
	while(!(SPSR &(1<<SPIF)))
	;
	for (int n=0; n<256;n+=1);
	CS_DISABLE();
}

void SPI_MSInit(void)
{
	/* SPI Initialize function */
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);	/* Make MOSI, SCK, SS as Output pin */
	DDRB &= ~(1<<MISO);			/* Make MISO pin as input pin */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Enable SPI in master mode with Fosc/16 */
	SPSR &= ~(1<<SPI2X);			/* Disable speed doubler */
}

char MASTER_SPI_Read(void)				/* SPI read data function */
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return(SPDR);			/* Return received data */
}

void SPI_SInit()
{
	/* SPI Initialize function */
	DDRB &= ~((1<<MOSI)|(1<<SCK)|(1<<SS));  /* Make MOSI, SCK, SS as input pins */
	DDRB |= (1<<MISO);			/* Make MISO pin as output pin */
	SPCR = (1<<SPE);			/* Enable SPI in slave mode */
}