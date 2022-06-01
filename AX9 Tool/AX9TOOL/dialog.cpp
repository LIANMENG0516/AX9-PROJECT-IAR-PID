#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Sign In");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnOk_clicked()
{
    this->accept();
}
