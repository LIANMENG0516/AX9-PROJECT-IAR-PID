#ifndef __FALSH_H_
#define __FALSH_H_

#include "stm32f4xx.h"

#define STM_PAGE_SIZE  0x20000                          //128K  

#define BOOT_AREA_ADDR 0x08000000                        //BOOT区为FALSH的0~4扇区共128K
#define APPL_AREA_ADDR 0x08020000                       //APP区划分为FALSH的5~9扇区共640K 
#define SIGN_AREA_ADDR 0x080C0000                       //SIGN区为FLASH的10~11扇区共256K

void JumpToApp(void);
void Flash_Program(uint32_t Address, uint8_t *Data, uint16_t DataLen);

#endif


