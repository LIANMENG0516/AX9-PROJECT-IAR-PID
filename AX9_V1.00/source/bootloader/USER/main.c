#include "stm32f4xx.h"

#include "board.h"

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
            
            if(FALSE == (bool)SUS_S3_CHK() && FALSE == (bool)SUS_S4_CHK())
            {
                PowerDown_Sequence();
            }
        }
    }
    else
    {
        JumpToApp();
    }
    
    while(1);
}












