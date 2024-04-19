#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>

#include <QWidget>
#include <QSpinBox>
#include <functional>

extern "C" {
#include <smart_calc.h>
}


QT_BEGIN_NAMESPACE
namespace Ui {
class plot;
}
QT_END_NAMESPACE

class plot : public QWidget
{
    Q_OBJECT

public:
    explicit plot(QWidget *parent = nullptr);

    ~plot();


private:
    Ui::plot *ui;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x,y;

    QSpinBox* xMin;
    QSpinBox* xMax;
    QSpinBox* yMin;
    QSpinBox* yMax;

public slots:
    // Слот для приема функции
    void slotReplotGraph(std::function<double(double)> func, int xMin_value, int xMax_value, int yMin_value, int yMax_value);
    void slotReceiveFunction(QString func, int xMin_value, int xMax_value, int yMin_value, int yMax_value);

private slots:
    void on_xMax_valueChanged(int arg1);
    void on_xMin_valueChanged(int arg1);
    void on_yMin_valueChanged(int arg1);
    void on_yMax_valueChanged(int arg1);
};

#endif // PLOT_H
