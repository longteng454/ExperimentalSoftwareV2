#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>

QButtonGroup *btnGroupDataFormat;
QButtonGroup *btnGroupSendFormat;



//构造函数
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Windows下的COMx的下拉菜单
    QStringList COMList;
    COMList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"<<"COM7"<<"COM8"<<"COM9"<<
                  "COM10"<<"COM11"<<"COM12"<<"COM13"<<"COM14"<<"COM15"<<"COM16";
    ui->comboBoxCOM->addItems(COMList);


    QStringList BaudRateList;
    BaudRateList << "110" << "300" << "600" <<"1200" << "2400" << "4800" << "9600" <<
                    "14400" << "19200" << "38400" << "56000" << "57600" << "115200" <<
                    "128000" << "256000";
    ui -> comboBoxBaudRate -> addItems(BaudRateList);

    QStringList WordLengthList;
    WordLengthList << "8" << "7";
    ui -> comboBoxWordLength ->addItems(WordLengthList);

    QStringList ParityList;
    ParityList << "NONE" << "EVEN" << "ODD" ;
    ui -> comboBoxParity ->addItems(ParityList);

    QStringList StopBitsList;
    StopBitsList << "1" << "2";
    ui -> comboBoxStopBits -> addItems(StopBitsList);


    ui->labelCOM->setText("等待打开COM口");


}


//析构函数
Widget::~Widget()
{
    delete ui;
}

char WordLengthInt = 8;
//打开串口并初始化
void Widget::on_OpenCOM_clicked()
{
    static bool serio_Open=0;//确定串口成功打开的变量
    //windows下的串口操作函数
    QString COMx = ui->comboBoxCOM->currentText();

    QString BaudRate = ui->comboBoxBaudRate->currentText();
    QString WordLength = ui->comboBoxWordLength->currentText();
    QString Parity = ui->comboBoxParity->currentText();
    QString StopBits = ui->comboBoxStopBits->currentText();




    bool ok;
    int BaudRateInt = BaudRate.toInt(&ok,10);    
    int StopBitsInt = StopBits.toInt(&ok,10);

    WordLengthInt = WordLength.toInt(&ok,10);

    s.setPortName(COMx);
    serio_Open = s.open(QIODevice::ReadWrite);
    if(serio_Open == true)
    {

        ui->labelCOM->setText("打开成功"+COMx);
        ui->labelCOM->setTextFormat(Qt::RichText);
        ui->labelCOM->colorCount();

        ui->comboBoxCOM->setEnabled(false);
        ui->comboBoxBaudRate->setEnabled(false);
        ui->comboBoxParity->setEnabled(false);
        ui->comboBoxStopBits->setEnabled(false);
        ui->comboBoxWordLength->setEnabled(false);
    }
    else
    {

        ui->labelCOM->setText("打开失败"+COMx);
        ui->comboBoxCOM->setEnabled(true);
        ui->comboBoxBaudRate->setEnabled(true);
        ui->comboBoxParity->setEnabled(true);
        ui->comboBoxStopBits->setEnabled(true);
        ui->comboBoxWordLength->setEnabled(true);
        return;
    }
    switch (BaudRateInt)
    {
        case 110:
            s.setBaudRate(QSerialPort::Baud110);
            break;
        case 300:
            s.setBaudRate(QSerialPort::Baud300);
            break;
        case 600:
            s.setBaudRate(QSerialPort::Baud600);
            break;
        case 1200:
            s.setBaudRate(QSerialPort::Baud1200);
            break;
        case 2400:
            s.setBaudRate(QSerialPort::Baud2400);
            break;
        case 4800:
            s.setBaudRate(QSerialPort::Baud4800);
            break;
        case 9600:
            s.setBaudRate(QSerialPort::Baud9600);
            break;
        case 14400:
            s.setBaudRate(QSerialPort::Baud14400);
            break;
        case 19200:
            s.setBaudRate(QSerialPort::Baud19200);
            break;
        case 38400:
            s.setBaudRate(QSerialPort::Baud38400);
            break;
        case 56000:
            s.setBaudRate(QSerialPort::Baud56000);
            break;
        case 57600:
            s.setBaudRate(QSerialPort::Baud57600);
            break;
        case 115200:
            s.setBaudRate(QSerialPort::Baud115200);
            break;
        case 128000:
            s.setBaudRate(QSerialPort::Baud128000);
            break;
        case 256000:
            s.setBaudRate(QSerialPort::Baud256000);
            break;
    }

    switch(WordLengthInt)
    {
        case 7:
            s.setDataBits(QSerialPort::Data7);
        break;
        case 8:
            s.setDataBits(QSerialPort::Data8);
        break;
    }

    switch(StopBitsInt)
    {
        case 1:
            s.setStopBits(QSerialPort::OneStop);
        break;
        case 2:
            s.setStopBits(QSerialPort::TwoStop);
        break;
    }

  if(Parity == "ODD")
    s.setParity(QSerialPort::OddParity);
  else if(Parity == "EVEN")
        s.setParity(QSerialPort::EvenParity);
  else if(Parity == "NONE")
        s.setParity(QSerialPort::NoParity);


    //windows下的槽函数
    connect(&s,SIGNAL(readyRead()),this,SLOT(forDataComing()));//槽函数，串口接收处理函数

    ui->OpenCOM->setEnabled(false);
    ui->closeCom->setEnabled(true);
}


//串口关闭
void Widget::on_closeCom_clicked()
{
    QString COMx = ui->comboBoxCOM->currentText();
    s.close();
    ui->labelCOM->setText("成功关闭"+COMx);
    ui->closeCom->setEnabled(false);
    ui->OpenCOM->setEnabled(true);
    ui->comboBoxCOM->setEnabled(true);
    ui->comboBoxBaudRate->setEnabled(true);
    ui->comboBoxParity->setEnabled(true);
    ui->comboBoxStopBits->setEnabled(true);
    ui->comboBoxWordLength->setEnabled(true);
}







char*     Receivedata = (char*)calloc(100,sizeof(char));//设立一块缓冲区，存取从串口度读回来的数据

//串口接收槽函数
void Widget::forDataComing(void)
{

        qDebug("%c",'\n');

}

