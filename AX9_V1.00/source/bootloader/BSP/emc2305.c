#include "emc2305.h"

#include "gpio.h"
#include "systick.h"

void SMDAT_2305_OUT()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOB, &GPIO_InitStruct);	
    SMDAT_2305_1();
}

void SMDAT_2305_IN()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			
    GPIO_Init(GPIOB, &GPIO_InitStruct);	
}

void I2c_Emc_Start()
{
    SMDAT_2305_OUT();
    SMCLK_2305_1();
    delay_us(80);
    SMDAT_2305_1();
    delay_us(80);
    SMDAT_2305_0();
    delay_us(80);
    SMCLK_2305_0();
    delay_us(80);
}

void I2c_Emc_Stop()
{
    SMDAT_2305_OUT();
    SMCLK_2305_0();
    SMDAT_2305_0();
    delay_us(80);
    SMCLK_2305_1();
    delay_us(80);
    SMDAT_2305_1();
    delay_us(80);
}

void I2c_Emc_SendByte(uint8_t data)
{	
    SMDAT_2305_OUT();

    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if((mask&data) == 0)
        {
                SMDAT_2305_0();
        }
        else
        {
                SMDAT_2305_1();
        }
        delay_us(80);
        SMCLK_2305_1();
        delay_us(80);
        SMCLK_2305_0();
        delay_us(80);
    }
}

uint8_t I2c_Emc_ReadByte()
{
    uint8_t data;
    
    SMDAT_2305_IN();
    SMCLK_2305_0();

    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if(SMDAT_2305_READ()==0)
        {
                data &= ~mask;
        }
        else
        {
                data |= mask;
        }
        delay_us(80);
        SMCLK_2305_1();
        delay_us(80);
        SMCLK_2305_0();
        delay_us(80);
    }
    return data;
}

uint8_t I2c_Emc_WaitAck()
{
    uint16_t startCnt = 2;

    SMDAT_2305_IN();

    delay_us(5);
    
    while(SMDAT_2305_READ())
    {
        if(--startCnt == 0)
        {
                return 1;
        }
    }
    
    SMCLK_2305_1();
    delay_us(80);    
    SMCLK_2305_0();
    delay_us(80);
    return 0;
}

void I2c_Emc_SendAck()
{
    SMDAT_2305_OUT();

    SMCLK_2305_0();
    delay_us(80);
    SMDAT_2305_0();
    delay_us(80);
    SMCLK_2305_1();
    delay_us(80);
    SMCLK_2305_0();
    delay_us(80);
}

void I2c_Emc_SendNack()
{
    SMDAT_2305_OUT();
    SMCLK_2305_0();
    delay_us(80);
    SMDAT_2305_1();
    delay_us(80);
    SMCLK_2305_1();
    delay_us(80);
    SMCLK_2305_0();
    delay_us(80);
}

uint8_t Emc2305_WriteByte(uint8_t id, uint8_t addr, uint8_t val)
{    
    I2c_Emc_Start();    
    I2c_Emc_SendByte((id << 1) & 0xFE);     //发送器件地址, 写地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_SendByte(addr);
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_SendByte(val);
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_Stop();
    return 0;
}

uint8_t Emc2305_WriteData(uint8_t id, uint8_t addr, uint8_t *buffer, uint8_t len)
{
    I2c_Emc_Start();
    I2c_Emc_SendByte((id << 1) & 0xFE);     //发送器件地址, 写地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_SendByte(addr);
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    for(int i=0; i<len; i++)
    {
        I2c_Emc_SendByte(*buffer++);
        if(I2c_Emc_WaitAck())
        {
            return 1;
        }
    }
    I2c_Emc_Stop();
    return 0;
}

uint8_t Emc2305_ReadByte(uint8_t id, uint8_t addr, uint8_t *buffer)
{
    I2c_Emc_Start();
    I2c_Emc_SendByte((id << 1) & 0xFE);     //发送器件地址, 写地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_SendByte(addr);
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_Start();
    I2c_Emc_SendByte((id << 1) | 0x01);     //发送器件地址, 读地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    *buffer = I2c_Emc_ReadByte();
    I2c_Emc_SendNack();
    I2c_Emc_Stop();
    return 0;
}

uint8_t Emc2305_ReadData(uint8_t id, uint8_t addr, uint8_t *buffer, uint8_t len)
{
    uint8_t i = 0;
    
    I2c_Emc_Start();
    I2c_Emc_SendByte((id << 1) & 0xFE);     //发送器件地址, 写地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_SendByte(addr);
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    I2c_Emc_Start();
    I2c_Emc_SendByte((id << 1) | 0x01);     //发送器件地址, 读地址
    if(I2c_Emc_WaitAck())
    {
        return 1;
    }
    do
    {
        delay_us(10);
        *buffer++ = I2c_Emc_ReadByte();
        if(++i==len)
        {
            I2c_Emc_SendNack();
        }
        else
        {
            I2c_Emc_SendAck();
        }
    }while(i!=len);
    I2c_Emc_Stop();
    return 0;
}







void Fan_Emc2305_Init()
{
    Emc2305_WriteByte(EMC2305_10K_ADDR, BASIC_CTL, 0x80);               //屏蔽中断  

    Emc2305_WriteByte(EMC2305_10K_ADDR, PWM_POLARITY, 0x00);            //设置PWM极性
    Emc2305_WriteByte(EMC2305_10K_ADDR, PWM_OUTPUT,   0x1F);            //设置PWM为推挽输出
    Emc2305_WriteByte(EMC2305_10K_ADDR, PWM45_BASE,   0x00);            //设置PWM4、PWM5基础频率为26KHz
    Emc2305_WriteByte(EMC2305_10K_ADDR, PWM123_BASE,  0x00);            //设置PWM1、PWM2、PWM3基础频率为26KHz
    
    Emc2305_WriteByte(EMC2305_10K_ADDR, FAN1_SETTING, SPEED_NoMin);     //设置占空比
    Emc2305_WriteByte(EMC2305_10K_ADDR, FAN2_SETTING, SPEED_NoMin);
    Emc2305_WriteByte(EMC2305_10K_ADDR, FAN3_SETTING, SPEED_NoMin);
    Emc2305_WriteByte(EMC2305_10K_ADDR, FAN4_SETTING, SPEED_NoMin);
    Emc2305_WriteByte(EMC2305_10K_ADDR, FAN5_SETTING, SPEED_NoMin);
}







