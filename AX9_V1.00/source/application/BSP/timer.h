#ifndef __TIMER__H
#define __TIMER__H

#include "stm32f4xx.h"

#include "gouble.h"

void TimerBase2_5_Config(TIM_TypeDef* TIMx, uint16_t period, uint16_t prescaler);
void TimerConfig(void);
void TIM2_IRQHandler_CallBack(void);
    
#endif


