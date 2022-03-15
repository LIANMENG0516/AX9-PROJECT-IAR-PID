#ifndef __GPIO_H_
#define __GPIO_H_

#include "stm32f4xx.h"

//USART4_DEBUG_COM
#define DEBUG_COM_TX_PORT         GPIOA
#define DEBUG_COM_TX_PIN          GPIO_Pin_0

#define DEBUG_COM_RX_PORT         GPIOA
#define DEBUG_COM_RX_PIN          GPIO_Pin_1

//T_AP5V5_2_ADC
#define T_AP5V5_2_PORT            GPIOA
#define T_AP5V5_2_PIN             GPIO_Pin_2

//T_D5V_ADC
#define T_D5V_PORT                GPIOA
#define T_D5V_PIN                 GPIO_Pin_3

//HVADJ1_DAC
#define HVADJ1_PORT               GPIOA
#define HVADJ1_PIN                GPIO_Pin_4

//HVADJ3_DAC
#define HVADJ3_PORT               GPIOA
#define HVADJ3_PIN                GPIO_Pin_5

//BAT2_SMBUS_C
#define BAT2_SMBUS_C_PORT         GPIOA
#define BAT2_SMBUS_C_PIN          GPIO_Pin_8
#define BAT2_SMBUS_C_1()          GPIO_SetBits(BAT2_SMBUS_C_PORT, BAT2_SMBUS_C_PIN)
#define BAT2_SMBUS_C_0()          GPIO_ResetBits(BAT2_SMBUS_C_PORT, BAT2_SMBUS_C_PIN)

//USB_CTRL
#define USB_CTRL_PORT             GPIOA
#define USB_CTRL_PIN              GPIO_Pin_10
#define USB_CTRL_EN(x)            x ? GPIO_ResetBits(USB_CTRL_PORT, USB_CTRL_PIN) : GPIO_SetBits(USB_CTRL_PORT, USB_CTRL_PIN)

//SPI3_CS3   
#define SPI3_CS3_PORT             GPIOB
#define SPI3_CS3_PIN              GPIO_Pin_0
#define CTL_SPI3_CS3(x)           x ? GPIO_SetBits(SPI3_CS3_PORT, SPI3_CS3_PIN) : GPIO_ResetBits(SPI3_CS3_PORT, SPI3_CS3_PIN)

//SMCLK_2305
#define SMCLK_2305_PORT           GPIOB
#define SMCLK_2305_PIN            GPIO_Pin_6
#define SMCLK_2305_1()            GPIO_SetBits(SMCLK_2305_PORT, SMCLK_2305_PIN)
#define SMCLK_2305_0()            GPIO_ResetBits(SMCLK_2305_PORT, SMCLK_2305_PIN)

//SMDAT_2305
#define SMDAT_2305_PORT           GPIOB
#define SMDAT_2305_PIN            GPIO_Pin_7
#define SMDAT_2305_1()            GPIO_SetBits(SMDAT_2305_PORT, SMDAT_2305_PIN)
#define SMDAT_2305_0()            GPIO_ResetBits(SMDAT_2305_PORT, SMDAT_2305_PIN)
//#define SMDAT_2305_IN()           {GPIOB->MODER = GPIOB->MODER & 0xFFFF3FFF;}
//#define SMDAT_2305_OUT()          {GPIOB->MODER = GPIOB->MODER & 0xFFFF7FFF; GPIOB->MODER = GPIOB->MODER | 0x00004000;}
#define SMDAT_2305_READ()         GPIO_ReadInputDataBit(SMDAT_2305_PORT, SMDAT_2305_PIN)

//IIC1_SCK
#define IIC1_SCK_PORT             GPIOB      
#define IIC1_SCK_PIN              GPIO_Pin_8    
#define IIC1_SCK_1()              GPIO_SetBits(IIC1_SCK_PORT, IIC1_SCK_PIN)
#define IIC1_SCK_0()              GPIO_ResetBits(IIC1_SCK_PORT, IIC1_SCK_PIN)

//IIC1_SDA
#define IIC1_SDA_PORT             GPIOB
#define IIC1_SDA_PIN              GPIO_Pin_9 
#define IIC1_SDA_1()              GPIO_SetBits(IIC1_SDA_PORT, IIC1_SDA_PIN)
#define IIC1_SDA_0()              GPIO_ResetBits(IIC1_SDA_PORT, IIC1_SDA_PIN)
//#define IIC1_SDA_IN()             {GPIOB->MODER = GPIOB->MODER & 0xFFF3FFFF;}
//#define IIC1_SDA_OUT()            {GPIOB->MODER = GPIOB->MODER & 0xFFF7FFFF; GPIOB->MODER = GPIOB->MODER | 0x00040000;}
#define IIC1_SDA_READ()           GPIO_ReadInputDataBit(IIC1_SDA_PORT, IIC1_SDA_PIN)

//COME_IICCLK
#define COME_IICCLK_PORT          GPIOB      
#define COME_IICCLK_PIN           GPIO_Pin_10    
#define COME_IICCLK_1()           GPIO_SetBits(IIC1_SCK_PORT, IIC1_SCK_PIN)
#define COME_IICCLK_0()           GPIO_ResetBits(IIC1_SCK_PORT, IIC1_SCK_PIN)

//COME_IICDAT
#define COME_IICDAT_PORT          GPIOB
#define COME_IICDAT_PIN           GPIO_Pin_11 
#define COME_IICDAT_1()           GPIO_SetBits(COME_IICDAT_PORT, COME_IICDAT_PIN)
#define COME_IICDAT_0()           GPIO_ResetBits(COME_IICDAT_PORT, COME_IICDAT_PIN)
//#define COME_IICDAT_IN()             {GPIOB->MODER = GPIOB->MODER & 0xFF3FFFFF;}
//#define COME_IICDAT_OUT()            {GPIOB->MODER = GPIOB->MODER & 0xFF7FFFFF; GPIOB->MODER = GPIOB->MODER | 0x00400000;}
#define COME_IICDAT_READ()           GPIO_ReadInputDataBit(COME_IICDAT_PORT, COME_IICDAT_PIN)

//SPI3_CS2   
#define SPI3_CS2_PORT             GPIOB
#define SPI3_CS2_PIN              GPIO_Pin_13
#define CTL_SPI3_CS2(x)           x ? GPIO_SetBits(SPI3_CS2_PORT, SPI3_CS2_PIN) : GPIO_ResetBits(SPI3_CS2_PORT, SPI3_CS2_PIN)

//SPI3_CS4   
#define SPI3_CS4_PORT             GPIOB
#define SPI3_CS4_PIN              GPIO_Pin_14
#define CTL_SPI3_CS4(x)           x ? GPIO_SetBits(SPI3_CS4_PORT, SPI3_CS4_PIN) : GPIO_ResetBits(SPI3_CS4_PORT, SPI3_CS4_PIN)

//T_VPP1_ADC    
#define T_VPP1_PORT               GPIOC
#define T_VPP1_PIN                GPIO_Pin_0

//T_VNN1_ADC    
#define T_VNN1_PORT               GPIOC
#define T_VNN1_PIN                GPIO_Pin_1

//T_VPP2_ADC    
#define T_VPP2_PORT               GPIOC
#define T_VPP2_PIN                GPIO_Pin_2

//T_VNN2_ADC    
#define T_VNN2_PORT               GPIOC
#define T_VNN2_PIN                GPIO_Pin_3

//T_IAPD_ADC    
#define T_IAPD_PORT               GPIOC
#define T_IAPD_PIN                GPIO_Pin_5

//BAT2_SMBUS_D   
#define BAT2_SMBUS_D_PORT         GPIOC
#define BAT2_SMBUS_D_PIN          GPIO_Pin_9
#define BAT2_SMBUS_D_1()          GPIO_SetBits(BAT2_SMBUS_D_PORT, BAT2_SMBUS_D_PIN)
#define BAT2_SMBUS_D_0()          GPIO_ResetBits(BAT2_SMBUS_D_PORT, BAT2_SMBUS_D_PIN)
#define BAT2_SMBUS_D_READ()       GPIO_ReadInputDataBit(BAT2_SMBUS_D_PORT, BAT2_SMBUS_D_PIN)

//SPI3_SCK
#define SPI3_PORT_SCK             GPIOC
#define SPI3_PIN_SCK              GPIO_Pin_10

//SPI3_MISO
#define SPI3_PORT_MISO            GPIOC  
#define SPI3_PIN_MISO             GPIO_Pin_11

//SPI3_MOSI
#define SPI3_PORT_MOSI            GPIOC
#define SPI3_PIN_MOSI             GPIO_Pin_12

//C_P5V5_1
#define C_P5V5_1_PORT             GPIOC
#define C_P5V5_1_PIN              GPIO_Pin_13
#define CTL_P5V5_1_EN(x)          x ? GPIO_ResetBits(C_P5V5_1_PORT, C_P5V5_1_PIN) : GPIO_SetBits(C_P5V5_1_PORT, C_P5V5_1_PIN)

//C_P5V5_2
#define C_P5V5_2_PORT             GPIOC
#define C_P5V5_2_PIN              GPIO_Pin_14
#define CTL_P5V5_2_EN(x)          x ? GPIO_ResetBits(C_P5V5_2_PORT, C_P5V5_2_PIN) : GPIO_SetBits(C_P5V5_2_PORT, C_P5V5_2_PIN)

//LIDIN
#define LIDIN_PORT                GPIOC
#define LIDIN_PIN                 GPIO_Pin_15

//PWR_BTN
#define PWRBTN_PORT               GPIOD
#define PWRBTN_PIN                GPIO_Pin_0

//CHARGE_EN
#define CHARGE_EN_PORT            GPIOD
#define CHARGE_EN_PIN             GPIO_Pin_1
#define CHARGE_EN(x)              x ? GPIO_SetBits(CHARGE_EN_PORT, CHARGE_EN_PIN) : GPIO_ResetBits(CHARGE_EN_PORT, CHARGE_EN_PIN)

//C_P2V25
#define C_P2V25_PORT              GPIOD
#define C_P2V25_PIN               GPIO_Pin_2
#define CTL_P2V25_EN(x)           x ? GPIO_ResetBits(C_P2V25_PORT, C_P2V25_PIN) : GPIO_SetBits(C_P2V25_PORT, C_P2V25_PIN)

//C_D0V95
#define C_D0V95_PORT              GPIOD
#define C_D0V95_PIN               GPIO_Pin_3
#define CTL_D0V95_EN(x)           x ? GPIO_ResetBits(C_D0V95_PORT, C_D0V95_PIN) : GPIO_SetBits(C_D0V95_PORT, C_D0V95_PIN) 

//C_D1V45
#define C_D1V45_PORT              GPIOD
#define C_D1V45_PIN               GPIO_Pin_4
#define CTL_D1V45_EN(x)           x ? GPIO_ResetBits(C_D1V45_PORT, C_D1V45_PIN) : GPIO_SetBits(C_D1V45_PORT, C_D1V45_PIN)

//USART2_COMM_COM
#define COMM_COM_TX_PORT          GPIOD
#define COMM_COM_TX_PIN           GPIO_Pin_5

#define COMM_COM_RX_PORT          GPIOD
#define COMM_COM_RX_PIN           GPIO_Pin_6

//C_P12V
#define C_P12V_PORT               GPIOD
#define C_P12V_PIN                GPIO_Pin_7
#define CTL_P12V_EN(x)            x ? GPIO_ResetBits(C_P12V_PORT, C_P12V_PIN) : GPIO_SetBits(C_P12V_PORT, C_P12V_PIN)

//C_P3V75
#define C_P3V75_PORT              GPIOD
#define C_P3V75_PIN               GPIO_Pin_8
#define CTL_P3V75_EN(x)           x ? GPIO_ResetBits(C_P3V75_PORT, C_P3V75_PIN) : GPIO_SetBits(C_P3V75_PORT, C_P3V75_PIN)

//C_N12V_5V5
#define C_N12V_5V5_PORT           GPIOD
#define C_N12V_5V5_PIN            GPIO_Pin_9
#define CTL_N12V_5V5_EN(x)        x ? GPIO_ResetBits(C_N12V_5V5_PORT, C_N12V_5V5_PIN) : GPIO_SetBits(C_N12V_5V5_PORT, C_N12V_5V5_PIN)

//PD10
#define PD10_PORT                 GPIOD
#define PD10_PIN                  GPIO_Pin_10
#define CTL_MCU_LED(x)            x ? GPIO_SetBits(PD10_PORT, PD10_PIN) : GPIO_ResetBits(PD10_PORT, PD10_PIN)
#define MCU_LED_BLINK()           GPIO_ToggleBits(PD10_PORT, PD10_PIN)

//CHARGE_CTL
#define CHARGE_CTL_PORT           GPIOD
#define CHARGE_CTL_PIN            GPIO_Pin_11
#define CHARGE_CTL(x)             x ? GPIO_SetBits(CHARGE_CTL_PORT, CHARGE_CTL_PIN) : GPIO_ResetBits(CHARGE_CTL_PORT, CHARGE_CTL_PIN)

//C_VDD_P5V
#define C_VDD_P5V_PORT            GPIOD
#define C_VDD_P5V_PIN             GPIO_Pin_12
#define CTL_VDD_P5V_EN(x)         x ? GPIO_ResetBits(C_VDD_P5V_PORT, C_VDD_P5V_PIN) : GPIO_SetBits(C_VDD_P5V_PORT, C_VDD_P5V_PIN)

//PBUS_ON
#define PBUS_ON_PORT              GPIOD
#define PBUS_ON_PIN               GPIO_Pin_13
#define PBUS_ON(x)                x ? GPIO_SetBits(PBUS_ON_PORT, PBUS_ON_PIN) : GPIO_ResetBits(PBUS_ON_PORT, PBUS_ON_PIN)

//SV_CTL_IN
#define SV_CTL_IN_PORT            GPIOD
#define SV_CTL_IN_PIN             GPIO_Pin_14
#define SV_CTL_IN(x)              x ? GPIO_SetBits(SV_CTL_IN_PORT, SV_CTL_IN_PIN) : GPIO_ResetBits(SV_CTL_IN_PORT, SV_CTL_IN_PIN)

//V_PROE1
#define V_PROE1_PORT              GPIOD
#define V_PROE1_PIN               GPIO_Pin_15
#define BAT1_INSERT_CHK(x)        GPIO_ReadInputDataBit(V_PROE1_PORT, V_PROE1_PIN)

//V_PROE2
#define V_PROE2_PORT              GPIOE
#define V_PROE2_PIN               GPIO_Pin_0
#define BAT2_INSERT_CHK(x)        GPIO_ReadInputDataBit(V_PROE2_PORT, V_PROE2_PIN)

//按键检测引脚
#define PWR_KEY_PORT              GPIOE
#define PWR_KEY_PIN               GPIO_Pin_1
#define PWR_KEY_CHK()             GPIO_ReadInputDataBit(PWR_KEY_PORT, PWR_KEY_PIN)

//开关机控制引脚
#define PWR_CTL_PORT              GPIOE
#define PWR_CTL_PIN               GPIO_Pin_2
#define PWR_CTL(x)                x ? GPIO_SetBits(PWR_CTL_PORT, PWR_CTL_PIN) : GPIO_ResetBits(PWR_CTL_PORT, PWR_CTL_PIN)

//电池状态检测引脚1
#define BAT_STAT1_PORT            GPIOE
#define BAT_STAT1_PIN             GPIO_Pin_3
#define BAT_STAT1()               GPIO_ReadInputDataBit(BAT_STAT1_PORT, BAT_STAT1_PIN)

//电池状态检测引脚2
#define BAT_STAT2_PORT            GPIOE
#define BAT_STAT2_PIN             GPIO_Pin_4
#define BAT_STAT2()               GPIO_ReadInputDataBit(BAT_STAT2_PORT, BAT_STAT2_PIN)

//FPGA配置完成状态引脚
#define FPGA_CFG_DOWN_PORT        GPIOE
#define FPGA_CFG_DOWN_PIN         GPIO_Pin_5
#define FPGA_CFG_DOWN_CHK()       GPIO_ReadInputDataBit(FPGA_CFG_DOWN_PORT, FPGA_CFG_DOWN_PIN)

//系统指示灯
#define SYS_LED_PORT              GPIOE
#define SYS_LED_PIN               GPIO_Pin_8
#define SYS_LED(x)                x ? GPIO_SetBits(SYS_LED_PORT, SYS_LED_PIN) : GPIO_ResetBits(SYS_LED_PORT, SYS_LED_PIN)

//AC在位检测引脚
#define AC_OK_PORT                GPIOE
#define AC_OK_PIN                 GPIO_Pin_9
#define AC_INSERT_CHK()           GPIO_ReadInputDataBit(AC_OK_PORT, AC_OK_PIN)

//工控板开关机信号引脚
#define PWR_BTN_COM_PORT          GPIOE
#define PWR_BTN_COM_PIN           GPIO_Pin_10
#define PWR_BTN_COM(x)            x ? GPIO_SetBits(PWR_BTN_COM_PORT, PWR_BTN_COM_PIN) : GPIO_ResetBits(PWR_BTN_COM_PORT, PWR_BTN_COM_PIN)

//US_PWR_ID
#define US_PWR_ID_PORT            GPIOE
#define US_PWR_ID_PIN             GPIO_Pin_11
#define US_PWR_ID_1()             GPIO_SetBits(US_PWR_ID_PORT, US_PWR_ID_PIN)
#define US_PWR_ID_0()             GPIO_ResetBits(US_PWR_ID_PORT, US_PWR_ID_PIN)
//#define US_PWR_ID_IN()           {GPIOE->MODER = GPIOE->MODER & 0xFF3FFFFF;}
//#define US_PWR_ID_OUT()          {GPIOE->MODER = GPIOE->MODER & 0xFF7FFFFF; GPIOE->MODER = GPIOE->MODER | 0x00400000;}
#define US_PWR_ID_READ()          GPIO_ReadInputDataBit(US_PWR_ID_PORT, US_PWR_ID_PIN)

//SUS_S4
#define SUS_S4_PORT               GPIOE
#define SUS_S4_PIN                GPIO_Pin_12
#define SUS_S4_CHK()              GPIO_ReadInputDataBit(SUS_S4_PORT, SUS_S4_PIN)

//SUS_S3
#define SUS_S3_PORT               GPIOE
#define SUS_S3_PIN                GPIO_Pin_13
#define SUS_S3_CHK()              GPIO_ReadInputDataBit(SUS_S3_PORT, SUS_S3_PIN)

//BAT1_SMBUS_D
#define BAT1_SMBUS_D_PORT         GPIOF
#define BAT1_SMBUS_D_PIN          GPIO_Pin_0
#define BAT1_SMBUS_D_1()          GPIO_SetBits(BAT1_SMBUS_D_PORT, BAT1_SMBUS_D_PIN)
#define BAT1_SMBUS_D_0()          GPIO_ResetBits(BAT1_SMBUS_D_PORT, BAT1_SMBUS_D_PIN)
#define BAT1_SMBUS_D_READ()       GPIO_ReadInputDataBit(BAT1_SMBUS_D_PORT, BAT1_SMBUS_D_PIN)

//BAT1_SMBUS_C 
#define BAT1_SMBUS_C_PORT         GPIOF
#define BAT1_SMBUS_C_PIN          GPIO_Pin_1
#define BAT1_SMBUS_C_1()          GPIO_SetBits(BAT1_SMBUS_C_PORT, BAT1_SMBUS_C_PIN)
#define BAT1_SMBUS_C_0()          GPIO_ResetBits(BAT1_SMBUS_C_PORT, BAT1_SMBUS_C_PIN)

//PWR_OK_COM
#define PWR_OK_COM_PORT           GPIOF
#define PWR_OK_COM_PIN            GPIO_Pin_2
#define PWR_OK_COM(x)             x ? GPIO_SetBits(PWR_OK_COM_PORT, PWR_OK_COM_PIN) : GPIO_ResetBits(PWR_OK_COM_PORT, PWR_OK_COM_PIN)

//T_A2V25_ADC   
#define T_A2V25_PORT              GPIOF
#define T_A2V25_PIN               GPIO_Pin_3

//T_A3V75_ADC   
#define T_A3V75_PORT              GPIOF
#define T_A3V75_PIN               GPIO_Pin_4

//T_AP5V5_1_ADC   
#define T_AP5V5_1_PORT            GPIOF
#define T_AP5V5_1_PIN             GPIO_Pin_5

//T_AP12V_ADC   
#define T_AP12V_PORT              GPIOF
#define T_AP12V_PIN               GPIO_Pin_6

//T_AN5V5_ADC   
#define T_AN5V5_PORT              GPIOF
#define T_AN5V5_PIN               GPIO_Pin_7
  
//T_AN12V_ADC   
#define T_AN12V_PORT              GPIOF
#define T_AN12V_PIN               GPIO_Pin_8

//T_D0V95_ADC   
#define T_D0V95_PORT              GPIOF
#define T_D0V95_PIN               GPIO_Pin_9

//T_D1V45_ADC
#define T_D1V45_PORT              GPIOF
#define T_D1V45_PIN               GPIO_Pin_10

//AFE_EN1
#define AFE_EN1_PORT              GPIOF
#define AFE_EN1_PIN               GPIO_Pin_11
#define AFE_EN1(x)                x ? GPIO_SetBits(AFE_EN1_PORT, AFE_EN1_PIN) : GPIO_ResetBits(AFE_EN1_PORT, AFE_EN1_PIN)

//AFE_EN2
#define AFE_EN2_PORT              GPIOF
#define AFE_EN2_PIN               GPIO_Pin_12
#define AFE_EN2(x)                x ? GPIO_SetBits(AFE_EN2_PORT, AFE_EN2_PIN) : GPIO_ResetBits(AFE_EN2_PORT, AFE_EN2_PIN)

//EN_FPGA_01
#define EN_FPGA_01_PORT           GPIOF
#define EN_FPGA_01_PIN            GPIO_Pin_13
#define EN_FPGA_01(x)             x ? GPIO_SetBits(EN_FPGA_01_PORT, EN_FPGA_01_PIN) : GPIO_ResetBits(EN_FPGA_01_PORT, EN_FPGA_01_PIN)

//EN_FPGA_02
#define EN_FPGA_02_PORT           GPIOF
#define EN_FPGA_02_PIN            GPIO_Pin_14
#define EN_FPGA_02(x)             x ? GPIO_SetBits(EN_FPGA_02_PORT, EN_FPGA_02_PIN) : GPIO_ResetBits(EN_FPGA_02_PORT, EN_FPGA_02_PIN)

//EN_FRONT
#define EN_FRONT_PORT             GPIOF
#define EN_FRONT_PIN              GPIO_Pin_15
#define EN_FRONT(x)               x ? GPIO_SetBits(EN_FRONT_PORT, EN_FRONT_PIN) : GPIO_ResetBits(EN_FRONT_PORT, EN_FRONT_PIN)

//BAT1_C_SHIFT
#define BAT1_C_SHIFT_PORT         GPIOG
#define BAT1_C_SHIFT_PIN          GPIO_Pin_0
#define BAT1_C_SHIFT_EN(x)        x ? GPIO_SetBits(BAT1_C_SHIFT_PORT, BAT1_C_SHIFT_PIN) : GPIO_ResetBits(BAT1_C_SHIFT_PORT, BAT1_C_SHIFT_PIN)

//BAT2_C_SHIFT
#define BAT2_C_SHIFT_PORT         GPIOG
#define BAT2_C_SHIFT_PIN          GPIO_Pin_1
#define BAT2_C_SHIFT_EN(x)        x ? GPIO_SetBits(BAT2_C_SHIFT_PORT, BAT2_C_SHIFT_PIN) : GPIO_ResetBits(BAT2_C_SHIFT_PORT, BAT2_C_SHIFT_PIN)

//CHARGE_LED_O
#define CHARGE_LED_O_PORT         GPIOG
#define CHARGE_LED_O_PIN          GPIO_Pin_2
#define CHARGE_LED_O_EN(x)        x ? GPIO_SetBits(CHARGE_LED_O_PORT, CHARGE_LED_O_PIN) : GPIO_ResetBits(CHARGE_LED_O_PORT, CHARGE_LED_O_PIN)

//CHARGE_LED_G
#define CHARGE_LED_G_PORT         GPIOG 
#define CHARGE_LED_G_PIN          GPIO_Pin_3
#define CHARGE_LED_G_EN(x)        x ? GPIO_SetBits(CHARGE_LED_G_PORT, CHARGE_LED_G_PIN) : GPIO_ResetBits(CHARGE_LED_G_PORT, CHARGE_LED_G_PIN)

//SLEEP_LED_C
#define SLEEP_LED_C_PORT          GPIOG
#define SLEEP_LED_C_PIN           GPIO_Pin_4
#define SLEEP_LED_EN(x)           x ? GPIO_SetBits(SLEEP_LED_C_PORT, SLEEP_LED_C_PIN) : GPIO_ResetBits(SLEEP_LED_C_PORT, SLEEP_LED_C_PIN)

//AUDIO_MUTE
#define AUDIO_MUTE_PORT          GPIOG
#define AUDIO_MUTE_PIN           GPIO_Pin_6
#define AUDIO_MUTE_EN(x)         x ? GPIO_SetBits(AUDIO_MUTE_PORT, AUDIO_MUTE_PIN) : GPIO_ResetBits(AUDIO_MUTE_PORT, AUDIO_MUTE_PIN)

//C_VNN2_VPP2
#define C_VPP2_VNN2_PORT          GPIOG
#define C_VPP2_VNN2_PIN           GPIO_Pin_14
#define CTL_VPP2_VNN2_EN(x)       x ? GPIO_ResetBits(C_VPP2_VNN2_PORT, C_VPP2_VNN2_PIN) : GPIO_SetBits(C_VPP2_VNN2_PORT, C_VPP2_VNN2_PIN)

//C_VNN1_VPP1
#define C_VPP1_VNN1_PORT          GPIOG
#define C_VPP1_VNN1_PIN           GPIO_Pin_15
#define CTL_VPP1_VNN1_EN(x)       x ? GPIO_ResetBits(C_VPP1_VNN1_PORT, C_VPP1_VNN1_PIN) : GPIO_SetBits(C_VPP1_VNN1_PORT, C_VPP1_VNN1_PIN)

void Gpio_Config(void);

#endif

