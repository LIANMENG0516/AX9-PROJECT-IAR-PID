#ifndef DIALOGDOWN_H
#define DIALOGDOWN_H

#include <QDialog>
#include <QByteArray>

namespace Ui {
class DialogDown;
}

class DialogDown : public QDialog
{
    Q_OBJECT

public:
    QString curPath;

public:
    explicit DialogDown(QWidget *parent = 0);
    ~DialogDown();

private slots:

    void slot_PortData();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogDown *ui;

public:
    QByteArray datArr;

signals:
    void signalClick(QByteArray data);

protected:
    void closeEvent(QCloseEvent *);


};

#endif // DIALOGDOWN_H
