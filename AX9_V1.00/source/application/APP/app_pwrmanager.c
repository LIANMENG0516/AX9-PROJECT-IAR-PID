#include "app_pwrmanager.h"

extern System_MsgStruct SysMsg;

OS_TCB PwrManagerTcb;

CPU_STK App_PwrManager_Task_Stk[APP_PWRMANAGER_STK_SIZE];

void App_PwrManager_Task()
{
    OS_ERR err;

    while(1)
    {			
        Battery_Power_Read();
        OSTimeDlyHMSM(0, 0, 0, 500, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_PwrManager_TaskCreate()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *		)&PwrManagerTcb, 
                 (CPU_CHAR *		)"App_PwrManager_Task", 
                 (OS_TASK_PTR		)App_PwrManager_Task,
                 (void *		)0,
                 (OS_PRIO		)APP_PWRMANAGER_TASK_PRIO,
                 (CPU_STK *		)&App_PwrManager_Task_Stk[0],
                 (CPU_STK_SIZE		)APP_PWRMANAGER_STK_SIZE / 10,
                 (CPU_STK_SIZE		)APP_PWRMANAGER_STK_SIZE,
                 (OS_MSG_QTY		)0,
                 (OS_TICK		)0,
                 (void *		)0,
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                 (OS_ERR *		)&err);
}



