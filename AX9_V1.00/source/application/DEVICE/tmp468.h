#ifndef __TMP468_H
#define __TMP468_H

#include "stm32f4xx.h"

#define TMP468_ADDR 0x48

#define LT_ADDR     0x00
#define RT1_ADDR    0x01
#define RT2_ADDR    0x02
#define RT3_ADDR    0x03
#define RT4_ADDR    0x04
#define RT5_ADDR    0x05
#define RT6_ADDR    0x06
#define RT7_ADDR    0x07
#define RT8_ADDR    0x08


uint8_t Tmp468_WriteByte(uint8_t id, uint16_t addr, uint16_t val);
uint8_t Tmp468_ReadByte(uint8_t id, uint8_t addr, uint8_t *buffer);
uint8_t Tmp468_ReadData(uint8_t id, uint8_t addr, uint8_t *buffer, uint8_t len);

void Obtain_TemperatureFPGA(void);


#endif
