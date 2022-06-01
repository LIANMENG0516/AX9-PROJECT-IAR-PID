#include "board.h"

#include "gouble.h"

extern System_MsgStruct SysMsg;

extern Com_Buffer DebugComRX;
extern Com_Buffer DebugComTX;

extern Com_Buffer CommuComRX;
extern Com_Buffer CommuComTX;

extern uint8_t	RcvData[100];
extern uint8_t	SenData[100];

void Debug_Com_Config()
{
    Usart_Init(DEBUG_COM, 115200);	

    USART_ITConfig(DEBUG_COM, USART_IT_RXNE, DISABLE);								//关闭RXNE中断 
    USART_ITConfig(DEBUG_COM, USART_IT_TXE, DISABLE);								//关闭TXE中断
    USART_ITConfig(DEBUG_COM, USART_IT_IDLE, ENABLE);								//开启IDLE中断

    USART_DMACmd(DEBUG_COM, USART_DMAReq_Rx, ENABLE);								//开启USART_DMA接收通道
    USART_DMACmd(DEBUG_COM, USART_DMAReq_Tx, ENABLE);								//开启USART_DMA发送通道

    Dma_Config(DEBUG_COM_DMAY_STREAMX_RX, DEBUG_COM_DMA_CHANNEL_RX, (uint32_t)&DEBUG_COM->DR, (uint32_t)&DebugComRX.Data[0], DMA_DIR_PeripheralToMemory, sizeof(RcvData), DMA_PeripheralDataSize_Byte, DMA_MemoryDataSize_Byte, DMA_Mode_Circular, DMA_Priority_VeryHigh);      //配置DEBUG_COM_RX_DMA通道                                                                     
    Dma_Config(DEBUG_COM_DMAY_STREAMX_TX, DEBUG_COM_DMA_CHANNEL_TX, (uint32_t)&DEBUG_COM->DR, (uint32_t)&DebugComTX.Data[0], DMA_DIR_MemoryToPeripheral, sizeof(SenData), DMA_PeripheralDataSize_Byte, DMA_MemoryDataSize_Byte, DMA_Mode_Circular, DMA_Priority_VeryHigh);      //配置DEBUG_COM_TX_DMA通道  

    DMA_Cmd(DEBUG_COM_DMAY_STREAMX_RX, ENABLE);                                                                 //使能DMA接收
    DMA_Cmd(DEBUG_COM_DMAY_STREAMX_TX, DISABLE);                                                                //关闭DMA发送


    DMA_ITConfig(DEBUG_COM_DMAY_STREAMX_TX, DMA_IT_TC, ENABLE);						        //开启DMA发送中断	
}

void Commu_Com_Config()
{
    Usart_Init(COMMU_COM, 115200);	

    USART_ITConfig(COMMU_COM, USART_IT_RXNE, DISABLE);								//关闭RXNE中断 
    USART_ITConfig(COMMU_COM, USART_IT_TXE, DISABLE);								//关闭TXE中断
    USART_ITConfig(COMMU_COM, USART_IT_IDLE, ENABLE);								//开启IDLE中断

    USART_DMACmd(COMMU_COM, USART_DMAReq_Rx, ENABLE);								//开启USART_DMA接收通道
    USART_DMACmd(COMMU_COM, USART_DMAReq_Tx, ENABLE);								//开启USART_DMA发送通道

    Dma_Config(COMMU_COM_DMAY_STREAMX_RX, COMMU_COM_DMA_CHANNEL_RX, (uint32_t)&COMMU_COM->DR, (uint32_t)&CommuComRX.Data[0], DMA_DIR_PeripheralToMemory, sizeof(RcvData), DMA_PeripheralDataSize_Byte, DMA_MemoryDataSize_Byte, DMA_Mode_Circular, DMA_Priority_VeryHigh);      //配置DEBUG_COM_RX_DMA通道                                                                     
    Dma_Config(COMMU_COM_DMAY_STREAMX_TX, COMMU_COM_DMA_CHANNEL_TX, (uint32_t)&COMMU_COM->DR, (uint32_t)&CommuComTX.Data[0], DMA_DIR_MemoryToPeripheral, sizeof(SenData), DMA_PeripheralDataSize_Byte, DMA_MemoryDataSize_Byte, DMA_Mode_Circular, DMA_Priority_VeryHigh);      //配置DEBUG_COM_TX_DMA通道  

    DMA_Cmd(COMMU_COM_DMAY_STREAMX_RX, ENABLE);                                                                 //使能DMA接收
    DMA_Cmd(COMMU_COM_DMAY_STREAMX_TX, DISABLE);                                                                //关闭DMA发送

    DMA_ITConfig(COMMU_COM_DMAY_STREAMX_TX, DMA_IT_TC, ENABLE);						        //开启DMA发送中断	
}



void Adc3_Config()
{
    Adc_Init(ADC3, ADC3_CHANNEL_NUM);

    ADC_RegularChannelConfig(ADC3, CHANNEL_VPP1,    SAMPLE_VPP1_SEQUENCE,    ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_VNN1,    SAMPLE_VNN1_SEQUENCE,    ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_VPP2,    SAMPLE_VPP2_SEQUENCE,    ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_VNN2,    SAMPLE_VNN2_SEQUENCE,    ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_A3V75,   SAMPLE_A3V75_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_A2V25,   SAMPLE_A2V25_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_AP12V,   SAMPLE_AP12V_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_AN12V,   SAMPLE_AN12V_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_AP5V5_1, SAMPLE_AP5V5_1_SEQUENCE, ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_AP5V5_2, SAMPLE_AP5V5_2_SEQUENCE, ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_AN5V5,   SAMPLE_AN5V5_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_D5V,     SAMPLE_D5V_SEQUENCE,     ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_D0V95,   SAMPLE_D0V95_SEQUENCE,   ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC3, CHANNEL_D1V45,   SAMPLE_D1V45_SEQUENCE,   ADC_SampleTime_480Cycles);
}

void Adc1_Config()
{
    Adc_Init(ADC1, ADC1_CHANNEL_NUM);
    
    ADC_TempSensorVrefintCmd(ENABLE);
    ADC_RegularChannelConfig(ADC1, CHANNEL_IADP, SAMPLE_IADP_SEQUENCE,  ADC_SampleTime_480Cycles);
    ADC_RegularChannelConfig(ADC1, CHANNEL_TEMP, SAMPLE_TEMP_SEQUENCE,  ADC_SampleTime_480Cycles);
}



extern uint16_t  Adc_3_ConValue[ADC_SAMPLE_NUM][ADC3_CHANNEL_NUM];

extern uint16_t  Adc_1_ConValue[ADC_SAMPLE_NUM][ADC1_CHANNEL_NUM];

void V_AdcDma_Config()
{
    Adc3_Config();                                                         
    Dma_Config(ADC_DMAY_STREAMX_V, ADC_DMA_CHANNEL_V, (uint32_t)&ADC3->DR, (uint32_t)Adc_3_ConValue, DMA_DIR_PeripheralToMemory, ADC_SAMPLE_NUM * ADC3_CHANNEL_NUM, DMA_PeripheralDataSize_HalfWord, DMA_MemoryDataSize_HalfWord, DMA_Mode_Circular, DMA_Priority_VeryHigh);                                                                                                                                                                                                                  
    DMA_Cmd(ADC_DMAY_STREAMX_V, ENABLE); 
    ADC_DMARequestAfterLastTransferCmd(ADC3, ENABLE);                         //如果不开启，只进入一次DMA中断
    ADC_DMACmd(ADC3, ENABLE);
    ADC_SoftwareStartConv(ADC3);	
}

void I_AdcDma_Config()
{
    Adc1_Config();
    Dma_Config(ADC_DMAY_STREAMX_I, ADC_DMA_CHANNEL_I, (uint32_t)&ADC1->DR, (uint32_t)Adc_1_ConValue, DMA_DIR_PeripheralToMemory, ADC_SAMPLE_NUM * ADC1_CHANNEL_NUM, DMA_PeripheralDataSize_HalfWord, DMA_MemoryDataSize_HalfWord, DMA_Mode_Circular, DMA_Priority_VeryHigh);                                                                                                                                                                                                                  
    DMA_Cmd(ADC_DMAY_STREAMX_I, ENABLE); 
    ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);                         //如果不开启，只进入一次DMA中断
    ADC_DMACmd(ADC1, ENABLE);
    ADC_SoftwareStartConv(ADC1);	
}

void Fan_Config()
{
    Fan_Emc2305_Init();
}

//extern USB_OTG_CORE_HANDLE USB_OTG_dev;
void Board_Bsp_Init()
{
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x20000);

    Nvic_Config();
    SysTick_Iint();
    Gpio_Config();
    
    //USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_CDC_cb, &USR_cb);
    //USB_CTRL_EN(1);

    #if USE_DEBUG
    Debug_Com_Config();                     //调试串口初始化
    #else
    Commu_Com_Config();                     //通讯串口初始化--与EC通讯
    #endif

    Spi_Dac_Config();
    Adjust_Hv_Reset();
    Adjust_Cw_Reset();
    
    V_AdcDma_Config();                      //电压采样通道初始化--共14路电压采样, 全部使用ADC3
    I_AdcDma_Config();                      //电流采样、片内温度采样通道初始化--共2路电流采样, 使用采样电阻将电流转化为电压进行采样, 使用ADC1

    Dac_config(DAC_Channel_1);
    Dac_config(DAC_Channel_2);
    
    Fan_Config();
    
    TimerConfig();
    
    Adjust_Voltage_Init();
}



