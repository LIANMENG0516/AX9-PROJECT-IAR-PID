#include "power.h"

extern System_MsgStruct SysMsg;

void Power_Insert()
{
    SysMsg.PwrInfo.Ac_Insert = AC_INSERT_CHK() ? TRUE : FALSE;
    SysMsg.PwrInfo.Bat1_Insert = BAT1_INSERT_CHK() ? FALSE : TRUE;
    SysMsg.PwrInfo.Bat2_Insert = BAT2_INSERT_CHK() ? FALSE : TRUE;
}

uint8_t CheckBatteryState()
{
    uint8_t batState;
    
    batState = (BAT_STAT1() << 1) + BAT_STAT2();
    
    return batState;
}

void Battery_Power_Read()
{
    uint8_t batState;
    static bool bat1_Charging = FALSE, bat2_Charging = FALSE;
    static uint16_t bat1ChargeRecoverCnt = 0, bat2ChargeRecoverCnt = 0;
    
    Power_Insert();
    Bat1_PowerRead();
    Bat2_PowerRead();
    batState = CheckBatteryState();
    
    if(SysMsg.PwrInfo.Ac_Insert == TRUE)                                                    //AC在位
    {
        if(SysMsg.PwrInfo.Bat1_Insert == TRUE || SysMsg.PwrInfo.Bat2_Insert == TRUE)
        {
            if(SysMsg.PwrInfo.Bat1_Insert == TRUE)
            {
                if(SysMsg.PwrInfo.Bat1_Power == 100)
                {
                    if(batState == BAT_STATE_FULL || batState == BAT_STATE_ERROR)
                    {
                        BAT1_C_SHIFT_EN(0);
                        bat1_Charging = FALSE;
                        SysMsg.PwrInfo.Bat1_State = BAT_STATE_FULL;
                    }
                }
                else if(SysMsg.PwrInfo.Bat1_Power != 100 && batState == BAT_STATE_ERROR)
                {
                    if(++bat1ChargeRecoverCnt >= 100)
                    {
                        BAT1_C_SHIFT_EN(0);
                        bat1_Charging = FALSE;
                        SysMsg.PwrInfo.Bat1_State = BAT_STATE_ERROR;
                    }
                    else
                    {
                        BAT1_C_SHIFT_EN(1);
                        bat1_Charging = TRUE;
                        SysMsg.PwrInfo.Bat1_State = BAT_STATE_CHARGE;
                    }
                }
                else if(SysMsg.PwrInfo.Bat1_Power != 100 && batState == BAT_STATE_CHARGE)
                {
                    BAT1_C_SHIFT_EN(1);
                    bat1_Charging = TRUE;
                    SysMsg.PwrInfo.Bat1_State = BAT_STATE_CHARGE;
                }
                else
                {
                    BAT1_C_SHIFT_EN(0);
                    bat1_Charging = FALSE;
                    SysMsg.PwrInfo.Bat1_State = BAT_STATE_ERROR;
                }
            }
            else
            {
                if(SysMsg.PwrInfo.Bat2_Power == 100)
                {
                    if(batState == BAT_STATE_FULL || batState == BAT_STATE_ERROR)
                    {
                        BAT2_C_SHIFT_EN(0);
                        bat2_Charging = FALSE;
                        SysMsg.PwrInfo.Bat2_State = BAT_STATE_FULL;
                        bat2ChargeRecoverCnt = 0;
                    }
                }
                else if(SysMsg.PwrInfo.Bat2_Power != 100 && batState == BAT_STATE_ERROR)
                {
                    if(++bat2ChargeRecoverCnt >= 100)
                    {
                        BAT2_C_SHIFT_EN(0);
                        bat2_Charging = FALSE;
                        SysMsg.PwrInfo.Bat2_State = BAT_STATE_ERROR;
                    }
                    else
                    {
                        BAT2_C_SHIFT_EN(1);
                        bat2_Charging = TRUE;
                        SysMsg.PwrInfo.Bat2_State = BAT_STATE_CHARGE;
                    }
                }
                else if(SysMsg.PwrInfo.Bat2_Power != 100 && batState == BAT_STATE_CHARGE)
                {
                    BAT2_C_SHIFT_EN(1);
                    bat2_Charging = TRUE;
                    SysMsg.PwrInfo.Bat2_State = BAT_STATE_CHARGE;
                    bat2ChargeRecoverCnt = 0;
                }
                else
                {
                    BAT2_C_SHIFT_EN(0);
                    bat2_Charging = FALSE;
                    SysMsg.PwrInfo.Bat2_State = BAT_STATE_ERROR;
                    bat2ChargeRecoverCnt = 0;
                }
            }
        }
        else
        {
            bat1_Charging = FALSE;
            bat2_Charging = FALSE;
            SysMsg.PwrInfo.Bat1_State = BAT_STATE_ERROR;
            SysMsg.PwrInfo.Bat2_State = BAT_STATE_ERROR;
            bat1ChargeRecoverCnt = 0;
            bat2ChargeRecoverCnt = 0;
        }
        
        if(bat1_Charging == TRUE || bat2_Charging == TRUE)
        {
            if(bat1_Charging == TRUE && bat2_Charging == FALSE)
            {
                BAT1_C_SHIFT_EN(1);
                BAT2_C_SHIFT_EN(0);
            }
            if(bat1_Charging == FALSE && bat2_Charging == TRUE)
            {
                BAT1_C_SHIFT_EN(0);
                BAT2_C_SHIFT_EN(1);
            }
            
            if(SysMsg.SystemState == SYSTEM_ON)
            {
                CHARGE_CTL(0);                      //关闭快充
            }
            else
            {
                CHARGE_CTL(1);                      //打开快充
            }
            
            CHARGE_EN(1);                           //使能充电
        }
        else
        {
            BAT1_C_SHIFT_EN(0);
            BAT2_C_SHIFT_EN(0);
            CHARGE_CTL(0);
            CHARGE_EN(0);
        }  
    }
    else
    {
        SysMsg.PwrInfo.Bat1_State = BAT_STATE_ERROR;
        SysMsg.PwrInfo.Bat2_State = BAT_STATE_ERROR;
        bat1ChargeRecoverCnt = 0;
        bat2ChargeRecoverCnt = 0;
        bat1_Charging = FALSE;
        bat2_Charging = FALSE;
        BAT1_C_SHIFT_EN(0);
        BAT2_C_SHIFT_EN(0);
        CHARGE_CTL(0);
        CHARGE_EN(0);
    }  
}


















