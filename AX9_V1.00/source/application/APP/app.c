#include "app.h"

#include "gouble.h"

OS_TCB StartTaskTcb;													//任务控制块

OS_TMR			Sys_StateChk_Tmr;
	
CPU_STK App_Start_Task_Stk[APP_START_STK_SIZE];										//任务堆栈空间

void App_Start_Task()
{   
    OS_ERR err;
    CPU_SR_ALLOC();

    CPU_Init();
    
    #if OS_CFG_STAT_TASK_EN > 0u
       OSStatTaskCPUUsageInit(&err);  											//统计任务                
    #endif
    
    #ifdef CPU_CFG_INT_DIS_MEAS_EN											//如果使能了测量中断关闭时间
        CPU_IntDisMeasMaxCurReset();	
    #endif
    
    #if	OS_CFG_SCHED_ROUND_ROBIN_EN  											//当使用时间片轮转的时候 
        OSSchedRoundRobinCfg(DEF_ENABLED, 1, &err); 								        //使能时间片轮转调度功能,时间片长度为1个系统时钟节拍，既1*5=5ms 
    #endif	
    
    OS_CRITICAL_ENTER();												//进入临界区  

    App_Led_TaskCreate();
    App_Usb_TaskCreate();
    App_ComEc_TaskCreate();
    App_ComDebug_TaskCreate();
    App_Fan_TaskCreate();
    App_SysOnOff_TaskCreate();
    App_PwrManager_TaskCreate();
    App_Temperature_TaskCreate();
    App_AdjVol_TaskCreate();
    
    OSTmrCreate(&Sys_StateChk_Tmr, "Sys_StateChk_Tmr", 1, 1, OS_OPT_TMR_PERIODIC, cb_Sys_StateChk_Tmr, 0, &err);	//创建定时器10ms	
    OSTmrStart(&Sys_StateChk_Tmr, &err);

    OSTaskSuspend(&StartTaskTcb, &err);

    OS_CRITICAL_EXIT();													//退出临界区
}

void App_Start_Task_Create()
{
    OS_ERR err;
    
    OSTaskCreate((OS_TCB *		)&StartTaskTcb,								        //任务控制块 
                 (CPU_CHAR *		)"App_Start_Task", 							        //任务名称
                 (OS_TASK_PTR		)App_Start_Task,							        //函数名称
                 (void *		)0,									        //传递给任务函数的参数
                 (OS_PRIO		)APP_START_TASK_PRIO,							        //任务优先级
                 (CPU_STK *		)&App_Start_Task_Stk[0],						        //任务堆栈基地址
                 (CPU_STK_SIZE		)APP_START_STK_SIZE / 10,						        //任务堆栈深度限位
                 (CPU_STK_SIZE		)APP_START_STK_SIZE,							        //任务堆栈大小
                 (OS_MSG_QTY		)0,									        //任务内部消息队列能够接收的最大消息数目,为0时禁止接收消息
                 (OS_TICK		)0,									        //当使能时间片轮转时的时间片长度，为0时为默认长度
                 (void *		)0,									        //用户补充的存储区
                 (OS_OPT		)OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,		                        //任务选项
                 (OS_ERR *		)&err);									        //存放该函数错误时的返回值
}






