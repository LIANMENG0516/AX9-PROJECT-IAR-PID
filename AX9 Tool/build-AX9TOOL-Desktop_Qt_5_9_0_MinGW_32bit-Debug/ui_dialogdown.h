/********************************************************************************
** Form generated from reading UI file 'dialogdown.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDOWN_H
#define UI_DIALOGDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogDown
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *DialogDown)
    {
        if (DialogDown->objectName().isEmpty())
            DialogDown->setObjectName(QStringLiteral("DialogDown"));
        DialogDown->resize(719, 223);
        progressBar = new QProgressBar(DialogDown);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(20, 140, 681, 23));
        QFont font;
        font.setKerning(true);
        progressBar->setFont(font);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        pushButton = new QPushButton(DialogDown);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 180, 93, 28));
        pushButton_2 = new QPushButton(DialogDown);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 180, 93, 28));
        pushButton_3 = new QPushButton(DialogDown);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(610, 180, 93, 28));
        lineEdit = new QLineEdit(DialogDown);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 100, 681, 21));
        label = new QLabel(DialogDown);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 20, 431, 61));
        QFont font1;
        font1.setPointSize(33);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        retranslateUi(DialogDown);
        QObject::connect(pushButton_3, SIGNAL(clicked()), DialogDown, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogDown);
    } // setupUi

    void retranslateUi(QDialog *DialogDown)
    {
        DialogDown->setWindowTitle(QApplication::translate("DialogDown", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        progressBar->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        progressBar->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        progressBar->setFormat(QApplication::translate("DialogDown", "%p%", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DialogDown", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("DialogDown", "\345\274\200\345\247\213\344\270\213\350\275\275", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("DialogDown", "\345\205\263\351\227\255\347\252\227\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("DialogDown", "\345\207\206\345\244\207\344\270\213\350\275\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogDown: public Ui_DialogDown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDOWN_H
