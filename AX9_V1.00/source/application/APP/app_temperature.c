#include "app_temperature.h"

extern System_MsgStruct SysMsg;

OS_TCB TemperatureTaskTcb;

CPU_STK App_Temperature_Task_Stk[APP_TEMPERATURE_STK_SIZE];

void App_Temperature_Task()
{
    OS_ERR err;

    while(1)
    {		
        Adc1_GetMcuInternalTemperature();                                       //获取MCU温度
        Bat1_TempatureRead();                                                   //获取电池1温度
        Bat2_TempatureRead();                                                   //获取电池2温度

        OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_Temperature_TaskCreate()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *		)&TemperatureTaskTcb, 
                 (CPU_CHAR *		)"App_Temperature_Task", 
                 (OS_TASK_PTR		)App_Temperature_Task,
                 (void *		)0,
                 (OS_PRIO		)APP_TEMPERATURE_TASK_PRIO,
                 (CPU_STK *		)&App_Temperature_Task_Stk[0],
                 (CPU_STK_SIZE		)APP_TEMPERATURE_STK_SIZE / 10,
                 (CPU_STK_SIZE		)APP_TEMPERATURE_STK_SIZE,
                 (OS_MSG_QTY		)0,
                 (OS_TICK		)0,
                 (void *		)0,
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                 (OS_ERR *		)&err);
}
