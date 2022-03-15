#include "app_com.h"

extern System_MsgStruct SysMsg;

extern CmdFrameStr SenFrameCmd;

extern Com_Buffer CommuComRX;
extern Com_Buffer CommuComTX;

extern uint8_t Ec_Info[];


OS_TCB ComEcTaskTcb;

CPU_STK App_ComEc_Task_Stk[APP_COMEC_STK_SIZE];

void App_ComEc_Task()
{
    OS_ERR err;

    while(1)
    {		
        if((CommuComRX.Len != 0) && (ReceiveFrameAnalysis(&CommuComRX.Data[0], CommuComRX.Len) == SUCCESS))   //格式化并解析串口数据
        {
            CPU_SR_ALLOC();
            OS_CRITICAL_ENTER();						//进入临界区, 禁止任务调度
            
            SysMsg.Cmd.Channel = ECCOM_CHANNEL;
            memset(CommuComRX.Data, 0, CommuComRX.Len);
            CommuComRX.Len = 0;
            Cmd_Process();                                                      //命令处理   
            
            OS_CRITICAL_EXIT();							//退出临界区, 允许任务调度
        }       
        
        OSTimeDlyHMSM(0, 0, 0, 5, OS_OPT_TIME_PERIODIC, &err);
    }
}

void App_ComEc_TaskCreate()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *              )&ComEcTaskTcb, 
                 (CPU_CHAR *		)"App_ComEc_Task", 
                 (OS_TASK_PTR		)App_ComEc_Task,
                 (void *		)0,
                 (OS_PRIO		)APP_COMEC_TASK_PRIO,
                 (CPU_STK *		)&App_ComEc_Task_Stk[0],
                 (CPU_STK_SIZE		)APP_COMEC_STK_SIZE / 10,
                 (CPU_STK_SIZE		)APP_COMEC_STK_SIZE,
                 (OS_MSG_QTY		)0,
                 (OS_TICK		)0,
                 (void *		)0,
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
                 (OS_ERR *		)&err);
}





