#include "xmodem.h"

#include "board.h"

extern CDC_IF_Prop_TypeDef VCP_fops;
extern uint32_t receive_count;
extern uint16_t Rx_Len;
extern uint8_t Rx_Buf[1500];

bool XmodemIapOk = FALSE;
bool XmodemStart = FALSE;
bool XmodemRxDat = FALSE;

XmodemStruct Rx_BufStruct;

uint32_t addroffset = 0;

uint16_t calcrc(uint8_t *ptr, uint16_t count)  
{  
    uint8_t i = 0; 
    uint16_t crc = 0;  
  
    while(count--)  
    {  
        crc = crc ^ (uint32_t)*ptr++ << 8;  
        i = 8;  
        do  
        {  
            if(crc & 0x8000)  
            {
                crc = crc << 1 ^ 0x1021; 
            }     
            else  
            {
                crc = crc << 1; 
            }
        }while(--i);  
    }  
    return crc;  
} 

uint8_t ReceiveDataFrameAnalysis(uint8_t *pData, uint16_t Len)
{
    if(Len == 0x01)
    {
        Rx_BufStruct.Header = EOT;
    }
    
    if((Len == (128 + 5)) || (Len == (1024 + 5)))
    {
        Rx_BufStruct.Header   = *pData++;
        Rx_BufStruct.Pack_Fth = *pData++;
        Rx_BufStruct.Pack_Sth = *pData++;
        
        if(Len == 128 + 5)
        {
            for(uint8_t i=0; i<128; i++)
            {
                Rx_BufStruct.Buf[i] = *pData++;
            }
        }
        if(Len == 1024 + 5)
        {
            for(uint16_t i=0; i<1024; i++)
            {
                Rx_BufStruct.Buf[i] = *pData++;
            }
        }
        Rx_BufStruct.Crc_Msb = *pData++;
        Rx_BufStruct.Crc_Lsb = *pData;
    }

    if(Rx_BufStruct.Header == SOH)
    {
        if(Len == 128 + 5)
        {
            if(calcrc(&Rx_BufStruct.Buf[0], 128) == ((Rx_BufStruct.Crc_Msb << 8) | Rx_BufStruct.Crc_Lsb))
            {
                return UPDAT_RUN;
            }
            else
            {
                return UPDAT_ERR;
            }
        }
        if(Len == 1024 + 5)
        {
            if(calcrc(&Rx_BufStruct.Buf[0], 1024) == ((Rx_BufStruct.Crc_Msb << 8) | Rx_BufStruct.Crc_Lsb))
            {
                return UPDAT_RUN;
            }
            else
            {
                return UPDAT_ERR;
            }
        }
    }
    
    if(Rx_BufStruct.Header == EOT)
    {
        return UPDAT_FINISH;
    }
    
    return UPDAT_ERR;
}

void XmodemSend(uint8_t *pData, uint16_t Len)
{
    VCP_fops.pIf_DataTx(pData, Len);
}


uint8_t USB_Tx_Buffer[CDC_DATA_MAX_PACKET_SIZE];
uint32_t kk = 0;

void Xmodm_Updata()
{
    uint8_t Data = 0;
    
    if(VCP_CheckDataReceived() != 0)                                            //接收到了数据
    {
        ++kk;
        printf("kk = %d \r\n", kk);
        for(uint16_t i=0; i<receive_count; i++)
        {
            printf("%02X ", Rx_Buf[i]);
        }
        printf("\r\n");
        
        
        if(Rx_Buf[0] == 0x68 && Rx_Buf[1] == 0x11 && Rx_Buf[2] == 04 && Rx_Buf[3] == 0x01 && Rx_Buf[4] == 0xC0 && Rx_Buf[5] == 0x16)
        {
            if(XmodemIapOk == TRUE)
            {
                USB_Tx_Buffer[0] = 0x68;
                USB_Tx_Buffer[1] = 0x11;
                USB_Tx_Buffer[2] = 0x04;
                USB_Tx_Buffer[3] = 0x01;
                USB_Tx_Buffer[4] = 0xC4;
                USB_Tx_Buffer[5] = 0x16;
                VCP_fops.pIf_DataTx(USB_Tx_Buffer, 6);
            }

            Rx_Len = 0;
            receive_count = 0;
        }
        else
        {
            receive_count = 0;
            XmodemStart = TRUE;
            XmodemRxDat = TRUE;  
        }                                         
    }
    
    
    
    static uint32_t startCnt = 0;

    if(XmodemStart == FALSE && ++startCnt >=3000000)                            //通讯未开始, 约1秒钟执行一次
    {
        startCnt = 0;
        Data = TRANSMIT;
        XmodemSend(&Data, 1);                                                   //发送字符C     
    }
    else
    {
        if(XmodemRxDat == TRUE)                                                 //判断一包数据是否接收完成
        {
            XmodemRxDat = FALSE;
            
            switch(ReceiveDataFrameAnalysis(Rx_Buf, Rx_Len))                    //解析数据
            {
                case UPDAT_RUN:
                                    Flash_Program(APPL_AREA_ADDR + addroffset, &Rx_BufStruct.Buf[0], Rx_Len - 5);
                                    addroffset += (Rx_Len - 5);
                                    Data = ACK;
                                    XmodemSend(&Data, 1);  
                                    Rx_Len = 0;
                                    break;
                case UPDAT_ERR:
                                    Data = NAK;
                                    XmodemSend(&Data, 1);
                                    Rx_Len = 0;
                                    break;
                case UPDAT_END:
                                    Data = ACK;
                                    XmodemSend(&Data, 1);   
                                    Rx_Len = 0;
                                    break;
                case UPDAT_FINISH:
                                    Data = ACK;
                                    XmodemSend(&Data, 1);
                                    Rx_Len = 0;
                                    
                                    XmodemIapOk = TRUE;

                                    FLASH_Unlock();
                                    FLASH_EraseSector(FLASH_Sector_10, VoltageRange_3);
                                    FLASH_Lock();
                                    break;
            }
        }
    }
}


void Reset_Cpu()
{
    SCB_AIRCR = SCB_RESET_VALUE;
}





