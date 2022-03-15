#ifndef __DS2431_H_
#define __DS2431_H_

#include "stm32f4xx.h"

uint8_t DS2431_WriteData(uint8_t addr, uint8_t *buffer);

uint8_t DS2431_ReadData(uint8_t addr, uint8_t *buffer);

void Write_UsPowerId(uint8_t *buffer);

#endif

