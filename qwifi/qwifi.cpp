//
// Created by leo chou on 2022/7/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_QWifi.h" resolved

#include <QPainter>
#include <QDebug>
#include "qwifi.h"
#include "ui_QWifi.h"


QWifi::QWifi(QWidget *parent) :
        QWidget(parent), ui(new Ui::QWifi) {
    ui->setupUi(this);

    update_width_gap_margin();
}

void QWifi::update_width_gap_margin() {
    m_width = width() / (m_max_level * 2 - 1);
    m_gap = m_width;
    m_left_margin = m_width / 2;
}

QWifi::~QWifi() {
    delete ui;
}

void QWifi::paintEvent(QPaintEvent *ev) {

    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    drawWifi(&painter);
}

void QWifi::drawWifi(QPainter *pPainter) {
    QPainter painter(this);
    QRect rect(0,0,width(),height());
    //设置当前图形视图窗口
//    painter.setViewport(rect);
//    painter.setWindow(0,0,0,50);
    //抗锯齿的效果
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    QPen pen;
    pen.setWidth(m_width);
    pen.setColor(m_color);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
//    QBrush brush;
//    brush.setColor(Qt::green);
//    brush.setStyle(Qt::SolidPattern);
//    painter.setBrush(brush);
//    rect.setRect(1,1,2,24);
//    painter.drawRect(rect);
//    rect.setRect(9,1,2,48);
//    painter.drawRect(rect);
//    rect.setRect(17,1,2,72);
//    painter.drawRect(rect);

//    QLineF line(m_left_margin, height(), m_left_margin, 3*height()/4);
//    painter.drawLine(line);
//    line.setLine(1*m_width+m_gap+m_left_margin, height(), 1*m_width+m_gap+m_left_margin, 2* height()/4);
//    painter.drawLine(line);
//    line.setLine(2*m_width+2*m_gap+m_left_margin, height(), 2*m_width+2*m_gap+m_left_margin, height()/4);
//    painter.drawLine(line);
//    line.setLine(3*m_width+3*m_gap+m_left_margin, height(), 3*m_width+3*m_gap+m_left_margin, 0);
//    painter.drawLine(line);

    QLineF line;
    for(int i=0; i<m_max_level; i++) {
        if (i+1 > m_level) {
            QPen qPen = painter.pen();
            qPen.setColor(m_color_bg);
            painter.setPen(qPen);
        }
        // 第i次：
        qint16 x = m_left_margin + i*(m_width+m_gap);
        qint16 y = height();
        qint16 h = (i+1) * height()/m_max_level;
        qint16 y2 = y-h;
        line.setLine(x,y,x,y2);
        qDebug()<< line;
        painter.drawLine(line);
    }

}

void QWifi::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    m_width = width()/7;
    m_gap = m_width;
    m_left_margin = m_width/2;
    update();
}

void QWifi::setLevel(quint8 level) {
    if (m_level == level) {
        return;
    }
    if (level > m_max_level) {
        m_level = m_max_level;
    } else if (level < 0) {
        m_level = 0;
    } else {
        m_level = level;
    }
    update();
}

void QWifi::setMaxLevel(quint8 level) {
    this->m_max_level = level;
    update_width_gap_margin();
    update();
}

void QWifi::setLevelColor(QColor &color) {
    this->m_color = color;
    update();
}

void QWifi::setLevelDefaultColor(QColor &color) {
    this->m_color_bg = color;
    update();
}
