#include "flash.h"

uint32_t JumpAddress;
typedef void (*pFunction)(void);
pFunction Jump_To_Application;


void JumpToApp()
{
    if(((*(__IO uint32_t *)APPL_AREA_ADDR) & 0x2FFE0000) == 0x20000000)         //检查栈顶地址是否合法
    {
        JumpAddress = *(__IO uint32_t*)(APPL_AREA_ADDR + 4);	
        Jump_To_Application = (pFunction)JumpAddress;
        __set_MSP(*(__IO uint32_t*)APPL_AREA_ADDR);				//初始化用户程序堆栈指针
        Jump_To_Application();							
    }
}

void Flash_Program(uint32_t Address, uint8_t *Data, uint16_t DataLen)
{
    uint8_t temp1, temp2;
    uint16_t tempData;
       
    FLASH_Unlock();
    for(uint16_t i=0; i<DataLen; i+=2)
    {
        temp1 = *Data++;
        temp2 = *Data++;
        tempData = (temp2 << 8) + temp1;

        if(tempData != 0x1A1A)
        {
            FLASH_ProgramHalfWord(Address, tempData);
        }

        Address += 2;
    }
    FLASH_Lock();
}
