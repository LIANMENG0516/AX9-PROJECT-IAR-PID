#include "bat.h"

extern System_MsgStruct SysMsg;
    
void SMDAT_BAT2_OUT()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOC, &GPIO_InitStruct);	
}

void SMDAT_BAT2_IN()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOC, &GPIO_InitStruct);
    
}

void I2c_Bat2_Start()
{
    SMDAT_BAT2_OUT();
    
    BAT2_SMBUS_C_1();
    delay_us_os(20);
    BAT2_SMBUS_D_1();
    delay_us_os(20);
    BAT2_SMBUS_D_0();
    delay_us_os(20);
    BAT2_SMBUS_C_0();
    delay_us_os(20);
}

void I2c_Bat2_Stop()
{
    SMDAT_BAT2_OUT();
    
    BAT2_SMBUS_C_0();
    delay_us_os(20);
    BAT2_SMBUS_D_0();
    delay_us_os(20);
    BAT2_SMBUS_C_1();
    delay_us_os(20);
    BAT2_SMBUS_D_1();
    delay_us_os(20);
}

void I2c_Bat2_SendByte(unsigned char data)
{	
    SMDAT_BAT2_OUT();
    delay_us_os(20);
    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if((mask&data) == 0)
        {
            BAT2_SMBUS_D_0();
        }
        else
        {
            BAT2_SMBUS_D_1();
        }
        delay_us_os(20);
        BAT2_SMBUS_C_1();
        delay_us_os(20);
        BAT2_SMBUS_C_0();
        delay_us_os(20);        
    }
}

uint8_t I2c_Bat2_WaitAck()
{
    uint16_t startCnt = 2000;

    SMDAT_BAT2_IN();
    
    delay_us_os(200);
    
    while(BAT2_SMBUS_D_READ())
    {
        if(--startCnt == 0)
        {
            return 1;
        }
    }
    delay_us_os(20);
    BAT2_SMBUS_C_1();
    delay_us_os(20);
    BAT2_SMBUS_C_0();
    delay_us_os(20);
    return 0;
}

void I2c_Bat2_SendAck()
{
    SMDAT_BAT2_OUT();

    BAT2_SMBUS_C_0();
    delay_us_os(20);
    BAT2_SMBUS_D_0();
    delay_us_os(20);
    BAT2_SMBUS_C_1();
    delay_us_os(20);
    BAT2_SMBUS_C_0();
    delay_us_os(20);
}

void I2c_Bat2_SendNack()
{
    SMDAT_BAT2_OUT();

    BAT2_SMBUS_C_0();
    delay_us_os(20);
    BAT2_SMBUS_D_1();
    delay_us_os(20);
    BAT2_SMBUS_C_1();
    delay_us_os(20);
    BAT2_SMBUS_C_0();
    delay_us_os(20);
}

uint8_t I2c_Bat2_ReadByte()
{
    uint8_t data;
    
    SMDAT_BAT2_IN();

    delay_us_os(20);
    
    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if(BAT2_SMBUS_D_READ()==0)
        {
            data &= ~mask;
        }
        else
        {
            data |= mask;
        }
        delay_us_os(20);
        BAT2_SMBUS_C_1();
        delay_us_os(20);
        BAT2_SMBUS_C_0();
        delay_us_os(20);
    }
    return data;
}

bool I2c_Bat2_ReadData(uint8_t id, uint8_t regaddr, uint8_t *buffer, uint8_t len)
{
    uint8_t i = 0;
    I2c_Bat2_Start();
    I2c_Bat2_SendByte(id);
    if(I2c_Bat2_WaitAck())
    {
        return FALSE;
    }
    I2c_Bat2_SendByte(regaddr);
    if(I2c_Bat2_WaitAck())
    {
        return FALSE;
    }
    I2c_Bat2_Start();
    I2c_Bat2_SendByte(id | 0x01);
    if(I2c_Bat2_WaitAck())
    {
        return FALSE;
    }
    do
    {
        delay_us_os(60);
        *buffer++ = I2c_Bat2_ReadByte();
        if(++i == len)
        {
            I2c_Bat2_SendNack();
        }
        else
        {
            I2c_Bat2_SendAck();
        }
    }while(i!=len);
    delay_us_os(50);
    I2c_Bat2_Stop();
    
    return TRUE;
}

void Bat2_PowerRead()
{
    uint8_t buffer[3] = {0, 0 , 0};

    if(SysMsg.PwrInfo.Bat2_Insert == TRUE)
    {
        if(I2c_Bat2_ReadData(BAT_ADDR, BAT_PWR_CMD, buffer, 3) == TRUE)
        {
            if(buffer[0] <= 100)
            {
                SysMsg.PwrInfo.Bat2_Power = buffer[0];
            }
        }
    }
    else
    {
        SysMsg.PwrInfo.Bat2_Power = 0;
    }
}

void Bat2_TempatureRead()
{
    uint8_t buffer[2] = {0, 0}, temp = 0;

    if(SysMsg.PwrInfo.Bat2_Insert == TRUE)
    {
        if(I2c_Bat2_ReadData(BAT_ADDR, BAT_TMP_CMD, buffer, 2) == TRUE)
        {
            temp = (int)(((buffer[1] << 8) | buffer[0]) * 0.1) - 273; 
            
            if(temp>0 && temp<100)
            {
                SysMsg.PwrInfo.Bat2_Tempature = temp;
            }
        }
    }
    else
    {
        SysMsg.PwrInfo.Bat2_Tempature = 0;
    }
}

