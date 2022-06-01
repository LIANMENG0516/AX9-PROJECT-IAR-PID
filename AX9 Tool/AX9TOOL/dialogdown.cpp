#include "dialogdown.h"
#include "ui_dialogdown.h"

#include "widget.h"

#include <QFileDialog>
#include <QDataStream>
#include <QDebug>

#define SOH 0x01
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
#define CAN 0x18

typedef struct {

    qint8 Head;
    qint8 packNum;
    qint8 numPack;
    qint8 data[128];
    qint8 chkHigh;
    qint8 chkLow;
}Xmodem;

Xmodem xmod;

DialogDown::DialogDown(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDown)
{
    ui->setupUi(this);
}


DialogDown::~DialogDown()
{
    delete ui;
}

void DialogDown::on_pushButton_clicked()
{
    QString dir = QDir::currentPath();
    curPath = QFileDialog::getOpenFileName(this, "选择文件", dir);
    ui->lineEdit->setText(curPath);
}



qint16 calcrc(const qint8 *ptr, qint16 count)
{
    qint8 i;
    qint16 crc = 0;

    while(--count >= 0)
    {
        crc = crc ^ (qint8) *ptr++ << 8;
        i = 8;
        do
        {
            if(crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
        } while(--i);
    }

    return(crc);
}

#define beginTransimt    1
#define runTransimt      2
#define repeatTransimt   3
#define stopTransimt     4
#define errTransimt      5

qint8 serialRevciveAnalysis(QByteArray byteArray)
{
    if(byteArray.size() == 1 && byteArray.at(0) == 'C')
    {
        return beginTransimt;
    }
    if(byteArray.size() == 1 && byteArray.at(0) == ACK)
    {
        return runTransimt;
    }
    if(byteArray.size() == 1 && byteArray.at(0) == NAK)
    {
        return repeatTransimt;
    }
    if(byteArray.size() == 1 && byteArray.at(0) == CAN)
    {
        return stopTransimt;
    }

    return errTransimt;
}

int packNum = 0;

int val = 0;

void DialogDown::slot_PortData()
{
    int crc = 0;

    Widget *ptr = (Widget *)parentWidget();
    QByteArray byteArray;

    byteArray = ptr->serialPort.readAll();

    switch(serialRevciveAnalysis(byteArray))
    {
        case    beginTransimt:                              //接收到字符'C', 开始传输
        case    runTransimt:                                //接收到ACK
                {
                    if(datArr.size() == 0)                      //文件发送完成
                    {
                        datArr.resize(1);
                        datArr.append(EOT);
                        ptr->serialPort.write(datArr);         //发送EOT
                        ui->label->setText("升级完成");
                        ui->progressBar->setValue(100);
                    }
                    else
                    {
                        if(val >= 95)
                        {
                            ui->progressBar->setValue(95);
                        }
                        else
                        {
                            ++val;
                            ui->progressBar->setValue(val);
                        }

                        if(packNum == 255)
                        {
                            packNum = 0;
                        }

                        xmod.Head = SOH;
                        xmod.packNum = ++packNum;
                        xmod.numPack = 255 - packNum;

                        if(datArr.size() >= 128)
                        {
                            for(int i=0; i<128; i++)
                            {
                                xmod.data[i] = datArr[i];
                            }

                            datArr = datArr.right(datArr.size() - 128);
                        }
                        else
                        {
                            for(int i=0; i<128; i++)
                            {
                                if(i < datArr.size())
                                {
                                    xmod.data[i] = datArr[i];
                                }
                                else
                                {
                                    xmod.data[i] = 0x1A;
                                } 
                            }

                            datArr.clear();
                        }

                        crc = calcrc(&xmod.data[0], 128);

                        xmod.chkHigh = crc >> 8;
                        xmod.chkLow = crc;

                        char *data = new char[133];
                        memset(data, 0, sizeof(xmod));
                        memcpy(data, &xmod ,sizeof(xmod));     //对结构体取址，必须在结构体变量名前加取址符&

                        qDebug() << sizeof(xmod);

                        ptr->serialPort.write(data, 133);

                        delete [] data;
                    }
                }
                break;
        case    repeatTransimt:                             //接收到NAK, 重新传输
                {
                    char *data = new char[133];
                    memset(data, 0, sizeof(xmod));
                    memcpy(data, &xmod ,sizeof(xmod));          //对结构体取址，必须在结构体变量名前加取址符&
                    ptr->serialPort.write(data);
                    delete [] data;
                }
                break;
        case    stopTransimt:                               //接收到CAN，取消发送
                {
                    datArr.clear();
                    ui->label->setText("传输取消");
                }
                break;
        case    errTransimt:
                {
                    datArr.clear();
                    ui->label->setText("传输失败");
                }
                break;
    }
}

void DialogDown::on_pushButton_2_clicked()
{
    ui->label->setText("正在升级...");

    QFile aFile(curPath);
    aFile.open(QIODevice::ReadOnly);                            //打开文件
    datArr = aFile.readAll();
    aFile.close();

    val = datArr.size();

    if(val != 0)
    {
        Widget *ptr = (Widget *)parentWidget();                 //指针函数，返回值为某一类型的指针。

        disconnect(&ptr->serialPort, SIGNAL(readyRead()), ptr, SLOT(slot_RecvPortData()));
        connect(&ptr->serialPort, SIGNAL(readyRead()), this, SLOT(slot_PortData()));
    }
}

void DialogDown::closeEvent(QCloseEvent *)
{
    val = 0;
    packNum = 0;
    Widget *ptr = (Widget *)parentWidget();
    connect(&ptr->serialPort, SIGNAL(readyRead()), ptr, SLOT(slot_RecvPortData()));
}





