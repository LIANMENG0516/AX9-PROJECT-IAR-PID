#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QtCharts>

#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>

#include <QDataStream>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "dialogdown.h"


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Widget;
}



typedef struct
{
    uint8_t		Header;
    uint8_t		Id;
    uint8_t		Cid;
    uint8_t 	Len;
    uint8_t 	Data[100];
    uint8_t		Chk;
    uint8_t 	Tail;
}CmdFrameStr;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:
    void chartSignal();
    void sendProcess(int val);

private slots:
    void slot_RecvPortData();   //自定义槽函数用于串口接收
    void on_timerReadVol();     //定时读取电压
    void on_chartUpData();      //更新图标

    void on_timer_timeout();

    void on_btnScan_clicked();

    void on_btnOpen_clicked();

    void on_btnClose_clicked();

    void on_btnSend_clicked();

    void on_btnClearRev_clicked();

    void on_btnClearSend_clicked();

    void on_btnStart_clicked();

    void on_btnFwVersion_clicked();

    void on_btnCompileInfo_clicked();

    void on_btnRdHwVersion_clicked();

    void on_btnWrHwVersion_clicked();

    void on_btnTempInfo_clicked();

    void on_btnPowerInfo_clicked();

    void on_btnFanInfo_clicked();

    void on_btnVoltageInfo_clicked();

    void on_btnSetHv_clicked();

    void on_btnGetVol_clicked();

    void on_btnSetCw_clicked();

    void on_btnUpgrade_clicked();

private:
    Ui::Widget *ui;

public:
     QSerialPort serialPort;

     void readSerialPort();

private:



    QDateTime   curdatetime;
    QLineSeries *curSeries;
    QValueAxis  *curAxis;
    QTimer      timer;
    QTimer      timerReadVol;       //命令发送定时器，开启后每20ms发送一次电压读取命令
    QTimer      timerUpData;        //绘图更新定时器，每隔一定时间绘制一屏幕图，具体间隔时间按照流畅度调试设定

    QList<QPointF> points;



    CmdFrameStr RcvFrameCmd;



    qint16 vpp1[10];
    qint16 vnn1[10];
    qint16 vpp2[10];
    qint16 vnn2[10];

    void SerialPortInit();
    void ChartFormInit();
    void PrepareData();

    void String_To_Hex(QString *str, QByteArray *sendBytes);


};

#endif // WIDGET_H
