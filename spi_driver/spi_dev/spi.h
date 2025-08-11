/*
 * spi.h
 *
 * Created: 15-10-2024 15:48:44
 *  Author: kishan.shivhare
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define DDR_SPI         DDRB
#define PORT_SPI        PORTB
#define SCK 5
#define MISO 4
#define MOSI 3
#define SS  2
#define DC   1
#define RST  0

// macros

#define CS_ENABLE()     PORT_SPI &= ~(1 << SS)
#define CS_DISABLE()    PORT_SPI |= (1 << SS)
#define DC_LOW()        PORT_SPI &= ~(1 << DC)
#define DC_HIGH()       PORT_SPI |= (1 << DC)
#define RST_ENABLE()    PORT_SPI &= ~(1 << RST)
#define RST_DISABLE()   PORT_SPI |= (1 << RST)
#define LCD_ENABLE()    PORT_SPI |= (1 << RST)
#define TFT_ENABLE()    PORT_SPI |= (1 << RST)

void SPI_MInit(void);
void SPI_MSInit(void);
void MASTER_SPI_Write(uint8_t rdata);
char MASTER_SPI_Read(void);
void SPI_SInit(void);
void SPI_MTansmit(char cData);
char SPI_SRead(void);


#endif /* SPI_H_ */