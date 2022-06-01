#include "board.h"

__ALIGN_BEGIN USB_OTG_CORE_HANDLE USB_OTG_dev __ALIGN_END;

void PowerOn_Sequence()
{
    PWR_BTN_COM(0);
    delay_ms(200);
    PWR_BTN_COM(1);
    
    PBUS_ON(1);
    PWR_CTL(1);
    delay_ms(10);
    CTL_P12V_EN(1);
    CTL_P5V5_1_EN(1);
    delay_ms(20);
    CTL_N12V_5V5_EN(1);
    CTL_P5V5_2_EN(1);
    CTL_P3V75_EN(1);
    CTL_P2V25_EN(1);
    delay_ms(20);
    CTL_D0V95_EN(1);
    delay_ms(15);
    CTL_VDD_P5V_EN(1);
    CTL_D1V45_EN(1);
    delay_ms(15);
    EN_FRONT(1);
    EN_FPGA_01(1); 
    delay_ms(10);
    AFE_EN1(1);
    delay_ms(15);
    EN_FPGA_02(1);
    AFE_EN2(1);
    delay_ms(20);
    PWR_OK_COM(1);
}

void PowerDown_Sequence()
{
    PWR_OK_COM(0);

    delay_ms(5);
    AFE_EN2(0);
    EN_FPGA_02(0);
    delay_ms(50);
    AFE_EN1(0);
    EN_FPGA_01(0);
    EN_FRONT(0);
    delay_ms(50);
    CTL_D1V45_EN(0);
    CTL_VDD_P5V_EN(0);
    CTL_D0V95_EN(0);
    CTL_P2V25_EN(0);
    CTL_P3V75_EN(0);
    delay_ms(20);
    CTL_P5V5_2_EN(0);
    CTL_P5V5_1_EN(0);
    CTL_N12V_5V5_EN(0);
    CTL_P12V_EN(0);
    delay_ms(10);
    
    Reset_Cpu();
}

void Board_Bsp_Init()
{
    Gpio_Config();
    
    PowerOn_Sequence();
    
    USBD_Init(&USB_OTG_dev, USB_OTG_FS_CORE_ID, &USR_desc, &USBD_CDC_cb, &USR_cb);
    USB_CTRL_EN(1);  
    
    SysTick_Iint();
    
    Fan_Emc2305_Init();
    
    Usart_Init(DEBUG_COM, 115200);
    
    
}



