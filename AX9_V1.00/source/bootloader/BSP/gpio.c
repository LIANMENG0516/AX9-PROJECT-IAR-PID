#include "gpio.h"

static void Gpio_Init(GPIO_TypeDef* GPIOx, uint16_t Gpio_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    GPIO_InitStruct.GPIO_Pin = Gpio_Pin;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode;				
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;		
    GPIO_InitStruct.GPIO_OType = GPIO_OType;				
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd;			
    GPIO_Init(GPIOx, &GPIO_InitStruct);	
}

void Gpio_Config()
{	
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG, ENABLE);                                   
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);                         //使能PWR时钟
    PWR_BackupAccessCmd(ENABLE);                                                //使能后备寄存器访问
    RCC_LSEConfig(RCC_LSE_OFF);                                                 //关闭外部低速外部时钟, 关闭后PC14 PC15才可以当普通IO用。
    PWR_BackupAccessCmd(DISABLE);                                               //禁止修改后备寄存器
	
    //USART4_DEBUG_COM
    GPIO_PinAFConfig(DEBUG_COM_TX_PORT, GPIO_PinSource0, GPIO_AF_UART4);
    GPIO_PinAFConfig(DEBUG_COM_RX_PORT, GPIO_PinSource1, GPIO_AF_UART4);
    Gpio_Init(DEBUG_COM_TX_PORT, DEBUG_COM_TX_PIN, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    Gpio_Init(DEBUG_COM_RX_PORT, DEBUG_COM_RX_PIN, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_AP5V5_2_ADC
    Gpio_Init(T_AP5V5_2_PORT, T_AP5V5_2_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    
    //T_D5V_ADC
    Gpio_Init(T_D5V_PORT, T_D5V_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    
    //HVADJ1_DAC
    Gpio_Init(HVADJ1_PORT, HVADJ1_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_DOWN);

    //HVADJ3_DAC
    Gpio_Init(HVADJ3_PORT, HVADJ3_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_DOWN);

    //BAT2_SMBUS_C
    Gpio_Init(BAT2_SMBUS_C_PORT, BAT2_SMBUS_C_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);
    GPIO_SetBits(BAT2_SMBUS_C_PORT, BAT2_SMBUS_C_PIN);
    
    //USB_CTRL
    Gpio_Init(USB_CTRL_PORT, USB_CTRL_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    USB_CTRL_EN(1);                                             //初始化禁止USB插入, 防止电流导管

    //SPI3_CS3  
    Gpio_Init(SPI3_CS3_PORT, SPI3_CS3_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP);    
    
    //SMCLK_2305
    Gpio_Init(SMCLK_2305_PORT, SMCLK_2305_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_NOPULL);
    
    //SMDAT_2305
    Gpio_Init(SMDAT_2305_PORT, SMDAT_2305_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_NOPULL);
    
    //IIC1_SCK
    Gpio_Init(IIC1_SCK_PORT, IIC1_SCK_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP);

    //IIC1_SDA
    Gpio_Init(IIC1_SDA_PORT, IIC1_SDA_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP);
    
    //COME_IICCLK
    Gpio_Init(COME_IICCLK_PORT, COME_IICCLK_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);

    //COME_IICDAT
    Gpio_Init(COME_IICDAT_PORT, COME_IICDAT_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);

    //SPI3_CS2   
    Gpio_Init(SPI3_CS2_PORT, SPI3_CS2_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP);
    
    //SPI3_CS4   
    Gpio_Init(SPI3_CS4_PORT, SPI3_CS4_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_UP);
    
    //T_VPP1_ADC    
    Gpio_Init(T_VPP1_PORT, T_VPP1_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_VNN1_ADC   
    Gpio_Init(T_VNN1_PORT, T_VNN1_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_VPP2_ADC  
    Gpio_Init(T_VPP2_PORT, T_VPP2_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_VNN2_ADC  
    Gpio_Init(T_VNN2_PORT, T_VNN2_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);    

    //T_IAPD_ADC   
    Gpio_Init(T_IAPD_PORT, T_IAPD_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL); 

    //BAT2_SMBUS_D   
    Gpio_Init(BAT2_SMBUS_D_PORT, BAT2_SMBUS_D_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);
    GPIO_SetBits(BAT2_SMBUS_D_PORT, BAT2_SMBUS_D_PIN);

    //SPI3_SCK
    GPIO_PinAFConfig(SPI3_PORT_SCK, GPIO_PinSource10, GPIO_AF_SPI3);
    Gpio_Init(SPI3_PORT_SCK, SPI3_PIN_SCK, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP);
    
    //SPI3_MISO
    GPIO_PinAFConfig(SPI3_PORT_MISO, GPIO_PinSource11, GPIO_AF_SPI3);
    Gpio_Init(SPI3_PORT_MISO, SPI3_PIN_MISO, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP);

    //SPI3_MOSI
    GPIO_PinAFConfig(SPI3_PORT_MOSI, GPIO_PinSource12, GPIO_AF_SPI3);
    Gpio_Init(SPI3_PORT_MOSI, SPI3_PIN_MOSI, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_UP);

    //C_P5V5_1
    Gpio_Init(C_P5V5_1_PORT, C_P5V5_1_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_P5V5_1_EN(0);

    //C_P5V5_2
    Gpio_Init(C_P5V5_2_PORT, C_P5V5_2_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_P5V5_2_EN(0);
    
    //LIDIN
    Gpio_Init(LIDIN_PORT, LIDIN_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //CHARGE_EN
    Gpio_Init(CHARGE_EN_PORT, CHARGE_EN_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //C_P2V25
    Gpio_Init(C_P2V25_PORT, C_P2V25_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_P2V25_EN(0);
    
    //C_D0V95
    Gpio_Init(C_D0V95_PORT, C_D0V95_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_D0V95_EN(0);
    
    //C_D1V45
    Gpio_Init(C_D1V45_PORT, C_D1V45_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_D1V45_EN(0);

    //USART2_COMM_COM
    GPIO_PinAFConfig(COMM_COM_TX_PORT, GPIO_PinSource5, GPIO_AF_USART2);
    GPIO_PinAFConfig(COMM_COM_RX_PORT, GPIO_PinSource6, GPIO_AF_USART2);
    Gpio_Init(COMM_COM_TX_PORT, COMM_COM_TX_PIN, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    Gpio_Init(COMM_COM_RX_PORT, COMM_COM_RX_PIN, GPIO_Mode_AF, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //C_P12V
    Gpio_Init(C_P12V_PORT, C_P12V_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
     CTL_P12V_EN(0);

    //C_P3V75
    Gpio_Init(C_P3V75_PORT, C_P3V75_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_P3V75_EN(0); 

    //C_N12V_5V5
    Gpio_Init(C_N12V_5V5_PORT, C_N12V_5V5_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_N12V_5V5_EN(0);

    //PD10
    Gpio_Init(PD10_PORT, PD10_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //CHARGE_CTL
    Gpio_Init(CHARGE_CTL_PORT, CHARGE_CTL_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //C_VDD_P5V
    Gpio_Init(C_VDD_P5V_PORT, C_VDD_P5V_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    CTL_VDD_P5V_EN(0);

    //PBUS_ON
    Gpio_Init(PBUS_ON_PORT, PBUS_ON_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //SV_CTL_IN
    Gpio_Init(SV_CTL_IN_PORT, SV_CTL_IN_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    SV_CTL_IN(0);

    //V_PROE1
    Gpio_Init(V_PROE1_PORT, V_PROE1_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_UP);

    //V_PROE2
    Gpio_Init(V_PROE2_PORT, V_PROE2_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_UP);

    //PWR_KEY
    Gpio_Init(PWR_KEY_PORT, PWR_KEY_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_DOWN);

    //PWR_CTL
    Gpio_Init(PWR_CTL_PORT, PWR_CTL_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //BAT_STAT1
    Gpio_Init(BAT_STAT1_PORT, BAT_STAT1_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //BAT_STAT2
    Gpio_Init(BAT_STAT2_PORT, BAT_STAT2_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    
    //FPGA配置完成状态引脚
    Gpio_Init(FPGA_CFG_DOWN_PORT, FPGA_CFG_DOWN_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //SYS_LED
    Gpio_Init(SYS_LED_PORT, SYS_LED_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //AC_OK
    Gpio_Init(AC_OK_PORT, AC_OK_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //PWR_BTN_COM
    Gpio_Init(PWR_BTN_COM_PORT, PWR_BTN_COM_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_NOPULL);
    PWR_BTN_COM(1);

    //US_PWR_ID
    Gpio_Init(US_PWR_ID_PORT, US_PWR_ID_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_NOPULL);
    //US_PWR_ID_1();
    
    //SUS_S4
    Gpio_Init(SUS_S4_PORT, SUS_S4_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //SUS_S3
    Gpio_Init(SUS_S3_PORT, SUS_S3_PIN, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //BAT1_SMBUS_D
    Gpio_Init(BAT1_SMBUS_D_PORT, BAT1_SMBUS_D_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);
    GPIO_SetBits(BAT1_SMBUS_D_PORT, BAT1_SMBUS_D_PIN);
    
    //BAT1_SMBUS_C 
    Gpio_Init(BAT1_SMBUS_C_PORT, BAT1_SMBUS_C_PIN, GPIO_Mode_OUT, GPIO_OType_OD, GPIO_PuPd_UP);
    GPIO_SetBits(BAT1_SMBUS_C_PORT, BAT1_SMBUS_C_PIN);

    //PWR_OK_COM
    Gpio_Init(PWR_OK_COM_PORT, PWR_OK_COM_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_A2V25_ADC
    Gpio_Init(T_A2V25_PORT, T_A2V25_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
        
    //T_A3V75_ADC  
    Gpio_Init(T_A3V75_PORT, T_A3V75_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_AP5V5_1_ADC   
    Gpio_Init(T_AP5V5_1_PORT, T_AP5V5_1_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
        
    //T_AP12V_ADC 
    Gpio_Init(T_AP12V_PORT, T_AP12V_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_AN5V5_ADC   
    Gpio_Init(T_AN5V5_PORT, T_AN5V5_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
     
    //T_AN12V_ADC 
    Gpio_Init(T_AN12V_PORT, T_AN12V_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_D0V95_ADC   
    Gpio_Init(T_D0V95_PORT, T_D0V95_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //T_D1V45_ADC
    Gpio_Init(T_D1V45_PORT, T_D1V45_PIN, GPIO_Mode_AN, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    
    //AFE_EN1
    Gpio_Init(AFE_EN1_PORT, AFE_EN1_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //AFE_EN2
    Gpio_Init(AFE_EN2_PORT, AFE_EN2_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //EN_FPGA_01
    Gpio_Init(EN_FPGA_01_PORT, EN_FPGA_01_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //EN_FPGA_02
    Gpio_Init(EN_FPGA_02_PORT, EN_FPGA_02_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //EN_FRONT
    Gpio_Init(EN_FRONT_PORT, EN_FRONT_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //BAT1_C_SHIFT
    Gpio_Init(BAT1_C_SHIFT_PORT, BAT1_C_SHIFT_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //BAT2_C_SHIFT
    Gpio_Init(BAT2_C_SHIFT_PORT, BAT2_C_SHIFT_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //CHARGE_LED_O
    Gpio_Init(CHARGE_LED_O_PORT, CHARGE_LED_O_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //CHARGE_LED_G
    Gpio_Init(CHARGE_LED_G_PORT, CHARGE_LED_G_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);

    //SLEEP_LED_C
    Gpio_Init(SLEEP_LED_C_PORT, SLEEP_LED_C_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    
    //AUDIO_MUTE
    Gpio_Init(AUDIO_MUTE_PORT, AUDIO_MUTE_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL);
    AUDIO_MUTE_EN(1);

    //C_VNN2_VPP2
    Gpio_Init(C_VPP2_VNN2_PORT, C_VPP2_VNN2_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_DOWN);
    CTL_VPP2_VNN2_EN(0);

    //C_VNN1_VPP1
    Gpio_Init(C_VPP1_VNN1_PORT, C_VPP1_VNN1_PIN, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_DOWN); 
    CTL_VPP1_VNN1_EN(0);    
}























