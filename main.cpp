#include "battery.h"
#include "qwifi/qwifi.h"
#include "qbattery/qcharge.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Battery w;
//    w.setWindowTitle("Battery");
//    w.show();

    QMainWindow w;
    QVBoxLayout layout;
    w.setLayout(&layout);

//    QWifi qwifi;
////    qwifi.setFixedSize(100, 100);
////    layout.addWidget(&qwifi);
//    qwifi.show();
//    qwifi.setLevel(3);
//    qwifi.setMaxLevel(5);
//    QColor color = Qt::green;
//    qwifi.setLevelColor(color);
//    QColor color2 = Qt::white;
//    qwifi.setLevelDefaultColor(color2);

    QCharge qcharge;
    qcharge.setGeometry(100,100,100, 100);
    qcharge.show();

    return a.exec();
}
