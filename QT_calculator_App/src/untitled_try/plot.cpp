#include "plot.h"
#include "ui_plot.h"

QString mainFunction;

plot::plot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plot)
{
    ui->setupUi(this);
    connect(xMax, QOverload<int>::of(&QSpinBox::valueChanged), this, &plot::on_xMax_valueChanged);
    connect(xMin, QOverload<int>::of(&QSpinBox::valueChanged), this, &plot::on_xMin_valueChanged);
    connect(yMax, QOverload<int>::of(&QSpinBox::valueChanged), this, &plot::on_yMax_valueChanged);
    connect(yMin, QOverload<int>::of(&QSpinBox::valueChanged), this, &plot::on_yMin_valueChanged);
}


void plot::slotReceiveFunction(QString func, int xMin_value, int xMax_value, int yMin_value, int yMax_value) {
    ui->label->setText(func);

    mainFunction =  func;

    std::string stdString = mainFunction.toStdString();
    const char* cString = stdString.c_str();

    std::function<double(double)> myFunction = [=](double x) { return strtod(s21_smart_calc(cString, x), nullptr); };

    slotReplotGraph(myFunction, xMin_value, xMax_value, yMin_value, yMax_value);
}

void plot::slotReplotGraph(std::function<double(double)> function, int xMin_value, int xMax_value, int yMin_value, int yMax_value) {
    h = 0.1;

    ui->xMax->setValue(xMax_value);
    ui->xMin->setValue(xMin_value);
    ui->yMax->setValue(yMax_value);
    ui->yMin->setValue(yMin_value);

    ui->widget->xAxis->setRange(xMin_value,xMax_value);
    ui->widget->yAxis->setRange(yMin_value, yMax_value);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    for (X = xMin_value; X <= xMax_value; X += h){
        x.push_back(X);
        y.push_back(function(X));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->replot();
}

plot::~plot()
{
    delete ui;
}

void plot::on_xMax_valueChanged(int arg1)
{
    std::string stdString = mainFunction.toStdString();
    const char* cString = stdString.c_str();

    std::function<double(double)> myFunction = [=](double x) { return strtod(s21_smart_calc(cString, x), nullptr); };
    slotReplotGraph(myFunction, ui->xMin->value(), arg1, ui->yMin->value(), ui->yMax->value());
}


void plot::on_xMin_valueChanged(int arg1)
{
    std::string stdString = mainFunction.toStdString();
    const char* cString = stdString.c_str();

    std::function<double(double)> myFunction = [=](double x) { return strtod(s21_smart_calc(cString, x), nullptr); };
    slotReplotGraph(myFunction, arg1, ui->xMax->value(), ui->yMin->value(), ui->yMax->value());
}


void plot::on_yMin_valueChanged(int arg1)
{
    std::string stdString = mainFunction.toStdString();
    const char* cString = stdString.c_str();

    std::function<double(double)> myFunction = [=](double x) { return strtod(s21_smart_calc(cString, x), nullptr); };
    slotReplotGraph(myFunction, ui->xMin->value(), ui->xMax->value(), arg1, ui->yMax->value());
}


void plot::on_yMax_valueChanged(int arg1)
{
    std::string stdString = mainFunction.toStdString();
    const char* cString = stdString.c_str();

    std::function<double(double)> myFunction = [=](double x) { return strtod(s21_smart_calc(cString, x), nullptr); };
    slotReplotGraph(myFunction, ui->xMin->value(), ui->xMax->value(), ui->yMin->value(), arg1);
}


