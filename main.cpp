#include "mainwin.h"
#include "qwifi/qwifi.h"
#include "qbattery/qcharge.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demo w;
    w.setWindowTitle("MainWin");
    w.show();

    return a.exec();
}
