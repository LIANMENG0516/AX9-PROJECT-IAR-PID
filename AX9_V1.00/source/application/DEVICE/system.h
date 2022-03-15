#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "stm32f4xx.h"

#include "gouble.h"

#define PID_CTRL                0       //开启PID调节控制

#define SYSTEM_OFF              0
#define SYSTEM_ON               1
#define SYSTEM_SLEEP            2

#define USB_CHANNEL             1
#define ECCOM_CHANNEL           2
#define DEBUGCOM_CHANNEL        3

#define FirmwareVersion_H 0x90
#define FirmwareVersion_L 0x00

#define HardwareVersion_H 0x90
#define HardwareVersion_L 0x00

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

typedef struct
{    
    bool HvFlag;
    bool CwFlag;

    bool VolInit;               //高压初始化标志位, 开机完成后被置位, 程序检测此标志位进行高压部分的初始化
    bool VolMinitor;            //高压监控标志位
    
    bool AdjVolOpen;            //单次调压开启/关闭标志
    bool AdjVolSuccess;         //单次调压成功与否标志
    bool MinAdjVolOpen;         //微调开启/关闭标志
    
    bool TimeFlag;              //计时标志
    
    bool HV1NeedChange;         
    bool HV2NeedChange;
    
    #if PID_CTRL
    
    bool PidOpen;
    
    float OldOffSetVpp1;        //偏差
    float NowOffSetVpp1;
    uint16_t McuDacVpp1;
    
    float OldOffSetVnn1;        //偏差
    float NowOffSetVnn1;        //偏差
    uint16_t McuDacVnn1;

    #endif

    uint8_t  MinAdjVolCnt;      //微调次数
      
    uint16_t Time;              //调压时间
    uint16_t TimeOut;           //调压超时时间

    uint16_t T_VPP1;
    uint16_t T_VNN1;
    uint16_t T_VPP2;
    uint16_t T_VNN2;
    
    uint16_t Old_T_VPP1;
    uint16_t Old_T_VNN1;
    uint16_t Old_T_VPP2;
    uint16_t Old_T_VNN2;
    
    uint16_t MAX_VPP1;
    uint16_t MIN_VPP1;
    uint16_t MAX_VNN1;
    uint16_t MIN_VNN1;
    
    uint16_t MAX_VPP2;
    uint16_t MIN_VPP2;
    uint16_t MAX_VNN2;
    uint16_t MIN_VNN2;
    
    uint16_t T_McuDacHv1;
    uint16_t T_SpiDacHv1;
    uint16_t T_McuDacHv2;
    uint16_t T_SpiDacHv2;
    uint16_t T_SpiDacPcw;
    uint16_t T_SpiDacNcw;
    
    uint16_t P_McuDacHv1;
    uint16_t P_SpiDacHv1;
    uint16_t P_McuDacHv2;
    uint16_t P_SpiDacHv2;
    uint16_t P_SpiDacPcw;
    uint16_t P_SpiDacNcw;

    uint16_t R_VPP1;
    uint16_t R_VNN1;
    uint16_t R_VPP2;
    uint16_t R_VNN2;
    
    uint16_t R_AP12V;
    uint16_t R_AN12V;
    uint16_t R_AP5V5_1;
    uint16_t R_AP5V5_2;
    uint16_t R_AN5V5;
    uint16_t R_A3V75;
    uint16_t R_A2V25;
    uint16_t R_D1V45;
    uint16_t R_D5V;
    uint16_t R_D0V95;
       
    uint16_t R_IADP;
}Ad_VolStruct;

typedef struct
{    
    uint8_t FPGA;
    uint8_t MCU;
}SysTemper;

typedef struct
{    
    uint16_t Rpm1;
    uint16_t Rpm2;
    uint16_t Rpm3;
    uint16_t Rpm4;
    uint16_t Rpm5;
}FanStrc;

typedef struct
{    
    bool            Timeout;
    bool            HV_Send;
    bool            CW_Send;
    bool            Firmware_Send;
    bool            CompileInfo_Send;
    bool            Voltage_Send;
    bool            FanInfo_Send;
    bool            PwrInfo_Send;
    bool            Vpp1Vnn1En_Send;
    bool            Vpp1Vnn1Dis_Send;
    bool            Vpp2Vnn2En_Send;
    bool            Vpp2Vnn2Dis_Send;
    bool            EcInfo_Send;
    bool            WriteBoardOk_Send;      //写响应
    bool            BoardInfo_Send;         //读响应
    uint8_t         Channel;                //命令通道, 是指程序接收到的命令从USB、ECCOM、DEBUGCOM哪个通道进入
}Command_Deal;

typedef struct
{    
    bool            Ac_Insert;
    bool            Bat1_Insert;
    bool            Bat2_Insert;
    uint8_t         Bat1_Power;             //电池电量
    uint8_t         Bat2_Power;             //电池电量
    uint8_t         Bat1_Tempature;         //电池温度
    uint8_t         Bat2_Tempature;         //电池温度
    uint8_t         Bat1_State;             //电池故障标志
    uint8_t         Bat2_State;             //电池故障标志
    
}PwrInfoStruct;

typedef struct
{
    Ad_VolStruct    AdjVol;
    SysTemper       Temperature;
    FanStrc         Fan;
    Command_Deal    Cmd;
    PwrInfoStruct   PwrInfo;
    uint8_t         SystemState;
    bool            KeyState;
    bool            PowerOnReq;
    bool            ShutDownReq;
    bool            System_S3_Change;
    bool            System_S4_Change;
    bool            S3_State;
    bool            S4_State;
}System_MsgStruct;

void Delay_Nop(uint16_t count);

bool System_PwrKey_Minitor(void);

bool System_S3_State_Minitor(void);

void SystemStateInit(void);

#endif
