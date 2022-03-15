#include "system.h"

System_MsgStruct SysMsg = {
  
    .AdjVol.HvFlag                      = FALSE,
    .AdjVol.CwFlag                      = FALSE,
    
    .AdjVol.VolInit                     = FALSE,
    .AdjVol.VolMinitor                  = FALSE,
    
    .AdjVol.AdjVolOpen                  = FALSE,
    .AdjVol.MinAdjVolOpen               = FALSE, 
    
    .AdjVol.TimeFlag                    = FALSE,
    
    .AdjVol.HV1NeedChange               = FALSE,
    .AdjVol.HV2NeedChange               = FALSE,    

    #if PID_CTRL
    
    .AdjVol.PidOpen                     = FALSE,
    
    .AdjVol.OldOffSetVpp1               = 0.0, 
    .AdjVol.NowOffSetVpp1               = 0.0,
    .AdjVol.McuDacVpp1                  = VPP1_DAC_CLOSE,
    
    .AdjVol.OldOffSetVnn1               = 0.0, 
    .AdjVol.NowOffSetVnn1               = 0.0,    
    .AdjVol.McuDacVnn1                  = VNN1_DAC_CLOSE,
    
    #endif    
    
    .AdjVol.MinAdjVolCnt                = 0,
    .AdjVol.Time                        = 0,
    .AdjVol.TimeOut                     = 0,

    .AdjVol.T_VPP1                      = 0,
    .AdjVol.T_VNN1                      = 0,
    .AdjVol.T_VPP2                      = 0, 
    .AdjVol.T_VNN2                      = 0,

    .AdjVol.Old_T_VPP1                  = 0,
    .AdjVol.Old_T_VNN1                  = 0,
    .AdjVol.Old_T_VPP2                  = 0, 
    .AdjVol.Old_T_VNN2                  = 0,
    
    .AdjVol.MAX_VPP1                    = 0,
    .AdjVol.MIN_VPP1                    = 0, 
    .AdjVol.MAX_VNN1                    = 0,
    .AdjVol.MIN_VNN1                    = 0,
    .AdjVol.MAX_VPP2                    = 0,
    .AdjVol.MIN_VPP2                    = 0,
    .AdjVol.MAX_VNN2                    = 0,
    .AdjVol.MIN_VNN2                    = 0,

    .AdjVol.T_McuDacHv1                 = VPP1_DAC_CLOSE,
    .AdjVol.T_SpiDacHv1                 = VNN1_DAC_CLOSE,
    .AdjVol.T_McuDacHv2                 = VPP2_DAC_CLOSE,
    .AdjVol.T_SpiDacHv2                 = VNN2_DAC_CLOSE,
    .AdjVol.T_SpiDacPcw                 = PCW_DAC_CLOSE,
    .AdjVol.T_SpiDacNcw                 = NCW_DAC_CLOSE,
    
    .AdjVol.P_McuDacHv1                 = VPP1_DAC_CLOSE,
    .AdjVol.P_SpiDacHv1                 = VNN1_DAC_CLOSE,
    .AdjVol.P_McuDacHv2                 = VPP2_DAC_CLOSE,
    .AdjVol.P_SpiDacHv2                 = VNN2_DAC_CLOSE,
    .AdjVol.P_SpiDacPcw                 = PCW_DAC_CLOSE,
    .AdjVol.P_SpiDacNcw                 = NCW_DAC_CLOSE,
    
    .AdjVol.R_VPP1                      = 0,
    .AdjVol.R_VNN1                      = 0,
    .AdjVol.R_VPP2                      = 0,
    .AdjVol.R_VNN2                      = 0,
    .AdjVol.R_A3V75                     = 0,
    .AdjVol.R_A2V25                     = 0,
    .AdjVol.R_AP12V                     = 0,
    .AdjVol.R_AN12V                     = 0,
    .AdjVol.R_AP5V5_1                   = 0,
    .AdjVol.R_AP5V5_2                   = 0,
    .AdjVol.R_AN5V5                     = 0,
    .AdjVol.R_D5V                       = 0,
    .AdjVol.R_D0V95                     = 0,
    .AdjVol.R_D1V45                     = 0,
    .AdjVol.R_IADP                      = 0,

    .Temperature.FPGA                   = 0,
    .Temperature.MCU                    = 0,
    
    .Fan.Rpm1                           = 0,    
    .Fan.Rpm2                           = 0,
    .Fan.Rpm3                           = 0,
    .Fan.Rpm4                           = 0,
    .Fan.Rpm5                           = 0,
    
    .Cmd.Timeout                        = FALSE,
    .Cmd.HV_Send                        = FALSE,
    .Cmd.CW_Send                        = FALSE,
    .Cmd.Firmware_Send                  = FALSE,    
    .Cmd.CompileInfo_Send               = FALSE,
    .Cmd.Voltage_Send                   = FALSE,
    .Cmd.FanInfo_Send                   = FALSE,
    .Cmd.PwrInfo_Send                   = FALSE,
    .Cmd.EcInfo_Send                    = FALSE,
    .Cmd.WriteBoardOk_Send              = FALSE,
    .Cmd.BoardInfo_Send                 = FALSE,
    .Cmd.Channel                        = USB_CHANNEL,
             
    .PwrInfo.Bat1_Insert                = FALSE,
    .PwrInfo.Bat2_Insert                = FALSE,
    .PwrInfo.Bat1_Power                 = 0,
    .PwrInfo.Bat2_Power                 = 0,
    .PwrInfo.Bat1_Tempature             = 0,
    .PwrInfo.Bat2_Tempature             = 0,
    .PwrInfo.Bat1_State                 = BAT_STATE_ERROR,
    .PwrInfo.Bat2_State                 = BAT_STATE_ERROR,
    .PwrInfo.Ac_Insert                  = FALSE,
    
    .SystemState                        = SYSTEM_OFF,
    .KeyState                           = FALSE,
    .PowerOnReq                         = FALSE,
    .ShutDownReq                        = FALSE,
    .System_S4_Change                   = FALSE,
    .S3_State                           = FALSE,
    .S4_State                           = FALSE,
};

void SystemStateInit()
{
    SysMsg.AdjVol.HvFlag                = FALSE,
    SysMsg.AdjVol.CwFlag                = FALSE,
    
    SysMsg.AdjVol.VolInit               = FALSE,
    SysMsg.AdjVol.VolMinitor            = FALSE,
    
    SysMsg.AdjVol.AdjVolOpen            = FALSE,
    SysMsg.AdjVol.MinAdjVolOpen         = FALSE, 
    
    SysMsg.AdjVol.TimeFlag              = FALSE,
    
    SysMsg.AdjVol.HV1NeedChange         = FALSE,
    SysMsg.AdjVol.HV2NeedChange         = FALSE,
    
    #if PID_CTRL
    
    SysMsg.AdjVol.PidOpen               = FALSE,
    
    SysMsg.AdjVol.OldOffSetVpp1         = 0.0, 
    SysMsg.AdjVol.NowOffSetVpp1         = 0.0,
    SysMsg.AdjVol.McuDacVpp1            = VPP1_DAC_CLOSE,
           
    SysMsg.AdjVol.OldOffSetVnn1         = 0.0, 
    SysMsg.AdjVol.NowOffSetVnn1         = 0.0,
    SysMsg.AdjVol.McuDacVnn1            = VNN1_DAC_CLOSE,
    
    
    #endif 
    
    SysMsg.AdjVol.MinAdjVolCnt          = 0,
    SysMsg.AdjVol.Time                  = 0,
    SysMsg.AdjVol.TimeOut               = 0,

    SysMsg.AdjVol.T_VPP1                = 0,
    SysMsg.AdjVol.T_VNN1                = 0,
    SysMsg.AdjVol.T_VPP2                = 0, 
    SysMsg.AdjVol.T_VNN2                = 0,
    SysMsg.AdjVol.Old_T_VPP1            = 0,
    SysMsg.AdjVol.Old_T_VNN1            = 0,
    SysMsg.AdjVol.Old_T_VPP2            = 0, 
    SysMsg.AdjVol.Old_T_VNN2            = 0,
    
    SysMsg.AdjVol.MAX_VPP1              = 0,
    SysMsg.AdjVol.MIN_VPP1              = 0, 
    SysMsg.AdjVol.MAX_VNN1              = 0,
    SysMsg.AdjVol.MIN_VNN1              = 0,
    SysMsg.AdjVol.MAX_VPP2              = 0,
    SysMsg.AdjVol.MIN_VPP2              = 0,
    SysMsg.AdjVol.MAX_VNN2              = 0,
    SysMsg.AdjVol.MIN_VNN2              = 0,

    SysMsg.AdjVol.T_McuDacHv1           = VPP1_DAC_CLOSE,
    SysMsg.AdjVol.T_SpiDacHv1           = VNN1_DAC_CLOSE,
    SysMsg.AdjVol.T_McuDacHv2           = VPP2_DAC_CLOSE,
    SysMsg.AdjVol.T_SpiDacHv2           = VNN2_DAC_CLOSE,
    SysMsg.AdjVol.T_SpiDacPcw           = PCW_DAC_CLOSE,
    SysMsg.AdjVol.T_SpiDacNcw           = NCW_DAC_CLOSE,
    
    SysMsg.AdjVol.P_McuDacHv1           = VPP1_DAC_CLOSE,
    SysMsg.AdjVol.P_SpiDacHv1           = VNN1_DAC_CLOSE,
    SysMsg.AdjVol.P_McuDacHv2           = VPP2_DAC_CLOSE,
    SysMsg.AdjVol.P_SpiDacHv2           = VNN2_DAC_CLOSE,
    SysMsg.AdjVol.P_SpiDacPcw           = PCW_DAC_CLOSE,
    SysMsg.AdjVol.P_SpiDacNcw           = NCW_DAC_CLOSE,
    SysMsg.AdjVol.R_VPP1                = 0;
    SysMsg.AdjVol.R_VNN1                = 0;
    SysMsg.AdjVol.R_VPP2                = 0;
    SysMsg.AdjVol.R_VNN2                = 0;
    SysMsg.AdjVol.R_A3V75               = 0;
    SysMsg.AdjVol.R_A2V25               = 0;
    SysMsg.AdjVol.R_AP12V               = 0;
    SysMsg.AdjVol.R_AN12V               = 0;
    SysMsg.AdjVol.R_AP5V5_1             = 0;
    SysMsg.AdjVol.R_AP5V5_2             = 0;
    SysMsg.AdjVol.R_AN5V5               = 0;
    SysMsg.AdjVol.R_D5V                 = 0;
    SysMsg.AdjVol.R_D0V95               = 0;
    SysMsg.AdjVol.R_D1V45               = 0;
    SysMsg.AdjVol.R_IADP                = 0;

    SysMsg.Temperature.FPGA             = 0;
    SysMsg.Temperature.MCU              = 0;
    
    SysMsg.Fan.Rpm1                     = 0;    
    SysMsg.Fan.Rpm2                     = 0;
    SysMsg.Fan.Rpm3                     = 0;
    SysMsg.Fan.Rpm4                     = 0;
    SysMsg.Fan.Rpm5                     = 0;
    
    SysMsg.Cmd.Timeout                  = FALSE;
    SysMsg.Cmd.HV_Send                  = FALSE;
    SysMsg.Cmd.CW_Send                  = FALSE;
    SysMsg.Cmd.Firmware_Send            = FALSE;    
    SysMsg.Cmd.CompileInfo_Send         = FALSE;
    SysMsg.Cmd.Voltage_Send             = FALSE;
    SysMsg.Cmd.FanInfo_Send             = FALSE;
    SysMsg.Cmd.PwrInfo_Send             = FALSE;
    SysMsg.Cmd.EcInfo_Send              = FALSE;
    SysMsg.Cmd.WriteBoardOk_Send        = FALSE;
    SysMsg.Cmd.BoardInfo_Send           = FALSE;
    SysMsg.Cmd.Channel                  = USB_CHANNEL;
         
    SysMsg.PwrInfo.Ac_Insert            = FALSE;         
    SysMsg.PwrInfo.Bat1_Insert          = FALSE;
    SysMsg.PwrInfo.Bat2_Insert          = FALSE;
    SysMsg.PwrInfo.Bat1_Power           = 0;
    SysMsg.PwrInfo.Bat2_Power           = 0;
    SysMsg.PwrInfo.Bat1_Tempature       = 0.0;
    SysMsg.PwrInfo.Bat2_Tempature       = 0.0;
    SysMsg.PwrInfo.Bat1_State           = BAT_STATE_ERROR;
    SysMsg.PwrInfo.Bat2_State           = BAT_STATE_ERROR;
    
    SysMsg.SystemState                  = SYSTEM_OFF;
    SysMsg.KeyState                     = FALSE;
    SysMsg.PowerOnReq                   = FALSE;
    SysMsg.ShutDownReq                  = FALSE;
    SysMsg.System_S3_Change             = FALSE;
    SysMsg.System_S4_Change             = FALSE;
    SysMsg.S3_State                     = FALSE;
    SysMsg.S4_State                     = FALSE;
}

void Delay_Nop(uint16_t count)
{
    while(--count);
}

bool System_PwrKey_Minitor()	
{	
    bool stateChange = FALSE;
    static uint16_t startCnt = 0;
    static bool stateNow = FALSE, stateOld = FALSE;
            
    stateNow = PWR_KEY_CHK() ? TRUE : FALSE;
    
    if(stateOld != stateNow && ++startCnt>=60)
    {
        startCnt = 0;
        SysMsg.KeyState = stateOld = stateNow;
        
        if(SysMsg.SystemState == SYSTEM_OFF)   //在关机状态下按下按键执行开机	
        {
            SysMsg.PowerOnReq = TRUE;
        }
        if(SysMsg.SystemState == SYSTEM_ON)    //在开机状态下按下按键发送关机请求, 使屏幕弹出关机对话框							
        {
            SysMsg.ShutDownReq = TRUE;
        }
        
        stateChange = TRUE;
    }
    if(stateNow == FALSE)
    {
        startCnt = 0;
        SysMsg.PowerOnReq = FALSE;
        SysMsg.ShutDownReq = FALSE;
        SysMsg.KeyState = FALSE;
        stateNow = stateOld = FALSE;
    }

    return stateChange;
}

bool System_S3_State_Minitor()
{    
    bool s3StateChanged = FALSE;
    
    static uint8_t startCnt = 0;
    
    static bool stateNow = FALSE, stateOld = FALSE;
    
    stateNow = (bool)SUS_S3_CHK();
    
    if((stateNow != stateOld) && (++startCnt >= 1)) 
    {
        startCnt = 0;
        SysMsg.S3_State = stateOld = stateNow;
        s3StateChanged = TRUE;
        SysMsg.System_S3_Change = TRUE;
    }
    if(stateNow == stateOld)
    {
        startCnt = 0;
    }
    return s3StateChanged;
}

bool System_S4_State_Minitor()
{  
    bool s4StateChanged = FALSE;
    
    static uint8_t startCnt = 0;
    
    static bool stateNow = FALSE, stateOld = FALSE;
    
    stateNow = (bool)SUS_S4_CHK();
    
    if((stateNow != stateOld) && (++startCnt >= 1)) 
    {
        startCnt = 0;
        stateOld = stateNow;
        s4StateChanged = TRUE;
        SysMsg.System_S4_Change = TRUE;
    }
    if(stateNow == stateOld)
    {
        startCnt = 0;
    }
    return s4StateChanged; 
}
