#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Ax9 Tool");

    this->setPalette(QPalette(Qt::gray));
    this->setAutoFillBackground(true);

    SerialPortInit();
    ChartFormInit();
    PrepareData();


    connect(&serialPort, SIGNAL(readyRead()), this, SLOT(slot_RecvPortData()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
    connect(&timerReadVol, SIGNAL(timeout()), this, SLOT(on_timerReadVol()));
    connect(this, SIGNAL(chartSignal()), this, SLOT(on_chartUpData()));
    qsrand(QTime::currentTime().second());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readSerialPort()
{

    ui->label->setText("ddd");
}

void Widget::SerialPortInit()
{
    QString str = "COM";
    QStringList comList;
    for(int i=1; i<=10; i++)
    {
        comList.append(str + QString::number(i, 10));
    }
    ui->boxPortNum->addItems(comList);

    QStringList rateList;
    rateList << "4800" << "9600" << "115200" << "128000" << "230400" << "256000";
    ui->boxBaundRate->addItems(rateList);
    ui->boxBaundRate->setCurrentText("115200");

    QStringList dataBitList = {"6 bit", "7 bit", "8 bit"};
    ui->boxDataBits->addItems(dataBitList);
    ui->boxDataBits->setCurrentText("8 bit");

    QStringList stopBitList = {"1 bit", "1.5 bit", "2 bit"};
    ui->boxStopBits->addItems(stopBitList);
    ui->boxStopBits->setCurrentText("1 bit");

    QStringList partityList = {"None", "Odd", "Even"};
    ui->boxPartity->addItems(partityList);
    ui->boxPartity->setCurrentText("None");

    QStringList flowCtrlList = {"None", "Software", "Hardware"};
    ui->boxFlowCtrl->addItems(flowCtrlList);
    ui->boxFlowCtrl->setCurrentText("None");
}

void Widget::ChartFormInit()
{
    QDate iniData(1970, 1, 1);
    QTime satTime(8, 0, 0, 0);
    QTime endTime(8, 0, 5, 0);
    QDateTime mindatetime(iniData, satTime);
    QDateTime maxdatetime(iniData, endTime);

    QChart *chart = new QChart();

    ui->chartView->setChart(chart);                     //添加图表
    chart->setTitle(tr("电压采集曲线"));                  //设置图表名称

    QDateTimeAxis *axisX = new QDateTimeAxis();
    QValueAxis *axisY = new QValueAxis();

    axisX->setRange(mindatetime, maxdatetime);
    axisX->setFormat("ss");
    axisX->setTickCount(6);
    axisX->setTitleText("time");

    axisY->setRange(-80, 80);
    axisY->setLabelFormat("%.2f");                      //标签格式
    axisY->setTickCount(9);
    axisY->setMinorTickCount(1);
    axisY->setTitleText("value");

    chart->addAxis(axisX, Qt::AlignBottom);             //为图表添加坐标轴X
    chart->addAxis(axisY, Qt::AlignLeft);               //为图表添加坐标轴Y

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QLineSeries *series3 = new QLineSeries();

    series0->setName("VPP1");
    series1->setName("VNN1");
    series2->setName("VPP2");
    series3->setName("VNN2");


    QPen    pen;

    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen);

    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    series1->setPen(pen);

    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::yellow);
    series2->setPen(pen);

    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::green);
    series3->setPen(pen);

    chart->addSeries(series0);                      //为图表添加折线series0
    chart->addSeries(series1);                      //为图表添加折线series1
    chart->addSeries(series2);                      //为图表添加折线series2
    chart->addSeries(series3);                      //为图表添加折线series3

    series0->attachAxis(axisX);                     //关联折线与坐标轴
    series0->attachAxis(axisY);
    series1->attachAxis(axisX);
    series1->attachAxis(axisY);
    series2->attachAxis(axisX);
    series2->attachAxis(axisY);
    series3->attachAxis(axisX);
    series3->attachAxis(axisY);
}

void Widget::PrepareData()
{
    QLineSeries *series0=(QLineSeries *)ui->chartView->chart()->series().at(0);
    QLineSeries *series1=(QLineSeries *)ui->chartView->chart()->series().at(1);
    QLineSeries *series2=(QLineSeries *)ui->chartView->chart()->series().at(2);
    QLineSeries *series3=(QLineSeries *)ui->chartView->chart()->series().at(3);

    series0->clear(); //清除数据
    series1->clear();
    series2->clear(); //清除数据
    series3->clear();

    series0->setUseOpenGL(true);
    series1->setUseOpenGL(true);
    series2->setUseOpenGL(true);
    series3->setUseOpenGL(true);

    for(qint16 i=0; i<=5000; i+=20)
    {
        points.append(QPoint(i, 0));
    }
    QTime etime;
    etime.start();
    series0->append(points);
    series1->append(points);
    series2->append(points);
    series3->append(points);
}

void Widget::on_chartUpData()
{
    QLineSeries *series0=(QLineSeries *)ui->chartView->chart()->series().at(0);
    QLineSeries *series1=(QLineSeries *)ui->chartView->chart()->series().at(1);
    QLineSeries *series2=(QLineSeries *)ui->chartView->chart()->series().at(2);
    QLineSeries *series3=(QLineSeries *)ui->chartView->chart()->series().at(3);

    QVector<QPointF> newPointsVpp1;
    QVector<QPointF> newPointsVnn1;
    QVector<QPointF> newPointsVpp2;
    QVector<QPointF> newPointsVnn2;

    newPointsVpp1 = series0->pointsVector();
    newPointsVnn1 = series1->pointsVector();
    newPointsVpp2 = series2->pointsVector();
    newPointsVnn2 = series3->pointsVector();

    qint16 i = 0, j = 0;

    for(i=0; i<=newPointsVnn1.count()-1-10; i++)     //向左平移10个点
    {
        newPointsVpp1[i].setY(newPointsVpp1[i+10].y());
        newPointsVnn1[i].setY(newPointsVnn1[i+10].y());
        newPointsVpp2[i].setY(newPointsVpp2[i+10].y());
        newPointsVnn2[i].setY(newPointsVnn2[i+10].y());
    }

    for(j=0; j<10; j++)                                 //使用之前采集到的数据补齐最后10个点
    {
        newPointsVpp1[i+j].setY(vpp1[j]);
        newPointsVnn1[i+j].setY(-vnn1[j]);
        newPointsVpp2[i+j].setY(vpp2[j]);
        newPointsVnn2[i+j].setY(-vnn2[j]);
    }

    series0->replace(newPointsVpp1);
    series1->replace(newPointsVnn1);
    series2->replace(newPointsVpp2);
    series3->replace(newPointsVnn2);
}


void Widget::on_timer_timeout()
{
    if(!ui->chkSendRepeat->isChecked())
    {
        timer.stop();

    }

    on_btnSend_clicked();
}


void Widget::on_timerReadVol()
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x0E;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x13;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::slot_RecvPortData()
{
    QByteArray revBytes;

    revBytes = serialPort.readAll();

    if(ui->chkRevDisplayTime->isChecked())
    {
        curdatetime = QDateTime::currentDateTime();
        ui->textEditRev->appendPlainText(curdatetime.toString("[hh:mm:ss:zzz]<-"));
    }

    if(ui->radioRevHex->isChecked())
    {
        for(qint8 i=0; i<revBytes.length(); i++)
        {
            QString str = QString("%1 ").arg(revBytes.at(i)&0xFF, 2, 16, QLatin1Char('0'));

            ui->textEditRev->insertPlainText(str);
        }
    }
    else
    {
        QString str = QString(revBytes);
        ui->textEditRev->insertPlainText(str);
    }



    //对数据进行解析，解析结果符合要求的传至绘图程序
    if(revBytes.length())
    {
        qint8 CmdCrc = 0;

        if(revBytes[0] == 0x68 && revBytes[1] == 0x04)
        {
            RcvFrameCmd.Header = revBytes[0];
            RcvFrameCmd.Id     = revBytes[1];
            RcvFrameCmd.Cid    = revBytes[2];
            RcvFrameCmd.Len    = revBytes[3];

            for(qint8 i=0; i<revBytes.length()-6; i++)
            {
                RcvFrameCmd.Data[i] = revBytes[4+i];
            }

            RcvFrameCmd.Chk    = revBytes[revBytes.length()-2];
            RcvFrameCmd.Tail   = revBytes[revBytes.length()-1];

            if(RcvFrameCmd.Header == 0x68 && RcvFrameCmd.Id == 0x04 && RcvFrameCmd.Tail == 0x16)
            {
                CmdCrc = RcvFrameCmd.Id + RcvFrameCmd.Cid + RcvFrameCmd.Len;

                for(qint8 i=0; i<RcvFrameCmd.Len; i++)
                {
                    CmdCrc += RcvFrameCmd.Data[i];
                }

                if(RcvFrameCmd.Cid == 0x0E)     //动态电压读取
                {
                    static qint8 i = 0;

                    vpp1[i] = (RcvFrameCmd.Data[0] << 8 | RcvFrameCmd.Data[1]) / 100.0;
                    vnn1[i] = (RcvFrameCmd.Data[2] << 8 | RcvFrameCmd.Data[3]) / 100.0;
                    vpp2[i] = (RcvFrameCmd.Data[4] << 8 | RcvFrameCmd.Data[5]) / 100.0;
                    vnn2[i] = (RcvFrameCmd.Data[6] << 8 | RcvFrameCmd.Data[7]) / 100.0;

                    ui->spinBoxVpp1->setValue(vpp1[i]);
                    ui->spinBoxVnn1->setValue(vnn1[i]);
                    ui->spinBoxVpp2->setValue(vpp2[i]);
                    ui->spinBoxVnn2->setValue(vnn2[i]);

                    if(ui->btnStart->text() == "暂停")
                    {
                        if(++i >= 10)
                        {
                            i = 0;
                            qDebug() << "ggggggggggggg";
                            emit chartSignal();                 //发射信号，更新图标
                        }
                    }
                    else
                    {
                        i = 0;
                    }
                }

                if(RcvFrameCmd.Cid == 0x01)     //版本读取并解析
                {
                    qint16 version = 0;

                    version = RcvFrameCmd.Data[0] << 8 | RcvFrameCmd.Data[1];
                    version = 0x9000;
                    QString str = QString::asprintf("%d.%d%d", ((version>>12) & 0x07), ((version>>8) & 0x0f) , ((version>>4) & 0x0f));
                    ui->lineEditFwVersion->setText(str);

                    ui->lineEditFwVersion->setStyleSheet("background-color:rgba(0,255,255,255)");
                }

                if(RcvFrameCmd.Cid == 0x02)     //编译时间读取并解析
                {
                    QString str;

                    for(int i=0; i<19; i++)
                    {
                        str[i] = RcvFrameCmd.Data[i];
                    }

                    ui->lineEditCompInfo->setText(str);

                    ui->lineEditCompInfo->setStyleSheet("background-color:rgba(0,255,255,255)");
                }

                if(RcvFrameCmd.Cid == 0x03)     //硬件版本读取并解析
                {
                    qint16 version = 0;

                    version = RcvFrameCmd.Data[0] << 8 | RcvFrameCmd.Data[1];
                    QString str = QString::asprintf("%d.%d%d", ((version>>12) & 0x07), ((version>>8) & 0x0f) , ((version>>4) & 0x0f));
                    ui->lineEditFwVersion->setText(str);
                }

                if(RcvFrameCmd.Cid == 0x0B)     //温度信息读取并解析
                {
                    QString str = QString::asprintf("BAT1: %d BAT2: %d", RcvFrameCmd.Data[0], RcvFrameCmd.Data[1]);
                    ui->lineEditTempInfo->setText(str);
                }

                if(RcvFrameCmd.Cid == 0x09)     //电源信息读取并解析
                {
                    QString str = QString::asprintf("Ac_Insert: %d Bat1_Insert: %d Bat1_Power: %d Bat1_State: %02X Bat2_Insert: %d Bat2_Power: %d Bat2_State: %02X ", RcvFrameCmd.Data[0], RcvFrameCmd.Data[1], RcvFrameCmd.Data[2], RcvFrameCmd.Data[3], RcvFrameCmd.Data[4], RcvFrameCmd.Data[5], RcvFrameCmd.Data[6]);
                    ui->lineEditPowerInfo->setText(str);
                }

                if(RcvFrameCmd.Cid == 0x0A)     //风扇信息读取并解析
                {
                    QString str = QString::asprintf("Fan1: %d Fan2: %d Fan3: %d Fan4: %d Fan5: %d", (RcvFrameCmd.Data[0]<<8 | RcvFrameCmd.Data[1]), (RcvFrameCmd.Data[2]<<8 | RcvFrameCmd.Data[3]), (RcvFrameCmd.Data[4]<<8 | RcvFrameCmd.Data[5]), (RcvFrameCmd.Data[6]<<8 | RcvFrameCmd.Data[7]), (RcvFrameCmd.Data[8]<<8 | RcvFrameCmd.Data[9]));
                    ui->lineEditFanInfo->setText(str);
                }

                if(RcvFrameCmd.Cid == 0x0D)     //静态电压读取并解析
                {
                    QString str = QString::asprintf("AP12V: %02f AN12V: %02f AP5V5_1: %02f AP5V5_2: %02f AN5V5: %02f A3V75: %02f A2V25: %02f D5V: %02f D1V45: %02f D0V95: %02f", (RcvFrameCmd.Data[0]<<8 | RcvFrameCmd.Data[1]) / 100.0, (RcvFrameCmd.Data[2]<<8 | RcvFrameCmd.Data[3]) / 100.0, (RcvFrameCmd.Data[4]<<8 | RcvFrameCmd.Data[5]) / 100.0, (RcvFrameCmd.Data[6]<<8 | RcvFrameCmd.Data[7]) / 100.0, (RcvFrameCmd.Data[8]<<8 | RcvFrameCmd.Data[9]) / 100.0, (RcvFrameCmd.Data[10]<<8 | RcvFrameCmd.Data[11]) / 100.0, (RcvFrameCmd.Data[12]<<8 | RcvFrameCmd.Data[13]) / 100.0, (RcvFrameCmd.Data[14]<<8 | RcvFrameCmd.Data[15]) / 100.0, (RcvFrameCmd.Data[16]<<8 | RcvFrameCmd.Data[17]) / 100.0, (RcvFrameCmd.Data[18]<<8 | RcvFrameCmd.Data[19]) / 100.0);
                    ui->lineEditVoltageInfo->setText(str);
                }
            }
        }
    }
}


void Widget::String_To_Hex(QString *str, QByteArray *sendBytes)
{
    for(qint8 i=0; i<str->length(); i=i+2)
    {
        bool ok;
        qint8 hexdata;
        QString hex_h = str->at(i);
        QString hex_l = str->at(i+1);
        hexdata = (hex_h.toInt(&ok, 16) << 4) + hex_l.toInt(&ok, 16);
        sendBytes->append(hexdata);
    }

    sendBytes->resize(str->length() / 2);
}

void Widget::on_btnScan_clicked()
{
    ui->boxPortNum->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->boxPortNum->addItem(info.portName());
        serialPort.setPort(info);
        serialPort.close();
    }
}

void Widget::on_btnOpen_clicked()
{
    //设置串口号
    serialPort.setPortName(ui->boxPortNum->currentText());

    //设置波特率
    serialPort.setBaudRate(ui->boxBaundRate->currentText().toLong());

    //设置数据位
    if(ui->boxDataBits->currentText() == "6 bit")
    {
        serialPort.setDataBits(QSerialPort::Data6);
    }
    else if(ui->boxDataBits->currentText() == "7 bit")
    {
        serialPort.setDataBits(QSerialPort::Data7);
    }
    else if(ui->boxDataBits->currentText() == "8 bit")
    {
        serialPort.setDataBits(QSerialPort::Data8);
    }
    else
    {
        serialPort.setDataBits(QSerialPort::UnknownDataBits);
    }

    //设置停止位
    if(ui->boxStopBits->currentText() == "1 bit")
    {
        serialPort.setStopBits(QSerialPort::OneStop);
    }
    else if(ui->boxStopBits->currentText() == "1.5 bit")
    {
        serialPort.setStopBits(QSerialPort::OneAndHalfStop);
    }
    else if(ui->boxStopBits->currentText() == "2 bit")
    {
        serialPort.setStopBits(QSerialPort::TwoStop);
    }
    else
    {
        serialPort.setStopBits(QSerialPort::UnknownStopBits);
    }

    //设置校验位
    if(ui->boxPartity->currentText() == "None")
    {
        serialPort.setParity(QSerialPort::NoParity);
    }
    else if(ui->boxPartity->currentText() == "Odd")
    {
        serialPort.setParity(QSerialPort::OddParity);
    }
    else
    {
        serialPort.setParity(QSerialPort::EvenParity);
    }

    //设置流控
    if(ui->boxFlowCtrl->currentText()=="None")
    {
        serialPort.setFlowControl(QSerialPort::NoFlowControl);
    }
    else if(ui->boxFlowCtrl->currentText() == "Software")
    {
        serialPort.setFlowControl(QSerialPort::SoftwareControl);
    }
    else
    {
        serialPort.setFlowControl(QSerialPort::HardwareControl);
    }

    //打开串口
    if(!serialPort.open(QIODevice::ReadWrite))
    {
        qDebug("串口打开失败!");
        QMessageBox::warning(this, "警告", "串口打开失败", QMessageBox::Ok, QMessageBox::NoButton);
    }
    else
    {
        ui->boxPortNum->setEnabled(0);
        ui->boxBaundRate->setEnabled(0);
        ui->boxBaundRate->setEnabled(0);
        ui->boxDataBits->setEnabled(0);
        ui->boxStopBits->setEnabled(0);
        ui->boxPartity->setEnabled(0);
        ui->boxFlowCtrl->setEnabled(0);
        ui->btnOpen->setEnabled(0);
        ui->btnClose->setEnabled(1);
        ui->btnSend->setEnabled(1);
    }
}

void Widget::on_btnClose_clicked()
{
    serialPort.close();

    timer.stop();

    ui->boxPortNum->setEnabled(1);
    ui->boxBaundRate->setEnabled(1);
    ui->boxBaundRate->setEnabled(1);
    ui->boxDataBits->setEnabled(1);
    ui->boxStopBits->setEnabled(1);
    ui->boxPartity->setEnabled(1);
    ui->boxFlowCtrl->setEnabled(1);
    ui->btnOpen->setEnabled(1);
    ui->btnClose->setEnabled(0);
    ui->btnSend->setEnabled(0);
}



void Widget::on_btnSend_clicked()
{
    QByteArray sendBytes;

    QString str;

    str = ui->textEditSend->toPlainText();

    if(ui->radioSendHex->isChecked())
    {
        str = str.remove(' ');
        if(str.length()%2)
        {
            QMessageBox::warning(this, "警告", "非法数据，请检查", QMessageBox::Ok, QMessageBox::NoButton);
            return;
        }
        else
        {
            String_To_Hex(&str, &sendBytes);
            if(ui->chkRevDisplayTime->isChecked())
            {
                curdatetime = QDateTime::currentDateTime();
                ui->textEditRev->appendPlainText(curdatetime.toString("[hh:mm:ss:zzz]->"));

                for(qint8 i=0; i<sendBytes.length(); i++)
                {
                    QString str = QString("%1 ").arg(sendBytes.at(i)&0xFF, 2, 16, QLatin1Char('0'));
                    ui->textEditRev->insertPlainText(str);
                }
            }
        }
    }
    else
    {
        if(ui->chkRevDisplayTime->isChecked())
        {
            curdatetime = QDateTime::currentDateTime();
            ui->textEditRev->appendPlainText(curdatetime.toString("[hh:mm:ss:zzz]->"));

            ui->textEditRev->insertPlainText(str);
        }
        if(ui->chkNewLine->isChecked())
        {
            str.append("\r\n");
        }

        sendBytes = str.toLatin1();
    }

    if(ui->chkSendRepeat->isChecked())
    {
        timer.setInterval(ui->spinRepatTime->value());
        timer.start();
    }

    serialPort.write(sendBytes);
}

void Widget::on_btnClearRev_clicked()
{
    ui->textEditRev->clear();
}

void Widget::on_btnClearSend_clicked()
{
    ui->textEditSend->clear();
}

void Widget::on_btnStart_clicked()
{
    static unsigned char i = 0;

    if(++i % 2 !=0)
    {
        timerReadVol.setInterval(20);       //开启读取电压的定时器，每20ms下发一次电压读取命令
        timerReadVol.start();
        ui->btnStart->setText("暂停");
    }
    else
    {
        timerReadVol.stop();
        ui->btnStart->setText("开始");
    }
}

void Widget::on_btnFwVersion_clicked()      //发送固件版本读取命令
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x01;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x06;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnCompileInfo_clicked()    //发送编译信息读取命令
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x02;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x07;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnRdHwVersion_clicked()    //读取硬件版本
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x03;
    sendBytes[3] = 0x01;
    sendBytes[3] = 0x00;
    sendBytes[4] = 0x08;
    sendBytes[5] = 0x16;

    serialPort.write(sendBytes);

}

void Widget::on_btnWrHwVersion_clicked()    //写硬件版本
{





}

void Widget::on_btnTempInfo_clicked()   //读温度信息
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x0B;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x10;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnPowerInfo_clicked()      //读取电源信息
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x09;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x0E;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnFanInfo_clicked()    //读风扇信息
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x0A;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x0F;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnVoltageInfo_clicked()    //读静态电压
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x0D;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x12;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}









void Widget::on_btnSetHv_clicked()
{
    qint16 vpp1, vnn1, vpp2, vnn2;

    vpp1 = ui->spinBoxHvVpp1->value() * 100;
    vnn1 = ui->spinBoxHvVnn1->value() * 100;
    vpp2 = ui->spinBoxHvVpp2->value() * 100;
    vnn2 = ui->spinBoxHvVnn2->value() * 100;

    QByteArray sendBytes;

    sendBytes.resize(14);
    sendBytes[0]  = 0x68;
    sendBytes[1]  = 0x04;
    sendBytes[2]  = 0x13;
    sendBytes[3]  = 0x08;
    sendBytes[4]  = vpp1 >> 8;
    sendBytes[5]  = vpp1;
    sendBytes[6]  = vnn1 >> 8;
    sendBytes[7]  = vnn1;
    sendBytes[8]  = vpp2 >> 8;
    sendBytes[9]  = vpp2;
    sendBytes[10] = vnn2 >> 8;
    sendBytes[11] = vnn2;


    uint8_t chkSum = 0;

    for(int i=0; i<8; i++)
    {
        chkSum += sendBytes[i+4];
    }

    sendBytes[12] = 0x04 + 0x13 + 0x08 + (vpp1 >> 8) + vpp1 + (vnn1 >> 8) + vnn1 + (vpp2 >> 8) + vpp2 + (vnn2 >> 8) + vnn2;
    sendBytes[13] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnGetVol_clicked()
{
    QByteArray sendBytes;

    sendBytes.resize(6);
    sendBytes[0] = 0x68;
    sendBytes[1] = 0x04;
    sendBytes[2] = 0x0E;
    sendBytes[3] = 0x01;
    sendBytes[4] = 0x00;
    sendBytes[5] = 0x13;
    sendBytes[6] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnSetCw_clicked()
{
    qint16 vpp1, vnn1, vpp2, vnn2;

    vpp1 = ui->spinBoxCwVpp1->value() * 100;
    vnn1 = ui->spinBoxCwVnn1->value() * 100;
    vpp2 = ui->spinBoxPcw->value() * 100;
    vnn2 = ui->spinBoxNcw->value() * 100;

    QByteArray sendBytes;

    sendBytes.resize(14);
    sendBytes[0]  = 0x68;
    sendBytes[1]  = 0x04;
    sendBytes[2]  = 0x14;
    sendBytes[3]  = 0x08;
    sendBytes[4]  = vpp1 >> 8;
    sendBytes[5]  = vpp1;
    sendBytes[6]  = vnn1 >> 8;
    sendBytes[7]  = vnn1;
    sendBytes[8]  = vpp2 >> 8;
    sendBytes[9]  = vpp2;
    sendBytes[10] = vnn2 >> 8;
    sendBytes[11] = vnn2;
    sendBytes[12] = 0x04 + 0x14 + 0x08 + (vpp1 >> 8) + vpp1 + (vnn1 >> 8) + vnn1 + (vpp2 >> 8) + vpp2 + (vnn2 >> 8) + vnn2;
    sendBytes[13] = 0x16;

    serialPort.write(sendBytes);
}

void Widget::on_btnUpgrade_clicked()
{
    DialogDown diaDown(this);   //this is very important

    diaDown.exec();
}







