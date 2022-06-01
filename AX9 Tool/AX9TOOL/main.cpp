#include "widget.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog *dlgLogin = new Dialog;

    if(dlgLogin->exec() == QDialog::Accepted)
    {
        Widget w;
        w.show();
        return a.exec();
    }
    else
    {
        delete dlgLogin;

        return 0;
    }
}
