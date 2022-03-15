#include "dac.h"

#include "gouble.h"

void Dac_config(uint32_t DAC_Channelx)
{
    DAC_InitTypeDef DAC_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    DAC_InitStruct.DAC_Trigger = DAC_Trigger_Software;
    DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
    DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
    DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Disable;

    DAC_Init(DAC_Channelx, &DAC_InitStruct);
    
    DAC_Cmd(DAC_Channelx, ENABLE);
}



































