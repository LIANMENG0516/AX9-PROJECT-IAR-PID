#include "app_adc.h"

extern System_MsgStruct SysMsg;

OS_TCB AdcTaskTcb;

CPU_STK App_Adc_Task_Stk[APP_ADC_STK_SIZE];

void App_Adc_Task()
{
    OS_ERR err;

    while(1)
    {		
        Adc3_GetFixVoltage();
        Adc1_GetOverCurrentVoltage();
        OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_Adc_TaskCreate()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *		)&AdcTaskTcb, 
                 (CPU_CHAR *		)"App_Adc_Task", 
                 (OS_TASK_PTR		)App_Adc_Task,
                 (void *		)0,
                 (OS_PRIO		)APP_ADC_TASK_PRIO,
                 (CPU_STK *		)&App_Adc_Task_Stk[0],
                 (CPU_STK_SIZE		)APP_ADC_STK_SIZE / 10,
                 (CPU_STK_SIZE		)APP_ADC_STK_SIZE,
                 (OS_MSG_QTY		)0,
                 (OS_TICK		)0,
                 (void *		)0,
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                 (OS_ERR *		)&err);
}
