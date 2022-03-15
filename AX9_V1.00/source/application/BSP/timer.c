#include "timer.h"

extern System_MsgStruct SysMsg;

void TimerBase2_5_Config(TIM_TypeDef* TIMx, uint16_t period, uint16_t prescaler)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;   
	
    if(TIMx == TIM2)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  
    if(TIMx == TIM3)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);   
    if(TIMx == TIM4)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);  
    if(TIMx == TIM5)
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);     

    TIM_TimeBaseInitStruct.TIM_Period = period;    				        //设置重装载计数值
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;    	                //设置计数模式：向上计数模式 
    TIM_TimeBaseInitStruct.TIM_Prescaler = prescaler;	  			        //分频系数
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;		 	        //设置时钟分频因子
    
    TIM_TimeBaseInit(TIMx, &TIM_TimeBaseInitStruct);				 	
}

void TimerConfig()
{
    TimerBase2_5_Config(TIM2, 1000-1, 84-1);                                    //1Ms
    TIM_Cmd(TIM2, ENABLE);                                                      //使能定时器
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);                                  //允许定时器更新中断
}

void TIM2_IRQHandler_CallBack()
{
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    if(SysMsg.AdjVol.TimeFlag == TRUE)
    {
        SysMsg.AdjVol.Time++;
    }
    else
    {
        SysMsg.AdjVol.Time = 0;
    }
}
















