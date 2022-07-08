#ifndef BATTERY_H
#define BATTERY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Battery; }
QT_END_NAMESPACE

class Battery : public QMainWindow

{
    Q_OBJECT

public:
    Battery(QWidget *parent = nullptr);
    ~Battery();


private:
    Ui::Battery *ui;
};

#endif // BATTERY_H
