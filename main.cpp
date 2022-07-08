#include "battery.h"
#include "qwifi.h"

#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Battery w;
//    w.setWindowTitle("Battery");
//    w.show();

//    QMainWindow w;
//    QVBoxLayout layout;
//    w.setLayout(&layout);
    QWifi qwifi;
//    qwifi.setFixedSize(100, 100);
//    layout.addWidget(&qwifi);
    qwifi.show();
    qwifi.setLevel(3);
    qwifi.setMaxLevel(5);
    QColor color = Qt::green;
    qwifi.setLevelColor(color);
    QColor color2 = Qt::white;
    qwifi.setLevelDefaultColor(color2);
//    w.show();
    return a.exec();
}
