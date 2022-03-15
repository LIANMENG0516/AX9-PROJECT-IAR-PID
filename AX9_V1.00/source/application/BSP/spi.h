#ifndef __SPI_H
#define __SPI_H

#include "stm32f4xx.h"

void Spi_config(SPI_TypeDef* SPIx, uint16_t DataSize, uint16_t cpol, uint16_t cpha);

uint8_t SPI_ReadWriteByte(SPI_TypeDef* SPIx, uint8_t data);

uint8_t SPI_WriteHalfWord(SPI_TypeDef* SPIx, uint16_t data);

uint8_t SPI_ReadWriteHalfWord(SPI_TypeDef* SPIx, uint16_t data);

#endif
