#include "app_timer.h"

extern System_MsgStruct SysMsg;

void cb_Sys_StateChk_Tmr(void *p_tmr, void *p_arg)
{    
    Update_EcInfo();

    Adc3_GetFixVoltage();
    
    Adc3_GetAdjVoltage();
}












