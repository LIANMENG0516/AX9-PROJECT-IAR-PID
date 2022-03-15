#include "adjustvoltage.h"

#include "gouble.h"

extern System_MsgStruct SysMsg;

uint16_t Vpp_Calculate_AdjVol(uint16_t T_Data)
{
    float Adjvol;
    uint16_t Dac_Val;
    
    Adjvol = 2.096 - T_Data / 100.0 / 43.2;                                  //(1/43.2+1/3.48+1)*1.6=2.096
    Dac_Val = (int)((Adjvol / 3.3 * 4095)+ 0.5);

    return Dac_Val;
}

uint16_t Vnn_Calculate_AdjVol(uint16_t T_Data)
{
    float Adjvol;
    uint16_t Dac_Val;
    
    Adjvol = 2.098 - ((0.023 * T_Data) / 100);    
    
    Dac_Val = ((int)(Adjvol * 4096 / 2.048)) >> 4;               //四舍五入后取整数
    
    return Dac_Val;
}

uint16_t Pcw_Calculate_AdjVol(uint16_t T_Data)
{
    uint16_t Dac_Val;
    
    Dac_Val = (uint16_t)(279 - 28.4 * T_Data / 100);
    
    return Dac_Val;
}

uint16_t Ncw_Calculate_AdjVol(uint16_t T_Data)
{
    uint16_t Dac_Val;
    
    Dac_Val = (uint16_t)(318 - 29.2 * T_Data / 100);    
    
    return Dac_Val;
}

void Adjust_Voltage_Vpp1(uint16_t T_Vpp1)
{
    SysMsg.AdjVol.P_McuDacHv1 = SysMsg.AdjVol.T_McuDacHv1 = Vpp_Calculate_AdjVol(T_Vpp1);                         //计算要调节到目标值时HVADJ1的值
    DAC_SetChannel1Data(DAC_Align_12b_R, SysMsg.AdjVol.T_McuDacHv1);                   //调节VPP1至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);                                   //软件触发DAC转换
}

void Adjust_Voltage_Vpp2(uint16_t T_Vpp2)
{
    SysMsg.AdjVol.P_McuDacHv2 = SysMsg.AdjVol.T_McuDacHv2 = Vpp_Calculate_AdjVol(T_Vpp2);                         //计算要调节到目标值时HVADJ3的值
    DAC_SetChannel2Data(DAC_Align_12b_R, SysMsg.AdjVol.T_McuDacHv2);                   //调节VPP2至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);                                   //软件触发DAC转换
}

void Adjust_Voltage_Vnn1_Vnn2(uint16_t T_Vnn1, uint16_t T_Vnn2)                                           
{
    SysMsg.AdjVol.P_SpiDacHv1 = SysMsg.AdjVol.T_SpiDacHv1 = Vnn_Calculate_AdjVol(T_Vnn1);
    SysMsg.AdjVol.P_SpiDacHv2 = SysMsg.AdjVol.T_SpiDacHv2 = Vnn_Calculate_AdjVol(T_Vnn2);
    DacHv_Tlv5626cd_ValueSet(SysMsg.AdjVol.T_SpiDacHv1, SysMsg.AdjVol.T_SpiDacHv2);
}

void Adjust_Voltage_Pcw_Ncw(uint16_t Pcw, uint16_t Ncw)                                           
{
    SysMsg.AdjVol.P_SpiDacPcw = SysMsg.AdjVol.T_SpiDacPcw = Pcw_Calculate_AdjVol(Pcw);
    SysMsg.AdjVol.P_SpiDacNcw = SysMsg.AdjVol.T_SpiDacNcw = Ncw_Calculate_AdjVol(Ncw);
    
    DacCw_Tlv5626cd_ValueSet(SysMsg.AdjVol.T_SpiDacPcw, SysMsg.AdjVol.T_SpiDacNcw);
}

void Adjust_Hv_Reset()
{
    DAC_SetChannel1Data(DAC_Align_12b_R, VPP1_DAC_CLOSE);                   //调节VPP1至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);                          //软件触发DAC转换
    
    DAC_SetChannel2Data(DAC_Align_12b_R, VPP2_DAC_CLOSE);                   //调节VPP2至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);                          //软件触发DAC转换
    
    DacHv_Tlv5626cd_ValueSet(VNN1_DAC_CLOSE, VNN2_DAC_CLOSE);
}

void Adjust_Hv1_Reset()
{
    DAC_SetChannel1Data(DAC_Align_12b_R, VPP1_DAC_CLOSE);                   //调节VPP1至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);                          //软件触发DAC转换
    DacHv_Tlv5626cd_ValueSet(VNN1_DAC_CLOSE, SysMsg.AdjVol.P_SpiDacHv2);
}

void Adjust_Hv2_Reset()
{
    DAC_SetChannel2Data(DAC_Align_12b_R, VPP2_DAC_CLOSE);                   //调节VPP2至目标值
    DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);                          //软件触发DAC转换
    DacHv_Tlv5626cd_ValueSet(SysMsg.AdjVol.P_SpiDacHv1, VNN2_DAC_CLOSE);
}

void Adjust_Cw_Reset()
{
    DacCw_Tlv5626cd_ValueSet(PCW_DAC_CLOSE, PCW_DAC_CLOSE);
}

void Adjust_Voltage_Init()
{  
    Adjust_Hv_Reset();
    //Adjust_Cw_Reset();
    Adjust_Voltage_Pcw_Ncw(250, 250); 
    CTL_VPP1_VNN1_EN(0);                                                        //打开高压输出
    CTL_VPP2_VNN2_EN(0);
}

void Adjust_Voltage_Close()
{
    Adjust_Hv_Reset();
    Adjust_Cw_Reset();
    CTL_VPP1_VNN1_EN(0);                                                        //打开高压输出
    CTL_VPP2_VNN2_EN(0);
}

void Adjust_Voltage_HV()    //高压调压处理流程
{       
    Adjust_Cw_Reset();   
    CTL_VPP1_VNN1_EN(1);                                                        //打开高压输出
    CTL_VPP2_VNN2_EN(1);
    Adjust_Voltage_Vpp1(SysMsg.AdjVol.T_VPP1);                                  //调节VPP1至目标值
    Adjust_Voltage_Vpp2(SysMsg.AdjVol.T_VPP2);                                  //调节VPP2至目标值
    Adjust_Voltage_Vnn1_Vnn2(SysMsg.AdjVol.T_VNN1, SysMsg.AdjVol.T_VNN2);       //调节VNN1, VNN2至目标值
    
}

void Adjust_Voltage_CW()    //低压调压处理流程
{
    CTL_VPP1_VNN1_EN(1);                                                        //打开高压输出
    CTL_VPP2_VNN2_EN(0);
    Adjust_Voltage_Vpp1(SysMsg.AdjVol.T_VPP1);                                  //调节VPP1至目标值   
    Adjust_Voltage_Vpp2(VPP2_DAC_CLOSE);
    Adjust_Voltage_Vnn1_Vnn2(SysMsg.AdjVol.T_VNN1, VNN2_DAC_CLOSE);  
    Adjust_Voltage_Pcw_Ncw(SysMsg.AdjVol.T_VPP2, SysMsg.AdjVol.T_VNN2);
    
}




