#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("误码率测试");
    w.setWindowFlags(w.windowFlags() &~ (Qt::WindowMaximizeButtonHint));
    w.show();



    return a.exec();
}
