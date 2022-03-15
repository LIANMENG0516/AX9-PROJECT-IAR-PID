#ifndef __POWER_H
#define __POWER_H

#include "stm32f4xx.h"

#include "gouble.h"

#define BAT_STATE_CHARGE    1   //正在充电
#define BAT_STATE_FULL      2   //充电完成
#define BAT_STATE_ERROR     3   //电池故障、过压、挂起、睡眠等

void Battery_Power_Read(void);

#endif
