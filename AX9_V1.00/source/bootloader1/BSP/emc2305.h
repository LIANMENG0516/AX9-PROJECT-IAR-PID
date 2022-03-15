#ifndef __EMC2305_H
#define __EMC2305_H

#include "stm32f4xx.h"

#define EMC2305_10K_ADDR    0x2c

#define BASIC_CTL           0x20
#define PWM_POLARITY        0x2a
#define PWM_OUTPUT          0x2b
#define PWM45_BASE          0x2c
#define PWM123_BASE         0x2d

#define FAN1_SETTING        0x30
#define FAN2_SETTING        0x40
#define FAN3_SETTING        0x50
#define FAN4_SETTING        0x60
#define FAN5_SETTING        0x70

#define FAN1_TACHREAD_HIGH  0x3e 
#define FAN1_TACHREAD_LOW   0x3f 
#define FAN2_TACHREAD_HIGH  0x4e 
#define FAN2_TACHREAD_LOW   0x4f 
#define FAN3_TACHREAD_HIGH  0x5e 
#define FAN3_TACHREAD_LOW   0x5f 
#define FAN4_TACHREAD_HIGH  0x6e 
#define FAN4_TACHREAD_LOW   0x6f 
#define FAN5_TACHREAD_HIGH  0x7e 
#define FAN5_TACHREAD_LOW   0x7f 

#define SPEED_NoMin         0x1c    
#define SPEED_NoMax         0xff    
#define SPEED_ERROR         960     //风扇转速低于960识别为硬件故障即无风扇或风扇损坏

#define TEMPERATURE_95      95
#define TEMPERATURE_50      50

#define FAN_OK  0
#define FAN_ERR 1

void Fan_Emc2305_Init(void);
void Fan_Emc2305_Control(void);
void Fan_Speed_Read(void);
void Write_Emc2305_Reg(uint8_t id, uint16_t addr, uint16_t val);
void Read_Emc2305_Reg(uint8_t id, uint8_t addr, uint8_t *buffer, uint8_t len);

#endif
