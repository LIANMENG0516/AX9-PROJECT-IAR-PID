#include "usart.h"

void Usart_Init(USART_TypeDef* USARTx, uint32_t Baud_Rate)
{
    USART_InitTypeDef USART_InitStructure;
    
    if(USARTx == USART1)
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    else if(USARTx == USART2)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    else if(USARTx == USART3)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    else if(USARTx == UART4)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
    else if(USARTx == UART5)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
    
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    
    USART_Init(USARTx, &USART_InitStructure); 	
    
    USART_Cmd(USARTx, ENABLE);
}

void Usart_Transmit_Char(USART_TypeDef* USARTx, uint8_t Data)
{
    while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) != SET);	//wait to tx register is empty
    USART_SendData(USARTx, Data);
}

void Usart_Transmit_String(USART_TypeDef* USARTx, uint8_t *Data)
{
    while(*Data)
    {
        Usart_Transmit_Char(USARTx, *Data);
        Data++;
    }
}

void Usart_Transmit_Nchar(USART_TypeDef* USARTx, uint8_t *Data, uint8_t Len)
{
    while(Len--)
    {
        Usart_Transmit_Char(USARTx, *Data);
        Data++;
    }
}

struct __FILE
{
    int handle;
};
FILE __stdout; 

void _sys_exit(int x)
{
    x = x;
}

int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(DEBUG_COM, USART_FLAG_TC) == RESET);
    USART_SendData(DEBUG_COM, (uint8_t)ch);
    return (ch);
}

