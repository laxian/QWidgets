//
// Created by leo chou on 2022/7/8.
//

#ifndef BATTERY_QCHARGE_H
#define BATTERY_QCHARGE_H

#include <QWidget>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class QCharge; }
QT_END_NAMESPACE

class QCharge : public QWidget {
Q_OBJECT

public:
    explicit QCharge(QWidget *parent = nullptr);

    ~QCharge() override;

protected:
    void paintEvent(QPaintEvent *);
    void drawBorder(QPainter *painter);
    void drawBg(QPainter *painter);
    void drawText(QPainter *painter);

private slots:
    void inputValue();

private:
    Ui::QCharge *ui;
    double _currentValue;
    int _margin;
    double _minValue;                //最小值
    double _maxValue;                //最大值
    bool _isForward;                 //是否往前移
    int _batteryWidth;

    int _batteryHeight;
    QRectF batteryRect;             //电池主体区域

    QTimer *inputTimer;                  //绘制定时器
};


#endif //BATTERY_QCHARGE_H
