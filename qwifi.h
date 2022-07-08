//
// Created by leo chou on 2022/7/8.
//

#ifndef BATTERY_QWIFI_H
#define BATTERY_QWIFI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class QWifi; }
QT_END_NAMESPACE

class QWifi : public QWidget {
Q_OBJECT

public:
    explicit QWifi(QWidget *parent = nullptr);

    ~QWifi() override;

    void setLevel(quint8 level);

    void setMaxLevel(quint8 level);

    void setLevelColor(QColor&);

    void setLevelDefaultColor(QColor&);

protected:
    void paintEvent(QPaintEvent *);

    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::QWifi *ui;

    void drawWifi(QPainter *pPainter);

    qint16 m_width = 4;
    qint16 m_gap = 4;
    QColor m_color = Qt::white;
    QColor m_color_bg = Qt::gray;

    qint16 m_left_margin;

    qint8 m_max_level = 4;
    // 默认4级
    qint8 m_level = 2;

    void update_width_gap_margin();
};


#endif //BATTERY_QWIFI_H
