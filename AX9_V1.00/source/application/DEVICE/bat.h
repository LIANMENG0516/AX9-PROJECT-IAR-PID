#ifndef __BAT_H
#define __BAT_H

#include "stm32f4xx.h"

#include "gouble.h"

#define BAT_ADDR        0x16
#define BAT_VOL_CMD     0x09
#define BAT_PWR_CMD     0x0D
#define BAT_TMP_CMD     0x08

void Bat1_PowerRead(void);
void Bat2_PowerRead(void);

void Bat1_TempatureRead(void);
void Bat2_TempatureRead(void);

#endif
