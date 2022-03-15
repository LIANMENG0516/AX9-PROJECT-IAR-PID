#include "spi.h"

void Spi_config(SPI_TypeDef* SPIx, uint16_t DataSize, uint16_t Cpol, uint16_t Cpha)
{
    SPI_InitTypeDef SPI_InitStruct;
    
    if(SPIx == SPI1)
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    else if(SPIx == SPI2)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
    else if(SPIx == SPI3)
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);
    else if(SPIx == SPI4)
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4, ENABLE);
    else if(SPIx == SPI5)
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI5, ENABLE);
    else if(SPIx == SPI6)
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI6, ENABLE);
    
    SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_DataSize = DataSize;
    SPI_InitStruct.SPI_CPOL = Cpol;
    SPI_InitStruct.SPI_CPHA = Cpha;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;

    SPI_Init(SPIx, &SPI_InitStruct);
    
    SPI_Cmd(SPIx, ENABLE);
}

uint8_t SPI_ReadWriteByte(SPI_TypeDef* SPIx, uint8_t data)
{		
    u8 retry = 0;				 	
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) != SET)
    {
        retry++;
        if(retry > 200)
        {
                return 0;
        }	
    }		
    SPI_I2S_SendData(SPIx, data);
    
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) != SET)
    {
        retry++;
        if(retry > 200)
        {
                return 0;
        }
    }	  						    
    return SPI_I2S_ReceiveData(SPIx);		    
}


uint8_t SPI_WriteHalfWord(SPI_TypeDef* SPIx, uint16_t data)
{
    uint16_t retry = 0;				 	
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) != SET)
    {
        retry++;
        if(retry > 2000)
        {
                return 0;
        }	
    }		
    SPI_I2S_SendData(SPIx, data);
    
    return 1;
}


uint8_t SPI_ReadWriteHalfWord(SPI_TypeDef* SPIx, uint16_t data)
{					 	
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);		
    SPI_I2S_SendData(SPIx, data);
    
    while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);	  						    
    return SPI_I2S_ReceiveData(SPIx);		    
}












