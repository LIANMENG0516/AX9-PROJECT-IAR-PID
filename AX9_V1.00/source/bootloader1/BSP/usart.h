#ifndef __USART_H
#define __USART_H 	

#include "stm32f4xx.h"

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define DEBUG_COM                       UART4

void Usart_Init(USART_TypeDef* USARTx, uint32_t Baud_Rate);
void Usart_Transmit_Char(USART_TypeDef* USARTx, uint8_t Data);
void Usart_Transmit_String(USART_TypeDef* USARTx, uint8_t *Data);
void Usart_Transmit_Nchar(USART_TypeDef* USARTx, uint8_t *Data, uint8_t Len);
int fputc(int ch, FILE *f);

#endif
