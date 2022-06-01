#include "app_fan.h"

extern System_MsgStruct SysMsg;

OS_TCB FanTaskTcb;

CPU_STK App_Fan_Task_Stk[APP_FAN_STK_SIZE];

void App_Fan_Task()
{
    OS_ERR err;

    while(1)
    {		
            Fan_Emc2305_Control();
            Fan_Speed_Read();
            OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_Fan_TaskCreate()
{
	OS_ERR err;
	
	OSTaskCreate((OS_TCB *			)&FanTaskTcb, 
                     (CPU_CHAR *		)"App_Fan_Task", 
                     (OS_TASK_PTR		)App_Fan_Task,
                     (void *			)0,
                     (OS_PRIO			)APP_FAN_TASK_PRIO,
                     (CPU_STK *			)&App_Fan_Task_Stk[0],
                     (CPU_STK_SIZE		)APP_FAN_STK_SIZE / 10,
                     (CPU_STK_SIZE		)APP_FAN_STK_SIZE,
                     (OS_MSG_QTY		)0,
                     (OS_TICK			)0,
                     (void *			)0,
                     (OS_OPT			)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                     (OS_ERR *			)&err);
}
