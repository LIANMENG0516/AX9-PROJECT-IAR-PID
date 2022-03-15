#ifndef __GOUBLE_H
#define __GOUBLE_H

#include "string.h"

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "gpio.h"
#include "nvic.h"
#include "systick.h"
#include "usart.h"
#include "timer.h"
#include "dma.h"
#include "spi.h"
#include "dac.h"
#include "adc.h"

#include "bat.h"
#include "power.h"
#include "board.h"
#include "ds2431.h"
#include "system.h"
#include "tmp468.h"
#include "adt7302.h"
#include "emc2305.h"
#include "tlv5626cd.h"
#include "adjustvoltage.h"
#include "command_process.h"

#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

#include "includes.h"
#include "os_cfg_app.h"
#include "os.h"

#include "app.h"
#include "app_led.h"
#include "app_adc.h"
#include "app_fan.h"
#include "app_usb.h"
#include "app_com.h"
#include "app_timer.h"
#include "app_adjvol.h"
#include "app_sysonoff.h"
#include "app_comdebug.h"
#include "app_pwrmanager.h"
#include "app_temperature.h"


#define USE_UCOSIII

#define USE_DEBUG                           1       //调试总开关
#define DEBUG_COMMAND                       1       //命令调试开关
#define DEBUG_STRING                        0       //字符串调试开关     

#define APP_ADJVOL_TASK_PRIO                20
#define APP_ADJVOL_STK_SIZE                 1024

#define APP_FAN_TASK_PRIO                   24
#define APP_FAN_STK_SIZE                    256

#define APP_SYSONOFF_TASK_PRIO              25
#define APP_SYSONOFF_STK_SIZE               512

#define APP_TEMPERATURE_TASK_PRIO           26
#define APP_TEMPERATURE_STK_SIZE            256

#define APP_ADC_TASK_PRIO                   27
#define APP_ADC_STK_SIZE                    256

#define APP_PWRMANAGER_TASK_PRIO            28
#define APP_PWRMANAGER_STK_SIZE             256

#define APP_USB_TASK_PRIO                   35
#define APP_USB_STK_SIZE                    256

#define APP_COMEC_TASK_PRIO                 36
#define APP_COMEC_STK_SIZE                  256

#define APP_COMDEBUG_TASK_PRIO              37
#define APP_COMDEBUG_STK_SIZE               256

#define APP_LED_TASK_PRIO 		    38
#define APP_LED_STK_SIZE                    256

#define APP_START_TASK_PRIO                 40		//优先级
#define APP_START_STK_SIZE                  256		//堆栈大小



#endif

















