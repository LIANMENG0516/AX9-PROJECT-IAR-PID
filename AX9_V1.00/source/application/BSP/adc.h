#ifndef __ADC_H_
#define __ADC_H_

#include "stm32f4xx.h"

#define ADC3_CHANNEL_NUM    14
#define ADC1_CHANNEL_NUM    2
#define ADC_SAMPLE_NUM      20

#define ADC_DMAY_STREAMX_V DMA2_Stream1
#define ADC_DMA_CHANNEL_V  DMA_Channel_2

#define ADC_DMAY_STREAMX_I DMA2_Stream0
#define ADC_DMA_CHANNEL_I  DMA_Channel_0

//ADC3
#define CHANNEL_VPP1 	    ADC_Channel_10		
#define CHANNEL_VNN1 	    ADC_Channel_11
#define CHANNEL_VPP2 	    ADC_Channel_12		
#define CHANNEL_VNN2 	    ADC_Channel_13
#define CHANNEL_A2V25 	    ADC_Channel_9		
#define CHANNEL_A3V75 	    ADC_Channel_14
#define CHANNEL_AP5V5_1 	ADC_Channel_15	
#define CHANNEL_AP12V	    ADC_Channel_4		
#define CHANNEL_AN5V5	    ADC_Channel_5		
#define CHANNEL_AN12V	    ADC_Channel_6
#define CHANNEL_D0V95 	    ADC_Channel_7
#define CHANNEL_D1V45 	    ADC_Channel_8
#define CHANNEL_AP5V5_2 	ADC_Channel_2
#define CHANNEL_D5V 	    ADC_Channel_3

#define SAMPLE_VPP1_SEQUENCE        1
#define SAMPLE_VNN1_SEQUENCE        2
#define SAMPLE_VPP2_SEQUENCE        3
#define SAMPLE_VNN2_SEQUENCE        4
#define SAMPLE_A3V75_SEQUENCE       5
#define SAMPLE_A2V25_SEQUENCE       6
#define SAMPLE_AP12V_SEQUENCE       7
#define SAMPLE_AN12V_SEQUENCE       8
#define SAMPLE_AP5V5_1_SEQUENCE     9
#define SAMPLE_AP5V5_2_SEQUENCE     10
#define SAMPLE_AN5V5_SEQUENCE       11
#define SAMPLE_D5V_SEQUENCE         12
#define SAMPLE_D0V95_SEQUENCE       13
#define SAMPLE_D1V45_SEQUENCE       14

//ADC1
#define CHANNEL_IADP 	    ADC_Channel_15      //¹ýÁ÷¼ì²â
#define CHANNEL_TEMP 	    ADC_Channel_16      //ÎÂ¶È¼ì²â 

#define SAMPLE_IADP_SEQUENCE        1
#define SAMPLE_TEMP_SEQUENCE        2

void Adc_Init(ADC_TypeDef* ADCx, uint8_t NumChannel);
void Adc3_GetAdjVoltage(void);
void Adc3_GetFixVoltage(void);
void Adc1_GetMcuInternalTemperature(void);
void Adc1_GetOverCurrentVoltage(void);

#endif

