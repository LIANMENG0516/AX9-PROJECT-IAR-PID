#include "dma.h"

#include "gouble.h"

void Dma_Config(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_Channelx, uint32_t peripher_address, uint32_t ram_address, uint32_t dma_dir, uint16_t rebuf_seize, uint32_t pdatalen, uint32_t mdatalen, uint32_t dma_mode, uint32_t dma_priority)                                                                     
{
    DMA_InitTypeDef DMA_InitStructure;	

    if((uint32_t)DMAy_Streamx < (uint32_t)DMA2)
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
    else
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);	

    DMA_InitStructure.DMA_Channel = DMA_Channelx;    				
    DMA_InitStructure.DMA_PeripheralBaseAddr = peripher_address;
    DMA_InitStructure.DMA_Memory0BaseAddr = ram_address;  														
    DMA_InitStructure.DMA_DIR = dma_dir;									
    DMA_InitStructure.DMA_BufferSize = rebuf_seize;			
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;								
    DMA_InitStructure.DMA_PeripheralDataSize = pdatalen;
    DMA_InitStructure.DMA_MemoryDataSize = mdatalen;									
    DMA_InitStructure.DMA_Mode = dma_mode;							
    DMA_InitStructure.DMA_Priority = dma_priority;									
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;	
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;	
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;	
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;	
    
    DMA_Init(DMAy_Streamx, &DMA_InitStructure);
    
    DMA_Cmd(DMAy_Streamx, DISABLE);
}


extern Com_Buffer DebugComTX;
extern Com_Buffer CommuComTX;
extern uint8_t	RcvData[100];
extern uint8_t	SenData[100];

void Dmay_Streamx_IRQHandler_CallBack()
{
    #if USE_DEBUG
    if(DMA_GetITStatus(DEBUG_COM_DMAY_STREAMX_TX, DEBUG_COM_DMA_IT_TC_TX) != RESET)
    {
        DMA_Cmd(DEBUG_COM_DMAY_STREAMX_TX, DISABLE); 
        DMA_SetCurrDataCounter(DEBUG_COM_DMAY_STREAMX_TX, sizeof(SenData));
        DMA_ClearITPendingBit(DEBUG_COM_DMAY_STREAMX_TX, DEBUG_COM_DMA_IT_TC_TX);					//清除DMA发送完成中断标志位
    }
    #else
    if(DMA_GetITStatus(COMMU_COM_DMAY_STREAMX_TX, COMMU_COM_DMA_IT_TC_TX) != RESET)
    {
        DMA_Cmd(COMMU_COM_DMAY_STREAMX_TX, DISABLE); 
        DMA_SetCurrDataCounter(COMMU_COM_DMAY_STREAMX_TX, sizeof(SenData));
        DMA_ClearITPendingBit(COMMU_COM_DMAY_STREAMX_TX, COMMU_COM_DMA_IT_TC_TX);					//清除DMA发送完成中断标志位
    }
    #endif
}




