/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGridLayout *gridLayout;
    QComboBox *boxDataBits;
    QComboBox *boxPortNum;
    QComboBox *boxBaundRate;
    QComboBox *boxStopBits;
    QComboBox *boxPartity;
    QComboBox *boxFlowCtrl;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOpen;
    QPushButton *btnClose;
    QPushButton *btnScan;
    QGroupBox *groupBox_2;
    QRadioButton *radioRevHex;
    QRadioButton *radioRevAssic;
    QCheckBox *chkRevDisplayTime;
    QGroupBox *groupBox_3;
    QRadioButton *radioSendHex;
    QCheckBox *chkSendRepeat;
    QRadioButton *radioSendAssic;
    QCheckBox *chkNewLine;
    QSpinBox *spinRepatTime;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QPlainTextEdit *textEditSend;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QPushButton *btnSend;
    QPushButton *btnClearRev;
    QPushButton *btnClearSend;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *textEditRev;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_16;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_15;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout_23;
    QLabel *label_16;
    QDoubleSpinBox *spinBoxVpp1;
    QFormLayout *formLayout_24;
    QLabel *label_17;
    QDoubleSpinBox *spinBoxVnn1;
    QFormLayout *formLayout_25;
    QLabel *label_18;
    QDoubleSpinBox *spinBoxVpp2;
    QFormLayout *formLayout_26;
    QLabel *label_15;
    QDoubleSpinBox *spinBoxVnn2;
    QPushButton *btnGetVol;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout_27;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxHvVpp1;
    QFormLayout *formLayout_28;
    QLabel *label_10;
    QDoubleSpinBox *spinBoxHvVnn1;
    QFormLayout *formLayout_29;
    QLabel *label_9;
    QDoubleSpinBox *spinBoxHvVpp2;
    QFormLayout *formLayout_30;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxHvVnn2;
    QPushButton *btnSetHv;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_19;
    QLabel *label_12;
    QDoubleSpinBox *spinBoxCwVpp1;
    QFormLayout *formLayout_20;
    QLabel *label_11;
    QDoubleSpinBox *spinBoxCwVnn1;
    QFormLayout *formLayout_21;
    QLabel *label_14;
    QDoubleSpinBox *spinBoxPcw;
    QFormLayout *formLayout_22;
    QLabel *label_13;
    QDoubleSpinBox *spinBoxNcw;
    QPushButton *btnSetCw;
    QPushButton *btnAutoAdjVol;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_13;
    QPushButton *btnSleep;
    QPushButton *btnWeakup;
    QPushButton *btnRestart;
    QPushButton *btnUpgrade;
    QPushButton *btnVpp1Vnn1En;
    QPushButton *btnVpp1Vnn1Dis;
    QPushButton *btnVpp2Vnn2En;
    QPushButton *btnVpp2Vnn2Dis;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_10;
    QPushButton *btnCompileInfo;
    QPushButton *btnFwVersion;
    QPushButton *btnRdHwVersion;
    QPushButton *btnWrHwVersion;
    QPushButton *btnTempInfo;
    QPushButton *btnPowerInfo;
    QPushButton *btnFanInfo;
    QPushButton *btnVoltageInfo;
    QGridLayout *gridLayout_11;
    QLineEdit *lineEditCompInfo;
    QLineEdit *lineEditFwVersion;
    QLineEdit *lineEditRdHwVersion;
    QLineEdit *lineEditWrHwVersion;
    QLineEdit *lineEditTempInfo;
    QLineEdit *lineEditPowerInfo;
    QLineEdit *lineEditFanInfo;
    QLineEdit *lineEditVoltageInfo;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_2;
    QChartView *chartView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnStart;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1900, 971);
        gridLayout_9 = new QGridLayout(Widget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox_7 = new QGroupBox(Widget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox_7->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(7, 7, 7, 7);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(groupBox_7);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 260));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        boxDataBits = new QComboBox(groupBox);
        boxDataBits->setObjectName(QStringLiteral("boxDataBits"));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        boxDataBits->setFont(font3);

        gridLayout->addWidget(boxDataBits, 2, 0, 1, 1);

        boxPortNum = new QComboBox(groupBox);
        boxPortNum->setObjectName(QStringLiteral("boxPortNum"));
        boxPortNum->setFont(font3);

        gridLayout->addWidget(boxPortNum, 0, 0, 1, 1);

        boxBaundRate = new QComboBox(groupBox);
        boxBaundRate->setObjectName(QStringLiteral("boxBaundRate"));
        boxBaundRate->setFont(font3);

        gridLayout->addWidget(boxBaundRate, 1, 0, 1, 1);

        boxStopBits = new QComboBox(groupBox);
        boxStopBits->setObjectName(QStringLiteral("boxStopBits"));
        boxStopBits->setFont(font3);

        gridLayout->addWidget(boxStopBits, 3, 0, 1, 1);

        boxPartity = new QComboBox(groupBox);
        boxPartity->setObjectName(QStringLiteral("boxPartity"));
        boxPartity->setFont(font3);

        gridLayout->addWidget(boxPartity, 4, 0, 1, 1);

        boxFlowCtrl = new QComboBox(groupBox);
        boxFlowCtrl->setObjectName(QStringLiteral("boxFlowCtrl"));
        boxFlowCtrl->setFont(font3);

        gridLayout->addWidget(boxFlowCtrl, 5, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout);


        verticalLayout_3->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnOpen = new QPushButton(groupBox);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setEnabled(true);
        btnOpen->setFont(font3);

        horizontalLayout->addWidget(btnOpen);

        btnClose = new QPushButton(groupBox);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setEnabled(true);
        btnClose->setFont(font3);

        horizontalLayout->addWidget(btnClose);


        verticalLayout_3->addLayout(horizontalLayout);

        btnScan = new QPushButton(groupBox);
        btnScan->setObjectName(QStringLiteral("btnScan"));
        btnScan->setFont(font3);

        verticalLayout_3->addWidget(btnScan);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_7);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        radioRevHex = new QRadioButton(groupBox_2);
        radioRevHex->setObjectName(QStringLiteral("radioRevHex"));
        radioRevHex->setGeometry(QRect(10, 30, 101, 16));
        radioRevHex->setFont(font3);
        radioRevAssic = new QRadioButton(groupBox_2);
        radioRevAssic->setObjectName(QStringLiteral("radioRevAssic"));
        radioRevAssic->setGeometry(QRect(120, 30, 51, 16));
        radioRevAssic->setFont(font3);
        radioRevAssic->setChecked(true);
        chkRevDisplayTime = new QCheckBox(groupBox_2);
        chkRevDisplayTime->setObjectName(QStringLiteral("chkRevDisplayTime"));
        chkRevDisplayTime->setGeometry(QRect(10, 60, 121, 16));
        chkRevDisplayTime->setFont(font3);

        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox_7);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 259));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox_3->setFont(font4);
        radioSendHex = new QRadioButton(groupBox_3);
        radioSendHex->setObjectName(QStringLiteral("radioSendHex"));
        radioSendHex->setGeometry(QRect(10, 30, 137, 21));
        radioSendHex->setFont(font2);
        chkSendRepeat = new QCheckBox(groupBox_3);
        chkSendRepeat->setObjectName(QStringLiteral("chkSendRepeat"));
        chkSendRepeat->setGeometry(QRect(10, 60, 121, 21));
        chkSendRepeat->setFont(font2);
        radioSendAssic = new QRadioButton(groupBox_3);
        radioSendAssic->setObjectName(QStringLiteral("radioSendAssic"));
        radioSendAssic->setGeometry(QRect(120, 30, 71, 19));
        radioSendAssic->setFont(font2);
        radioSendAssic->setChecked(true);
        chkNewLine = new QCheckBox(groupBox_3);
        chkNewLine->setObjectName(QStringLiteral("chkNewLine"));
        chkNewLine->setGeometry(QRect(10, 90, 91, 19));
        chkNewLine->setFont(font2);
        spinRepatTime = new QSpinBox(groupBox_3);
        spinRepatTime->setObjectName(QStringLiteral("spinRepatTime"));
        spinRepatTime->setGeometry(QRect(120, 60, 51, 22));
        spinRepatTime->setFont(font2);
        spinRepatTime->setMaximum(10000);
        spinRepatTime->setValue(1);

        verticalLayout_2->addWidget(groupBox_3);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 3, 1);

        groupBox_5 = new QGroupBox(groupBox_7);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 200));
        QFont font5;
        font5.setPointSize(9);
        groupBox_5->setFont(font5);
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textEditSend = new QPlainTextEdit(groupBox_5);
        textEditSend->setObjectName(QStringLiteral("textEditSend"));
        textEditSend->setFont(font3);

        gridLayout_5->addWidget(textEditSend, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_5, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_7);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setFont(font5);
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        btnSend = new QPushButton(groupBox_6);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setFont(font3);

        gridLayout_6->addWidget(btnSend, 0, 0, 1, 1);

        btnClearRev = new QPushButton(groupBox_6);
        btnClearRev->setObjectName(QStringLiteral("btnClearRev"));
        btnClearRev->setFont(font3);

        gridLayout_6->addWidget(btnClearRev, 0, 1, 1, 1);

        btnClearSend = new QPushButton(groupBox_6);
        btnClearSend->setObjectName(QStringLiteral("btnClearSend"));
        btnClearSend->setFont(font3);

        gridLayout_6->addWidget(btnClearSend, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 2, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textEditRev = new QPlainTextEdit(groupBox_4);
        textEditRev->setObjectName(QStringLiteral("textEditRev"));
        textEditRev->setFont(font3);

        gridLayout_4->addWidget(textEditRev, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(Widget);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setFont(font);
        gridLayout_16 = new QGridLayout(groupBox_9);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(7, 7, 7, 7);
        groupBox_10 = new QGroupBox(groupBox_9);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setMaximumSize(QSize(16777215, 259));
        gridLayout_8 = new QGridLayout(groupBox_10);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        formLayout_23 = new QFormLayout();
        formLayout_23->setSpacing(6);
        formLayout_23->setObjectName(QStringLiteral("formLayout_23"));
        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font3);

        formLayout_23->setWidget(0, QFormLayout::LabelRole, label_16);

        spinBoxVpp1 = new QDoubleSpinBox(groupBox_10);
        spinBoxVpp1->setObjectName(QStringLiteral("spinBoxVpp1"));
        spinBoxVpp1->setEnabled(true);
        spinBoxVpp1->setFont(font3);
        spinBoxVpp1->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));
        spinBoxVpp1->setWrapping(false);
        spinBoxVpp1->setFrame(true);
        spinBoxVpp1->setReadOnly(false);
        spinBoxVpp1->setAccelerated(false);
        spinBoxVpp1->setKeyboardTracking(true);
        spinBoxVpp1->setProperty("showGroupSeparator", QVariant(false));

        formLayout_23->setWidget(0, QFormLayout::FieldRole, spinBoxVpp1);


        verticalLayout_7->addLayout(formLayout_23);

        formLayout_24 = new QFormLayout();
        formLayout_24->setSpacing(6);
        formLayout_24->setObjectName(QStringLiteral("formLayout_24"));
        label_17 = new QLabel(groupBox_10);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font3);

        formLayout_24->setWidget(0, QFormLayout::LabelRole, label_17);

        spinBoxVnn1 = new QDoubleSpinBox(groupBox_10);
        spinBoxVnn1->setObjectName(QStringLiteral("spinBoxVnn1"));
        spinBoxVnn1->setFont(font3);
        spinBoxVnn1->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));

        formLayout_24->setWidget(0, QFormLayout::FieldRole, spinBoxVnn1);


        verticalLayout_7->addLayout(formLayout_24);

        formLayout_25 = new QFormLayout();
        formLayout_25->setSpacing(6);
        formLayout_25->setObjectName(QStringLiteral("formLayout_25"));
        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font3);

        formLayout_25->setWidget(0, QFormLayout::LabelRole, label_18);

        spinBoxVpp2 = new QDoubleSpinBox(groupBox_10);
        spinBoxVpp2->setObjectName(QStringLiteral("spinBoxVpp2"));
        spinBoxVpp2->setFont(font3);
        spinBoxVpp2->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));

        formLayout_25->setWidget(0, QFormLayout::FieldRole, spinBoxVpp2);


        verticalLayout_7->addLayout(formLayout_25);

        formLayout_26 = new QFormLayout();
        formLayout_26->setSpacing(6);
        formLayout_26->setObjectName(QStringLiteral("formLayout_26"));
        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font3);

        formLayout_26->setWidget(0, QFormLayout::LabelRole, label_15);

        spinBoxVnn2 = new QDoubleSpinBox(groupBox_10);
        spinBoxVnn2->setObjectName(QStringLiteral("spinBoxVnn2"));
        spinBoxVnn2->setFont(font3);
        spinBoxVnn2->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));

        formLayout_26->setWidget(0, QFormLayout::FieldRole, spinBoxVnn2);


        verticalLayout_7->addLayout(formLayout_26);

        btnGetVol = new QPushButton(groupBox_10);
        btnGetVol->setObjectName(QStringLiteral("btnGetVol"));
        btnGetVol->setEnabled(true);
        btnGetVol->setFont(font3);

        verticalLayout_7->addWidget(btnGetVol);


        gridLayout_15->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        formLayout_27 = new QFormLayout();
        formLayout_27->setSpacing(6);
        formLayout_27->setObjectName(QStringLiteral("formLayout_27"));
        label_7 = new QLabel(groupBox_10);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        formLayout_27->setWidget(0, QFormLayout::LabelRole, label_7);

        spinBoxHvVpp1 = new QDoubleSpinBox(groupBox_10);
        spinBoxHvVpp1->setObjectName(QStringLiteral("spinBoxHvVpp1"));
        spinBoxHvVpp1->setFont(font3);

        formLayout_27->setWidget(0, QFormLayout::FieldRole, spinBoxHvVpp1);


        verticalLayout_8->addLayout(formLayout_27);

        formLayout_28 = new QFormLayout();
        formLayout_28->setSpacing(6);
        formLayout_28->setObjectName(QStringLiteral("formLayout_28"));
        label_10 = new QLabel(groupBox_10);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);

        formLayout_28->setWidget(0, QFormLayout::LabelRole, label_10);

        spinBoxHvVnn1 = new QDoubleSpinBox(groupBox_10);
        spinBoxHvVnn1->setObjectName(QStringLiteral("spinBoxHvVnn1"));
        spinBoxHvVnn1->setFont(font3);

        formLayout_28->setWidget(0, QFormLayout::FieldRole, spinBoxHvVnn1);


        verticalLayout_8->addLayout(formLayout_28);

        formLayout_29 = new QFormLayout();
        formLayout_29->setSpacing(6);
        formLayout_29->setObjectName(QStringLiteral("formLayout_29"));
        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);

        formLayout_29->setWidget(0, QFormLayout::LabelRole, label_9);

        spinBoxHvVpp2 = new QDoubleSpinBox(groupBox_10);
        spinBoxHvVpp2->setObjectName(QStringLiteral("spinBoxHvVpp2"));
        spinBoxHvVpp2->setFont(font3);

        formLayout_29->setWidget(0, QFormLayout::FieldRole, spinBoxHvVpp2);


        verticalLayout_8->addLayout(formLayout_29);

        formLayout_30 = new QFormLayout();
        formLayout_30->setSpacing(6);
        formLayout_30->setObjectName(QStringLiteral("formLayout_30"));
        label_8 = new QLabel(groupBox_10);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);

        formLayout_30->setWidget(0, QFormLayout::LabelRole, label_8);

        spinBoxHvVnn2 = new QDoubleSpinBox(groupBox_10);
        spinBoxHvVnn2->setObjectName(QStringLiteral("spinBoxHvVnn2"));
        spinBoxHvVnn2->setFont(font3);

        formLayout_30->setWidget(0, QFormLayout::FieldRole, spinBoxHvVnn2);


        verticalLayout_8->addLayout(formLayout_30);

        btnSetHv = new QPushButton(groupBox_10);
        btnSetHv->setObjectName(QStringLiteral("btnSetHv"));
        btnSetHv->setFont(font3);

        verticalLayout_8->addWidget(btnSetHv);


        gridLayout_15->addLayout(verticalLayout_8, 0, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        formLayout_19 = new QFormLayout();
        formLayout_19->setSpacing(6);
        formLayout_19->setObjectName(QStringLiteral("formLayout_19"));
        label_12 = new QLabel(groupBox_10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        formLayout_19->setWidget(0, QFormLayout::LabelRole, label_12);

        spinBoxCwVpp1 = new QDoubleSpinBox(groupBox_10);
        spinBoxCwVpp1->setObjectName(QStringLiteral("spinBoxCwVpp1"));
        spinBoxCwVpp1->setFont(font3);

        formLayout_19->setWidget(0, QFormLayout::FieldRole, spinBoxCwVpp1);


        verticalLayout_6->addLayout(formLayout_19);

        formLayout_20 = new QFormLayout();
        formLayout_20->setSpacing(6);
        formLayout_20->setObjectName(QStringLiteral("formLayout_20"));
        label_11 = new QLabel(groupBox_10);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);

        formLayout_20->setWidget(0, QFormLayout::LabelRole, label_11);

        spinBoxCwVnn1 = new QDoubleSpinBox(groupBox_10);
        spinBoxCwVnn1->setObjectName(QStringLiteral("spinBoxCwVnn1"));
        spinBoxCwVnn1->setFont(font3);

        formLayout_20->setWidget(0, QFormLayout::FieldRole, spinBoxCwVnn1);


        verticalLayout_6->addLayout(formLayout_20);

        formLayout_21 = new QFormLayout();
        formLayout_21->setSpacing(6);
        formLayout_21->setObjectName(QStringLiteral("formLayout_21"));
        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font3);

        formLayout_21->setWidget(0, QFormLayout::LabelRole, label_14);

        spinBoxPcw = new QDoubleSpinBox(groupBox_10);
        spinBoxPcw->setObjectName(QStringLiteral("spinBoxPcw"));
        spinBoxPcw->setFont(font3);

        formLayout_21->setWidget(0, QFormLayout::FieldRole, spinBoxPcw);


        verticalLayout_6->addLayout(formLayout_21);

        formLayout_22 = new QFormLayout();
        formLayout_22->setSpacing(6);
        formLayout_22->setObjectName(QStringLiteral("formLayout_22"));
        label_13 = new QLabel(groupBox_10);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font3);

        formLayout_22->setWidget(0, QFormLayout::LabelRole, label_13);

        spinBoxNcw = new QDoubleSpinBox(groupBox_10);
        spinBoxNcw->setObjectName(QStringLiteral("spinBoxNcw"));
        spinBoxNcw->setFont(font3);

        formLayout_22->setWidget(0, QFormLayout::FieldRole, spinBoxNcw);


        verticalLayout_6->addLayout(formLayout_22);

        btnSetCw = new QPushButton(groupBox_10);
        btnSetCw->setObjectName(QStringLiteral("btnSetCw"));
        btnSetCw->setFont(font3);

        verticalLayout_6->addWidget(btnSetCw);


        gridLayout_15->addLayout(verticalLayout_6, 0, 2, 1, 1);

        btnAutoAdjVol = new QPushButton(groupBox_10);
        btnAutoAdjVol->setObjectName(QStringLiteral("btnAutoAdjVol"));
        btnAutoAdjVol->setMaximumSize(QSize(16777215, 500));
        btnAutoAdjVol->setFont(font3);
        btnAutoAdjVol->setText(QLatin1String("Auto\n"
"Adiust\n"
"Voltage"));

        gridLayout_15->addWidget(btnAutoAdjVol, 1, 0, 1, 3);


        gridLayout_8->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_16->addWidget(groupBox_10, 1, 1, 1, 1);

        groupBox_12 = new QGroupBox(groupBox_9);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setMaximumSize(QSize(16777215, 259));
        gridLayout_13 = new QGridLayout(groupBox_12);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        btnSleep = new QPushButton(groupBox_12);
        btnSleep->setObjectName(QStringLiteral("btnSleep"));
        btnSleep->setFont(font3);

        gridLayout_13->addWidget(btnSleep, 0, 0, 1, 1);

        btnWeakup = new QPushButton(groupBox_12);
        btnWeakup->setObjectName(QStringLiteral("btnWeakup"));
        btnWeakup->setFont(font3);

        gridLayout_13->addWidget(btnWeakup, 1, 0, 1, 1);

        btnRestart = new QPushButton(groupBox_12);
        btnRestart->setObjectName(QStringLiteral("btnRestart"));
        btnRestart->setFont(font3);

        gridLayout_13->addWidget(btnRestart, 2, 0, 1, 1);

        btnUpgrade = new QPushButton(groupBox_12);
        btnUpgrade->setObjectName(QStringLiteral("btnUpgrade"));
        btnUpgrade->setFont(font3);

        gridLayout_13->addWidget(btnUpgrade, 3, 0, 1, 1);

        btnVpp1Vnn1En = new QPushButton(groupBox_12);
        btnVpp1Vnn1En->setObjectName(QStringLiteral("btnVpp1Vnn1En"));
        btnVpp1Vnn1En->setFont(font3);

        gridLayout_13->addWidget(btnVpp1Vnn1En, 4, 0, 1, 1);

        btnVpp1Vnn1Dis = new QPushButton(groupBox_12);
        btnVpp1Vnn1Dis->setObjectName(QStringLiteral("btnVpp1Vnn1Dis"));
        btnVpp1Vnn1Dis->setFont(font3);

        gridLayout_13->addWidget(btnVpp1Vnn1Dis, 5, 0, 1, 1);

        btnVpp2Vnn2En = new QPushButton(groupBox_12);
        btnVpp2Vnn2En->setObjectName(QStringLiteral("btnVpp2Vnn2En"));
        btnVpp2Vnn2En->setFont(font3);

        gridLayout_13->addWidget(btnVpp2Vnn2En, 6, 0, 1, 1);

        btnVpp2Vnn2Dis = new QPushButton(groupBox_12);
        btnVpp2Vnn2Dis->setObjectName(QStringLiteral("btnVpp2Vnn2Dis"));
        btnVpp2Vnn2Dis->setFont(font3);

        gridLayout_13->addWidget(btnVpp2Vnn2Dis, 7, 0, 1, 1);


        gridLayout_16->addWidget(groupBox_12, 1, 2, 1, 1);

        groupBox_11 = new QGroupBox(groupBox_9);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setMaximumSize(QSize(16777215, 259));
        gridLayout_12 = new QGridLayout(groupBox_11);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        btnCompileInfo = new QPushButton(groupBox_11);
        btnCompileInfo->setObjectName(QStringLiteral("btnCompileInfo"));
        btnCompileInfo->setFont(font3);

        gridLayout_10->addWidget(btnCompileInfo, 0, 0, 1, 1);

        btnFwVersion = new QPushButton(groupBox_11);
        btnFwVersion->setObjectName(QStringLiteral("btnFwVersion"));
        btnFwVersion->setFont(font3);

        gridLayout_10->addWidget(btnFwVersion, 1, 0, 1, 1);

        btnRdHwVersion = new QPushButton(groupBox_11);
        btnRdHwVersion->setObjectName(QStringLiteral("btnRdHwVersion"));
        btnRdHwVersion->setFont(font3);

        gridLayout_10->addWidget(btnRdHwVersion, 2, 0, 1, 1);

        btnWrHwVersion = new QPushButton(groupBox_11);
        btnWrHwVersion->setObjectName(QStringLiteral("btnWrHwVersion"));
        btnWrHwVersion->setFont(font3);

        gridLayout_10->addWidget(btnWrHwVersion, 3, 0, 1, 1);

        btnTempInfo = new QPushButton(groupBox_11);
        btnTempInfo->setObjectName(QStringLiteral("btnTempInfo"));
        btnTempInfo->setFont(font3);

        gridLayout_10->addWidget(btnTempInfo, 4, 0, 1, 1);

        btnPowerInfo = new QPushButton(groupBox_11);
        btnPowerInfo->setObjectName(QStringLiteral("btnPowerInfo"));
        btnPowerInfo->setFont(font3);

        gridLayout_10->addWidget(btnPowerInfo, 5, 0, 1, 1);

        btnFanInfo = new QPushButton(groupBox_11);
        btnFanInfo->setObjectName(QStringLiteral("btnFanInfo"));
        btnFanInfo->setFont(font3);

        gridLayout_10->addWidget(btnFanInfo, 6, 0, 1, 1);

        btnVoltageInfo = new QPushButton(groupBox_11);
        btnVoltageInfo->setObjectName(QStringLiteral("btnVoltageInfo"));
        btnVoltageInfo->setFont(font3);

        gridLayout_10->addWidget(btnVoltageInfo, 7, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_10);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        lineEditCompInfo = new QLineEdit(groupBox_11);
        lineEditCompInfo->setObjectName(QStringLiteral("lineEditCompInfo"));
        lineEditCompInfo->setFont(font3);

        gridLayout_11->addWidget(lineEditCompInfo, 0, 0, 1, 1);

        lineEditFwVersion = new QLineEdit(groupBox_11);
        lineEditFwVersion->setObjectName(QStringLiteral("lineEditFwVersion"));
        lineEditFwVersion->setFont(font3);

        gridLayout_11->addWidget(lineEditFwVersion, 1, 0, 1, 1);

        lineEditRdHwVersion = new QLineEdit(groupBox_11);
        lineEditRdHwVersion->setObjectName(QStringLiteral("lineEditRdHwVersion"));
        lineEditRdHwVersion->setFont(font3);

        gridLayout_11->addWidget(lineEditRdHwVersion, 2, 0, 1, 1);

        lineEditWrHwVersion = new QLineEdit(groupBox_11);
        lineEditWrHwVersion->setObjectName(QStringLiteral("lineEditWrHwVersion"));
        lineEditWrHwVersion->setFont(font3);

        gridLayout_11->addWidget(lineEditWrHwVersion, 3, 0, 1, 1);

        lineEditTempInfo = new QLineEdit(groupBox_11);
        lineEditTempInfo->setObjectName(QStringLiteral("lineEditTempInfo"));
        lineEditTempInfo->setFont(font3);

        gridLayout_11->addWidget(lineEditTempInfo, 4, 0, 1, 1);

        lineEditPowerInfo = new QLineEdit(groupBox_11);
        lineEditPowerInfo->setObjectName(QStringLiteral("lineEditPowerInfo"));
        lineEditPowerInfo->setFont(font3);

        gridLayout_11->addWidget(lineEditPowerInfo, 5, 0, 1, 1);

        lineEditFanInfo = new QLineEdit(groupBox_11);
        lineEditFanInfo->setObjectName(QStringLiteral("lineEditFanInfo"));
        lineEditFanInfo->setFont(font3);
        lineEditFanInfo->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(lineEditFanInfo, 6, 0, 1, 1);

        lineEditVoltageInfo = new QLineEdit(groupBox_11);
        lineEditVoltageInfo->setObjectName(QStringLiteral("lineEditVoltageInfo"));
        lineEditVoltageInfo->setFont(font3);

        gridLayout_11->addWidget(lineEditVoltageInfo, 7, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_11);


        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_16->addWidget(groupBox_11, 1, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_9);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setMaximumSize(QSize(16777215, 800));
        gridLayout_2 = new QGridLayout(groupBox_8);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chartView = new QChartView(groupBox_8);
        chartView->setObjectName(QStringLiteral("chartView"));
        chartView->setFont(font3);

        gridLayout_2->addWidget(chartView, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnStart = new QPushButton(groupBox_8);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setFont(font3);

        horizontalLayout_3->addWidget(btnStart);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_16->addWidget(groupBox_8, 0, 0, 1, 3);


        gridLayout_9->addWidget(groupBox_9, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Widget", "Basic Debug Area", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "Port Config", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Serial Port", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Baund Rate", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "Data Bit", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "Stop Bit", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "Parity", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "Flow Ctrl", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("Widget", "Open", Q_NULLPTR));
        btnClose->setText(QApplication::translate("Widget", "Close", Q_NULLPTR));
        btnScan->setText(QApplication::translate("Widget", "Scan", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "Receive Config", Q_NULLPTR));
        radioRevHex->setText(QApplication::translate("Widget", "Hex", Q_NULLPTR));
        radioRevAssic->setText(QApplication::translate("Widget", "Assic", Q_NULLPTR));
        chkRevDisplayTime->setText(QApplication::translate("Widget", "Display Time", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "Send Config", Q_NULLPTR));
        radioSendHex->setText(QApplication::translate("Widget", "Hex", Q_NULLPTR));
        chkSendRepeat->setText(QApplication::translate("Widget", "Repeat Send", Q_NULLPTR));
        radioSendAssic->setText(QApplication::translate("Widget", "Assic", Q_NULLPTR));
        chkNewLine->setText(QApplication::translate("Widget", "New Line", Q_NULLPTR));
        spinRepatTime->setSuffix(QApplication::translate("Widget", "Ms", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Widget", "Send", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        btnSend->setText(QApplication::translate("Widget", "Send", Q_NULLPTR));
        btnClearRev->setText(QApplication::translate("Widget", "Receive Area Clear", Q_NULLPTR));
        btnClearSend->setText(QApplication::translate("Widget", "Send Area Clear", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Widget", "Receive", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Widget", "Function Debug Area", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("Widget", "Adjust Voltage", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "VPP1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spinBoxVpp1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        spinBoxVpp1->setPrefix(QString());
        label_17->setText(QApplication::translate("Widget", "VNN1", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "VPP2", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "VNN2", Q_NULLPTR));
        btnGetVol->setText(QApplication::translate("Widget", "Get Voltage", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "VPP1", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "VNN1", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "VPP2", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "VNN2", Q_NULLPTR));
        btnSetHv->setText(QApplication::translate("Widget", "Set Hv ", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "VPP1", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "VNN1", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "P_CW", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "N_CW", Q_NULLPTR));
        btnSetCw->setText(QApplication::translate("Widget", "Set Cw", Q_NULLPTR));
        groupBox_12->setTitle(QApplication::translate("Widget", "Command", Q_NULLPTR));
        btnSleep->setText(QApplication::translate("Widget", "Sleep", Q_NULLPTR));
        btnWeakup->setText(QApplication::translate("Widget", "Weakup", Q_NULLPTR));
        btnRestart->setText(QApplication::translate("Widget", "Restart", Q_NULLPTR));
        btnUpgrade->setText(QApplication::translate("Widget", "Upgrade", Q_NULLPTR));
        btnVpp1Vnn1En->setText(QApplication::translate("Widget", "VPP1VNN1_EN", Q_NULLPTR));
        btnVpp1Vnn1Dis->setText(QApplication::translate("Widget", "VPP1VNN1_DIS", Q_NULLPTR));
        btnVpp2Vnn2En->setText(QApplication::translate("Widget", "VPP2VNN2_EN", Q_NULLPTR));
        btnVpp2Vnn2Dis->setText(QApplication::translate("Widget", "VPP2VNN2_DIS", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("Widget", "Info Display", Q_NULLPTR));
        btnCompileInfo->setText(QApplication::translate("Widget", "\347\274\226\350\257\221\346\227\266\351\227\264", Q_NULLPTR));
        btnFwVersion->setText(QApplication::translate("Widget", "\345\233\272\344\273\266\347\211\210\346\234\254", Q_NULLPTR));
        btnRdHwVersion->setText(QApplication::translate("Widget", "\350\257\273\347\241\254\347\211\210\346\234\254", Q_NULLPTR));
        btnWrHwVersion->setText(QApplication::translate("Widget", "\345\206\231\347\241\254\347\211\210\346\234\254", Q_NULLPTR));
        btnTempInfo->setText(QApplication::translate("Widget", "\346\270\251\345\272\246\344\277\241\346\201\257", Q_NULLPTR));
        btnPowerInfo->setText(QApplication::translate("Widget", "\347\224\265\346\272\220\344\277\241\346\201\257", Q_NULLPTR));
        btnFanInfo->setText(QApplication::translate("Widget", "\351\243\216\346\211\207\344\277\241\346\201\257", Q_NULLPTR));
        btnVoltageInfo->setText(QApplication::translate("Widget", "\347\224\265\345\216\213\350\257\273\345\217\226", Q_NULLPTR));
        lineEditFanInfo->setText(QApplication::translate("Widget", "Fan1 Speed Fan2 Speed Fan3 Speed Fan4 Speed Fan5 Speed ", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Widget", "Chart Area", Q_NULLPTR));
        btnStart->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
