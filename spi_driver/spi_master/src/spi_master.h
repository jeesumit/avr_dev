#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#include <avr/io.h>
#include <stdio.h>

#define CS_ENABLE()     PORTB &= ~(1 << PB2)
#define CS_DISABLE()    PORTB |= (1 << PB2)

#define DC_LOW()        PORTB &= ~(1 << PB1)
#define DC_HIGH()       PORTB |= (1 << PB1)


#define RST_ENABLE()    PORTB &= ~(1 << PB0)
#define RST_DISABLE()   PORTB |= (1 << PB0)

void SPI_MasterInit(void);
char SPI_MasterTransceive(char data);
char SPI_MasterReceive(void);

#endif /* SPI_MASTER_H_ */
