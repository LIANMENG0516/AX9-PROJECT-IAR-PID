#ifndef __BOARD_H
#define __BOARD_H

#include "stm32f4xx.h"

#include "gpio.h"
#include "usart.h"
#include "flash.h"
#include "xmodem.h"
#include "emc2305.h"
#include "systick.h"

#include "string.h"

#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

void Board_Bsp_Init(void);
void PowerOn_Sequence(void);
void PowerDown_Sequence(void);

#endif
