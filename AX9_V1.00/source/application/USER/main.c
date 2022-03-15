#include "stm32f4xx.h"

#include "gouble.h"

//HCLK  168MHz
//AHB   168MHz
//APB1  42MHz
//APB2  84MHz

int main()
{
    OS_ERR err;
    CPU_SR_ALLOC();

    Board_Bsp_Init();
    SystemStateInit();

    OSInit(&err);
    OS_CRITICAL_ENTER();

    DEBUG_PRINTF(1, "Start The Task Create \r\n");  

    App_Start_Task_Create();

    OS_CRITICAL_EXIT();	
    OSStart(&err);
}
