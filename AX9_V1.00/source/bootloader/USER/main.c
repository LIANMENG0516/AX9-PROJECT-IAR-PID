#include "stm32f4xx.h"

#include "board.h"


#define SYSTEM_ON  TRUE
#define SYSTEM_OFF FALSE

bool SysState = SYSTEM_ON;

extern bool XmodemIapOk;
extern bool XmodemStart;
extern bool XmodemRxDat;
extern uint32_t addroffset;

extern uint16_t Rx_Len;
extern uint32_t receive_count;


void PowerKey_Process()
{
    static uint16_t startCnt = 0;
    static bool stateNow = FALSE;
            
    stateNow = PWR_KEY_CHK() ? TRUE : FALSE;
    
    if(stateNow == TRUE)
    {
        while(++startCnt)
        {
            if(SysState == SYSTEM_OFF && startCnt >= 100 && startCnt < 500)     //短按开机
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
                delay_ms(3000);
                PWR_OK_COM(1);
                
                SysState = SYSTEM_ON;
                
                Rx_Len = 0;
                receive_count = 0;
                XmodemIapOk = FALSE;
                XmodemStart = FALSE;
                XmodemRxDat = FALSE;
                
                while(PWR_KEY_CHK());  
                break;
            }
            if(startCnt > 500)                                                  //长按关机
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
                
                SysState = SYSTEM_OFF;
                
                Rx_Len = 0;
                receive_count = 0;
                addroffset = 0;
                XmodemIapOk = FALSE;
                XmodemStart = FALSE;
                XmodemRxDat = FALSE;
                
                
                while(PWR_KEY_CHK()); 
                break;
            }
            
            delay_ms(10);
        }
    }
    if(stateNow == FALSE)
    {
        startCnt = 0;
    }
}








int main()
{
    if(*(__IO uint32_t *)SIGN_AREA_ADDR != 0xFFFFFFFF)
    {
        Board_Bsp_Init();
        
        FLASH_Unlock();
        FLASH_EraseSector(FLASH_Sector_5, VoltageRange_3);
        FLASH_EraseSector(FLASH_Sector_6, VoltageRange_3);
        FLASH_EraseSector(FLASH_Sector_7, VoltageRange_3);
        FLASH_EraseSector(FLASH_Sector_8, VoltageRange_3);
        FLASH_EraseSector(FLASH_Sector_9, VoltageRange_3);
        FLASH_Lock();

        printf("Run To Iap \r\n");

        while(1)
        {
            Xmodm_Updata();

            PowerKey_Process();
            
            if(XmodemIapOk)
            {
                if(FALSE == (bool)SUS_S3_CHK() && FALSE == (bool)SUS_S4_CHK())
                {
                    PowerDown_Sequence();
                }
            }
        }
    }
    else
    {
        JumpToApp();
    }
  
    while(1);
}












