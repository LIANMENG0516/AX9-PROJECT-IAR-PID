#ifndef __APP_TIMER_H
#define __APP_TIMER_H

#include "gouble.h"

#define ADJTIMEOUT  3000  //调压超时时间单位Ms

void cb_Sys_StateChk_Tmr(void *p_tmr, void *p_arg);

#endif
