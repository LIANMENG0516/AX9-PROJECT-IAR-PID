#ifndef __DMA_H
#define __DMA_H

#include "stm32f4xx.h"

void Dma_Config(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_Channelx, uint32_t peripher_address, uint32_t ram_address, uint32_t dma_dir, uint16_t rebuf_seize, uint32_t pdatalen, uint32_t mdatalen, uint32_t dma_mode, uint32_t dma_priority);
void Dmay_Streamx_IRQHandler_CallBack(void);

#endif
