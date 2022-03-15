#ifndef __SYSTICK_H_
#define __SYSTICK_H_

#include "stm32f4xx.h"

void SysTick_Iint(void);

void Delay_ms(__IO uint32_t nTime);

void TimingDelay_Decrement(void);

void Set_DelayMs(__IO uint32_t nTime);

uint32_t Get_DelayMs(void);

void delay_us(uint16_t time);

void delay_ms(uint16_t time);

void delay_us_os(uint16_t time);

void delay_os_lock(void);

void delay_os_unlock(void);

#endif

