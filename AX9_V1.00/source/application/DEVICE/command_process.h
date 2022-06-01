#ifndef __COMMAND_PROCESS_H
#define __COMMAND_PROCESS_H

#include "gouble.h"

typedef struct 
{
	uint8_t		Header;
	uint8_t		Id;
	uint8_t		Cid;
	uint8_t 	Len;
	uint8_t 	*Data;
	uint8_t		Chk;
	uint8_t 	Tail;
}CmdFrameStr;

#define STM_PAGE_SIZE  0x20000                          //128K  

#define BOOT_AREA_ADDR 0x08000000                       //BOOT区为FALSH的0~4扇区共128K
#define APPL_AREA_ADDR 0x08020000                       //APP区划分为FALSH的5~9扇区共640K 
#define SIGN_AREA_ADDR 0x080C0000                       //SIGN区为FLASH的10~11扇区共256K

#define RESPONSE_OK                             1
#define RESPONSE_FAIL                           0

#define CMD_FIRMWARE_VERSION                    0x01
#define CMD_COMPILE_INFO                        0x02
#define CMD_RDHARDWARE_VERSION                  0x03            
#define CMD_WDHARDWARE_VERSION                  0x04            
#define CMD_SLEEP_EN                            0x05
#define CMS_WEAK_UP                             0x06
#define CMD_RESTART                             0x07
#define CMD_UPGRADE                             0x08
#define CMD_POWER_INFO                          0x09          
#define CMD_FAN_INFO                            0x0A 
#define CMD_RDTEMPEATURE_INFO                   0x0B 
#define CMD_WDTEMPEATURE_INFO                   0x0C 
#define CMD_RDSTATIC_VOLTAGE                    0x0D           
#define CMD_RDADJUST_VOLTAGE                    0x0E            
#define CMD_VPP1VNN1_EN                         0x0F                
#define CMD_VPP1VNN1_DIS                        0x10             
#define CMD_VPP2VNN2_EN                         0x11              
#define CMD_VPP2VNN2_DIS                        0x12                 
#define CMD_ADJUSTVOLTAGE_HV                    0x13
#define CMD_ADJUSTVOLTAGE_CW                    0x14

#define CMD_EC_COMMUNICATE                      0xA0

#define CMD_INVALID                             0xF0                            //非法命令
#define TIMEOUT                                 0xF1                            //调压超时

#define CMS_DEBUGSWITCH                         0xFF                            //调压信息输出开关

#define SCB_AIRCR       (*(volatile unsigned long *)0xE000ED0C)                 //Reset control Address Register
#define SCB_RESET_VALUE 0x05FA0004                                              //reset value ,write to SCB_AIRCR  can reset cpu

void FrameCmdPackage(uint8_t *pBuf);
void Send_CmdPackage(DMA_Stream_TypeDef* DMAy_Streamx);
void Cmd_Process(void);

ErrorStatus ReceiveFrameAnalysis(uint8_t *pData, uint8_t DataLen);

uint8_t DebugReceiveFrameAnalysis(char *pData);

uint8_t Deal_Compare(char *pData, uint8_t DataLen);

void Calc_TarVol_AlowRange(void);

void Update_EcInfo(void);

void Reset_Cpu(void);

#endif











