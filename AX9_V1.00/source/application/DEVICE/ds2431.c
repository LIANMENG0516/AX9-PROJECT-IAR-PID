#include "ds2431.h"

#include "gouble.h"

void US_PWR_ID_OUT()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOE, &GPIO_InitStruct);	
}

void US_PWR_ID_IN()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOE, &GPIO_InitStruct);	
}


uint8_t DS2431_Reset()
{
    uint8_t result;

    US_PWR_ID_OUT(); US_PWR_ID_1(); delay_us_os(200);
    US_PWR_ID_0();                                      //拉低总线600us产生复位脉冲
    delay_us_os(600);
    US_PWR_ID_IN();                                     //释放总线
    delay_us_os(60);
    result = US_PWR_ID_READ();                          //接收应答
    delay_us_os(300);

    return result;
}

void DS2431_WriteByte(uint8_t data)
{
    US_PWR_ID_OUT();
    
    for(int i=0; i<8; i++)
    {
        US_PWR_ID_1(); 
        delay_us_os(2); 
        US_PWR_ID_0();
        delay_us_os(10);
        if(data & 0x01)
        {
                US_PWR_ID_1();
        }
        else
        {
                US_PWR_ID_0();
        }
        delay_us_os(60);

        data = data >> 1;
    }
}

uint8_t DS2431_ReadByte()
{
    uint8_t data = 0, mask = 0x01;
    

    for(int i=0; i<8; i++)
	{
        US_PWR_ID_OUT(); 
        US_PWR_ID_1(); 
        delay_us_os(2);
        US_PWR_ID_0();
        delay_us_os(2);
        US_PWR_ID_IN();
        delay_us_os(5);
        if(US_PWR_ID_READ())
        {
            data |= mask;
        }
        else
        {
            data &= ~mask;
        }
        delay_us_os(60);

        mask = mask << 1;
    }
    
    return data;
}

uint8_t DS2431_WriteData(uint8_t addr, uint8_t *buffer)
{
    uint16_t status, crc16;
    
    if(DS2431_Reset())
    {
        return 1;
    }
    
    DS2431_WriteByte(0xCC);
    DS2431_WriteByte(0x0F);
    DS2431_WriteByte(addr);
    DS2431_WriteByte(0x00);
    
    for(uint8_t i=0; i<8; i++)
    {
        DS2431_WriteByte(buffer[i]);
    }
    
    crc16 = DS2431_ReadByte();
    crc16 |= DS2431_ReadByte() << 8;

    if(DS2431_Reset())
    {
        return 1;
    }

    DS2431_WriteByte(0xCC);
    DS2431_WriteByte(0x55);
    DS2431_WriteByte(addr);
    DS2431_WriteByte(0x00);
    DS2431_WriteByte(0x07);


    US_PWR_ID_1();
    delay_us_os(800);

    status = DS2431_ReadByte();

    if(status == 0xAA)
    {
        US_PWR_ID_1();
    }
    
    return 0;
}

uint8_t DS2431_ReadData(uint8_t addr, uint8_t *buffer)
{
    if(DS2431_Reset())
    {
        return 1;
    }
    DS2431_WriteByte(0xCC);
    DS2431_WriteByte(0xF0);
    DS2431_WriteByte(addr);
    DS2431_WriteByte(0x00);
    
    for(uint8_t i=0; i<16; i++)
    {
        buffer[i] = DS2431_ReadByte();
    }
    
    if(DS2431_Reset())
    {
        return 1;
    }
    
    return 0;
}

uint8_t UsPowerId[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void Write_UsPowerId(uint8_t *buffer)
{    
    for(uint8_t i=0; i<16; i++)
    {
        UsPowerId[i] = *buffer++;
    }

    DS2431_WriteData(0, UsPowerId);
}

void Read_UsPowerId(uint8_t *buffer)
{
    DS2431_ReadData(0, buffer);

}
























