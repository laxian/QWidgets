#pragma execution_character_set("utf-8")

#include <QVBoxLayout>
#include <QPushButton>
#include "mainwin.h"
#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"
#include "ui_mainwin.h"
#include "qbattery/qcharge.h"
#include "qwifi/qwifi.h"

Demo::Demo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)

{
    ui->setupUi(this);       //驱动UI设计师
//    setGeometry(0, 0, 200, 200);  //固定大小
    auto *vlayout = new QVBoxLayout;

    auto *qwifi = new QWifi;
    qwifi->setFixedSize(100, 100);
    qwifi->setLevel(5);
    qwifi->setMaxLevel(6);
    QColor color = Qt::green;
    qwifi->setLevelColor(color);
    QColor color2 = Qt::white;
    qwifi->setLevelDefaultColor(color2);

    QPalette pal(qwifi->palette());
    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::black);
    qwifi->setAutoFillBackground(true);
    qwifi->setPalette(pal);

    vlayout->addWidget(qwifi);

    auto *qcharge = new QCharge;
    qcharge->setFixedSize(60, 50);
    QPalette pal2(qcharge->palette());
    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::gray);
    qcharge->setAutoFillBackground(true);
    qcharge->setPalette(pal2);

    vlayout->addWidget(qcharge);
    this->centralWidget()->setLayout(vlayout);
}

Demo::~Demo()
{

    delete ui;
}
