#include "app_comdebug.h"

extern System_MsgStruct SysMsg;

extern CmdFrameStr SenFrameCmd;

extern Com_Buffer DebugComRX;
extern Com_Buffer DebugComTX;

OS_TCB ComDebugTaskTcb;

CPU_STK App_ComDebug_Task_Stk[APP_COMDEBUG_STK_SIZE];

void App_ComDebug_Task()
{
    OS_ERR err;

    while(1)
    {		   
        if((DebugComRX.Len != 0) && (ReceiveFrameAnalysis(&DebugComRX.Data[0], DebugComRX.Len) == SUCCESS))   //格式化并解析串口数据
        {
            CPU_SR_ALLOC();
            OS_CRITICAL_ENTER();						//进入临界区, 禁止任务调度
            SysMsg.Cmd.Channel = DEBUGCOM_CHANNEL;
            memset(DebugComRX.Data, 0, DebugComRX.Len);
            DebugComRX.Len = 0;
            Cmd_Process(); 
            OS_CRITICAL_EXIT();							//退出临界区, 允许任务调度
        }

        /*
        if((DebugComRX.Len != 0) && (Deal_Compare((char *)DebugComRX.Data, DebugComRX.Len) != 0))
        {
            OS_CRITICAL_EXIT();							//退出临界区, 允许任务调度
            SysMsg.Cmd.Channel = DEBUGCOM_CHANNEL;
            memset(DebugComRX.Data, 0, DebugComRX.Len);
            DebugComRX.Len = 0;
            OS_CRITICAL_EXIT();							//退出临界区, 允许任务调度
        }
        */
        
        OSTimeDlyHMSM(0, 0, 0, 5, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_ComDebug_TaskCreate()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *              )&ComDebugTaskTcb, 
                 (CPU_CHAR *		)"App_ComDebug_Task", 
                 (OS_TASK_PTR		)App_ComDebug_Task,
                 (void *		)0,
                 (OS_PRIO		)APP_COMDEBUG_TASK_PRIO,
                 (CPU_STK *		)&App_ComDebug_Task_Stk[0],
                 (CPU_STK_SIZE		)APP_COMDEBUG_STK_SIZE / 10,
                 (CPU_STK_SIZE		)APP_COMDEBUG_STK_SIZE,
                 (OS_MSG_QTY		)0,
                 (OS_TICK		)0,
                 (void *		)0,
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                 (OS_ERR *		)&err);
}
