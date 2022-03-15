#ifndef __USART_H
#define __USART_H 	

#include "stm32f4xx.h"

#include "gouble.h"

typedef struct
{
	uint8_t *Data;
	uint8_t Len;
}Com_Buffer;

#define DEBUG_COM                       UART4
#define DEBUG_COM_DMAY_STREAMX_RX       DMA1_Stream2
#define DEBUG_COM_DMAY_STREAMX_TX       DMA1_Stream4
#define DEBUG_COM_DMA_CHANNEL_RX        DMA_Channel_4
#define DEBUG_COM_DMA_CHANNEL_TX        DMA_Channel_4
#define DEBUG_COM_DMA_FLAG_TC_RX        DMA_FLAG_TCIF4
#define DEBUG_COM_DMA_IT_TC_TX          DMA_IT_TCIF4

#define COMMU_COM                       USART2
#define COMMU_COM_DMAY_STREAMX_RX       DMA1_Stream5
#define COMMU_COM_DMAY_STREAMX_TX       DMA1_Stream6
#define COMMU_COM_DMA_CHANNEL_RX        DMA_Channel_4
#define COMMU_COM_DMA_CHANNEL_TX        DMA_Channel_4
#define COMMU_COM_DMA_FLAG_TC_RX        DMA_FLAG_TCIF4
#define COMMU_COM_DMA_IT_TC_TX          DMA_IT_TCIF6

void Usart_Init(USART_TypeDef* USARTx, uint32_t Baud_Rate);
void Usart_Transmit_Char(USART_TypeDef* USARTx, uint8_t Data);
void Usart_Transmit_String(USART_TypeDef* USARTx, uint8_t *Data);
void Usart_Transmit_Nchar(USART_TypeDef* USARTx, uint8_t *Data, uint8_t Len);
int fputc(int ch, FILE *f);

void Com_IRQHandler_CallBack(void);

#endif
