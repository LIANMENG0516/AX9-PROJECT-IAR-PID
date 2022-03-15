#include "tlv5626cd.h"

#include "gouble.h"

void Spi_Dac_Config()
{
    Spi_config(SPI3, SPI_DataSize_16b, SPI_CPOL_High, SPI_CPHA_1Edge);
}

void DacHv_Tlv5626cd_ValueSet(uint8_t dataA, uint8_t dataB)
{      
    CTL_SPI3_CS2(0);
    SPI_WriteHalfWord(SPI3, TLV562CD_MODE);
    Delay_Nop(4000);
    CTL_SPI3_CS2(1);
    
    Delay_Nop(2000);
    
    CTL_SPI3_CS2(0);
    SPI_WriteHalfWord(SPI3, (0x1000 | (dataB << 4)));
    Delay_Nop(4000);
    CTL_SPI3_CS2(1);

    Delay_Nop(2000);
    
    CTL_SPI3_CS2(0);
    SPI_WriteHalfWord(SPI3, (0x8000 | (dataA << 4)));
    Delay_Nop(4000);
    CTL_SPI3_CS2(1);
}

void DacCw_Tlv5626cd_ValueSet(uint8_t dataA, uint8_t dataB)
{ 
    CTL_SPI3_CS4(0);
    SPI_WriteHalfWord(SPI3, TLV562CD_MODE);
    Delay_Nop(4000);
    CTL_SPI3_CS4(1);
    
    Delay_Nop(2000);
    
    CTL_SPI3_CS4(0);
    SPI_WriteHalfWord(SPI3, (0x1000 | (dataB << 4)));
    Delay_Nop(4000);
    CTL_SPI3_CS4(1);

    Delay_Nop(2000);
    
    CTL_SPI3_CS4(0);
    SPI_WriteHalfWord(SPI3, (0x8000 | (dataA << 4)));
    Delay_Nop(4000);
    CTL_SPI3_CS4(1);
}










