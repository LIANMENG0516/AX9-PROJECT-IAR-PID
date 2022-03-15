#include "tmp468.h"

#include "gouble.h"

void IIC1_SDA_OUT()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			
    GPIO_Init(GPIOB, &GPIO_InitStruct);	
}

void IIC1_SDA_IN()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			
    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void I2c_Tmp_Start()
{
    IIC1_SDA_OUT();
    IIC1_SCK_1();
    IIC1_SDA_1();
    Delay_Nop(200);
    IIC1_SDA_0();
    Delay_Nop(200);
    IIC1_SCK_0();
    Delay_Nop(200);
}

void I2c_Tmp_Stop()
{
    IIC1_SDA_OUT();
    IIC1_SCK_0();
    IIC1_SDA_0();
    Delay_Nop(200);
    IIC1_SCK_1();
    Delay_Nop(200);
    IIC1_SDA_1();
    Delay_Nop(200);
}

void I2c_Tmp_SendByte(unsigned char data)
{	
    IIC1_SDA_OUT();

    Delay_Nop(200);
    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if((mask&data) == 0)
        {
                IIC1_SDA_0();
        }
        else
        {
                IIC1_SDA_1();
        }
        Delay_Nop(200);
        IIC1_SCK_1();
        Delay_Nop(200);
        IIC1_SCK_0();
        Delay_Nop(200);
    }
}

uint8_t I2c_Tmp_WaitAck()
{
    uint16_t startCnt = 5000;
    
    IIC1_SDA_IN();
    
    while(IIC1_SDA_READ())
    {
        if(--startCnt == 0)
        {
                return 1;
        }
    }
    
    IIC1_SCK_1();
    Delay_Nop(200);   
    IIC1_SCK_0();
    Delay_Nop(200);
    return 0;
}

void I2c_Tmp_SendAck()
{
    IIC1_SDA_OUT();

    IIC1_SCK_0();
    Delay_Nop(200);
    IIC1_SDA_0();
    Delay_Nop(200);
    IIC1_SCK_1();
    Delay_Nop(200);
    IIC1_SCK_0();
    Delay_Nop(200);
}

void I2c_Tmp_SendNack()
{
    IIC1_SDA_OUT();

    IIC1_SCK_0();
    Delay_Nop(200);
    IIC1_SDA_1();
    Delay_Nop(200);
    IIC1_SCK_1();
    Delay_Nop(200);
    IIC1_SCK_0();
    Delay_Nop(200);
}

uint8_t I2c_Tmp_ReadByte()
{
    uint8_t data;
    
    IIC1_SDA_IN();
    IIC1_SCK_0();

    for(uint8_t mask=0x80; mask!=0; mask>>=1)
    {
        if(IIC1_SDA_READ()==0)
        {
            data &= ~mask;
        }
        else
        {
            data |= mask;
        }
        Delay_Nop(200);
        IIC1_SCK_1();
        Delay_Nop(200);
        IIC1_SCK_0();
        Delay_Nop(200);
    }
    return data;
}

uint8_t Tmp468_WriteByte(uint8_t id, uint16_t addr, uint16_t val)
{
    I2c_Tmp_Start();
    I2c_Tmp_SendByte((id << 1) & 0xFE);           //发送器件地址, 写地址
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_SendByte(addr);
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_SendByte(val);
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_Stop();
    return 0;
}

uint8_t Tmp468_ReadByte(uint8_t id, uint8_t addr, uint8_t *buffer)
{
    I2c_Tmp_Start();
    I2c_Tmp_SendByte((id << 1) & 0xFE);     //发送器件地址, 写地址
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_SendByte(addr);
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_SendByte((id << 1) | 0x01);     //发送器件地址, 读地址
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    *buffer = I2c_Tmp_ReadByte();
    I2c_Tmp_SendNack();
    I2c_Tmp_Stop();
    return 0;
}

uint8_t Tmp468_ReadData(uint8_t id, uint8_t addr, uint8_t *buffer, uint8_t len)
{
    uint8_t i = 0;
    
    I2c_Tmp_Start();
    I2c_Tmp_SendByte((id << 1) & 0xFE); 
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_SendByte(addr);
    if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    I2c_Tmp_Start();
    I2c_Tmp_SendByte((id << 1) | 0x01);
	if(I2c_Tmp_WaitAck())
    {
        return 1;
    }
    do
    {
        Delay_Nop(200);
        *buffer++ = I2c_Tmp_ReadByte();
        if(++i==len)
        {
            I2c_Tmp_SendNack();
        }
        else
        {
            I2c_Tmp_SendAck();
        }
    }while(i!=len);
    I2c_Tmp_Stop();
    return 0;
}

extern System_MsgStruct SysMsg;

void Obtain_TemperatureFPGA()
{
    uint8_t Temp[2];

    Tmp468_ReadData(TMP468_ADDR, RT1_ADDR, Temp, 2);
    
    SysMsg.Temperature.FPGA = (int)(((((Temp[0] << 8) + Temp[1]) >> 3) * 0.0625) + 0.5);    //四舍五入取整数
}







