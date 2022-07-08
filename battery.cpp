#pragma execution_character_set("utf-8")

#include <QVBoxLayout>
#include <QPushButton>
#include "battery.h"
#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"
#include "ui_battery.h"
#include "qbattery/qcharge.h"
#include "qwifi/qwifi.h"

Battery::Battery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Battery)

{
    ui->setupUi(this);       //驱动UI设计师
    setGeometry(0, 0, 200, 200);  //固定大小
    auto *vlayout = new QVBoxLayout;

    auto *qwifi = new QWifi;
    qwifi->setFixedSize(50, 50);
    qwifi->setLevel(2);
    qwifi->setMaxLevel(4);
    QColor color = Qt::green;
    qwifi->setLevelColor(color);
    QColor color2 = Qt::white;
    qwifi->setLevelDefaultColor(color2);
    vlayout->addWidget(qwifi);

    auto *qcharge = new QCharge;
    vlayout->addWidget(qcharge);
    this->centralWidget()->setLayout(vlayout);
}

Battery::~Battery()
{

    delete ui;
}
