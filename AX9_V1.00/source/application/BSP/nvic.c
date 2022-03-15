#include "nvic.h"

void Nvic_Config()
{
    NVIC_InitTypeDef NVIC_InitStrcture;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	

    NVIC_InitStrcture.NVIC_IRQChannel = UART4_IRQn;
    NVIC_InitStrcture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStrcture.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStrcture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStrcture);

    NVIC_InitStrcture.NVIC_IRQChannel = DMA1_Stream6_IRQn;
    NVIC_InitStrcture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStrcture.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStrcture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStrcture);

    NVIC_InitStrcture.NVIC_IRQChannel = DMA1_Stream4_IRQn;
    NVIC_InitStrcture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStrcture.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStrcture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStrcture);

    NVIC_InitStrcture.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStrcture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStrcture.NVIC_IRQChannelSubPriority = 4;
    NVIC_InitStrcture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStrcture);

    NVIC_InitStrcture.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStrcture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStrcture.NVIC_IRQChannelSubPriority = 5;
    NVIC_InitStrcture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStrcture);
}











