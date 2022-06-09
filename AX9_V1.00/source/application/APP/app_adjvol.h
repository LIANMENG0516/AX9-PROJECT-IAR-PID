#ifndef __APP_ADJUSTVOLTAGE_H
#define __APP_ADJUSTVOLTAGE_H

#include "gouble.h"


#define RNAGE_MIN_VOL 10                //调压结果与调压目标的差值小于此值时不进行微调 0.1V
#define SWITCH_ADJVOL_MODULE     1      //1：分步调压, 0：一次性调压
#define MINICWVOL                0

#define HV_CHANGE_UP_TIMEOUT   100
#define HV_CHANGE_DOWN_TIMEOUT 500

#define STEP_DACMCU_UP       29         //MCU_DAC升压步进
#define STEP_DACMCU_DOWN     58         //MCU_DAC降压步进
        
#define STEP_SPIMCU_UP       3          //SPI_DAC升压步进
#define STEP_SPIMCU_DOWN     6          //SPI_DAC降压步进

#define MCU_DAC         1
#define SPI_DAC         2

void App_AdjVol_Task(void);
void App_AdjVol_TaskCreate(void);

void Get_AdjHvMsg(uint8_t *buffer);
void Get_AdjCwMsg(uint8_t *buffer);

void Pid_AdjVolHv(uint8_t *buffer);

#endif
