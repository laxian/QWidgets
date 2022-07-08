#include "battery.h"
#include "qwifi/qwifi.h"
#include "qbattery/qcharge.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Battery w;
    w.setWindowTitle("Battery");
    w.show();

    return a.exec();
}
