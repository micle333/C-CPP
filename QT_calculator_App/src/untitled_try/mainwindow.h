#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <functional>
#include <plot.h>

extern "C" {
#include <smart_calc.h>
}


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signalSendFunction(QString func, int xMin_value, int xMax_value, int yMin_value, int yMax_value);



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString mainString;
    QString xvalue;
    int inputX = 0;

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x,y;

private slots:
    void digit_numbers();
    void on_pushButton_dot_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_division_clicked();
    void on_pushButton_grapsh_2_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_tng_clicked();
    void on_pushButton_ctg_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_closed_clicked();
    void on_pushButton_open_clicked();
    void on_pushButton_degree_clicked();
    void on_pushButton_module_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_grapsh_clicked();
    void on_pushButton_12_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_2_accepted();
    void handleResetButton_credit();
    void handleResetButton_deposit();
    void on_pushButton_13_clicked();
};

#endif // MAINWINDOW_H
