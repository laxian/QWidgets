#ifndef BATTERY_H
#define BATTERY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class Demo : public QMainWindow

{
    Q_OBJECT

public:
    Demo(QWidget *parent = nullptr);
    ~Demo();


private:
    Ui::MainWin *ui;
};

#endif // BATTERY_H
