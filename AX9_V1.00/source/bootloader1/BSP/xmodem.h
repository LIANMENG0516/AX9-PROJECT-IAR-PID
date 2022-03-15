#ifndef __XMODEM_H_
#define __XMODEM_H_

#include "stm32f4xx.h"

#define TRANSMIT 'C'    

#define UPDAT_RUN       0xA0
#define UPDAT_ERR       0xA1
#define UPDAT_END       0xA2
#define UPDAT_FINISH    0xA3

#define SOH             0x01
#define STX             0x02
#define EOT             0x04
#define ACK             0x06
#define NAK             0x15

#define BUFSIZE         1024

#define SCB_AIRCR       (*(volatile unsigned long *)0xE000ED0C)                 //Reset control Address Register
#define SCB_RESET_VALUE 0x05FA0004                                              //reset value ,write to SCB_AIRCR  can reset cpu

typedef struct
{
    uint8_t Header;
    uint8_t Pack_Fth;
    uint8_t Pack_Sth;
    uint8_t Buf[BUFSIZE];
    uint8_t Crc_Msb;
    uint8_t Crc_Lsb;
}XmodemStruct;

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

void Xmodm_Updata(void);
void Reset_Cpu(void);

#endif



