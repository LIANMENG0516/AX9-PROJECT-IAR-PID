/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLineEdit *editUser;
    QLabel *label_2;
    QLineEdit *editPassword;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 80, 61, 31));
        editUser = new QLineEdit(Dialog);
        editUser->setObjectName(QStringLiteral("editUser"));
        editUser->setGeometry(QRect(150, 90, 113, 20));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 160, 54, 12));
        editPassword = new QLineEdit(Dialog);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        editPassword->setGeometry(QRect(150, 160, 113, 20));
        editPassword->setEchoMode(QLineEdit::Password);
        btnOk = new QPushButton(Dialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(70, 230, 93, 28));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(220, 230, 93, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        btnOk->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("Dialog", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
