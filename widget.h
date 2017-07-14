#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <Qtimer.h>
#include <QDatetime>
#include <QTextEdit>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_OpenCOM_clicked();
    void on_closeCom_clicked();

public slots:
    void forDataComing(void);//串口接收函数

private:
    Ui::Widget *ui;
    QSerialPort s;
    QTimer SendTime;
    QString RepeatData;
};

#endif // WIDGET_H
