#ifndef __BOARD_H
#define __BOARD_H

#include "systick.h"


#include "includes.h"
#include "os_cfg_app.h"
#include "os.h"

#define USE_UCOSIII

//#define DEBUG_PRINTF(x, format, ...)  if(x){printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__);}

#define DEBUG_PRINTF(x, format, ...)  if(x){printf(format, ##__VA_ARGS__);}

void Board_Bsp_Init(void);

#endif
