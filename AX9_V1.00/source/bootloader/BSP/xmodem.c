#include "xmodem.h"

#include "board.h"

extern CDC_IF_Prop_TypeDef VCP_fops;
extern uint8_t USB_Rx_Buffer[CDC_DATA_MAX_PACKET_SIZE]; 
extern uint32_t receive_count;

bool XmodemStart = FALSE;
bool XmodemRxDat = FALSE;

XmodemStruct Rx_BufStruct;

uint8_t RxBuf[CDC_DATA_MAX_PACKET_SIZE];
uint16_t RxLen = 0;
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

uint32_t kk = 0;

void Xmodm_Updata()
{
    uint8_t Data = 0;
    
    if(VCP_CheckDataReceived() != 0)                                        //接收到了数据
    {
        ++kk;
        printf("kk = %d \r\n", kk);
        
        RxLen = receive_count;                                             //将接收的数据存入 Rx_Len
        
        for(uint16_t i=0; i<RxLen; i++)
        {
            RxBuf[i] = USB_Rx_Buffer[i];
            
            printf("%02X ", RxBuf[i]);
        }
        
        printf("\r\n");
        
        receive_count = 0;
        memset(USB_Rx_Buffer, 0, sizeof(USB_Rx_Buffer));
       
        XmodemStart = TRUE;
        XmodemRxDat = TRUE;                                             
    }

    if(XmodemStart == FALSE)                                                    //通讯未开始
    {
        Data = TRANSMIT;
        XmodemSend(&Data, 1);                                                   //发送字符C
        delay_ms(500);                                          
    }
    else
    {
        if(XmodemRxDat == TRUE)                                                 //判断一包数据是否接收完成
        {
            XmodemRxDat = FALSE;
            
            switch(ReceiveDataFrameAnalysis(RxBuf, RxLen))                      //解析数据
            {
                case UPDAT_RUN:
                                    Flash_Program(APPL_AREA_ADDR + addroffset, &Rx_BufStruct.Buf[0], RxLen - 5);
                                    addroffset += (RxLen - 5);
                                    Data = ACK;
                                    XmodemSend(&Data, 1);                        
                                    break;
                case UPDAT_ERR:
                                    Data = NAK;
                                    XmodemSend(&Data, 1);
                                    break;
                case UPDAT_END:
                                    Data = ACK;
                                    XmodemSend(&Data, 1);     
                                    break;
                case UPDAT_FINISH:
                                    USB_CTRL_EN(0); 
                                    
                                    XmodemStart = FALSE;
                                    XmodemRxDat = FALSE;

                                    Data = ACK;
                                    XmodemSend(&Data, 1);

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





