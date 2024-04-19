#include "mainwindow.h"
#include "smart_calc.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QGraphicsDropShadowEffect>
#include <QThread>
#include "plot.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digit_numbers()));

    connect(ui->buttonBox->button(QDialogButtonBox::Reset),SIGNAL(clicked()), this, SLOT(handleResetButton_credit()));
    connect(ui->buttonBox_2->button(QDialogButtonBox::Reset),SIGNAL(clicked()), this, SLOT(handleResetButton_deposit()));
}


void MainWindow::handleResetButton_credit()
{
    ui->SummaCredit->setValue(0);
    ui->months->setValue(0);
    ui->persent->setValue(0);
    ui->month_pay->setText("0");
    ui->label_10->setText("0");
    ui->label_11->setText("0");
}


void MainWindow::handleResetButton_deposit()
{
    ui->SummaDeposit->setValue(0);
    ui->months_deposit->setValue(0);
    ui->persent_deposit->setValue(0);
    ui->rep->setValue(0);
    ui->with->setValue(0);
    ui->accured_interest->setText("0");
    ui->tax_amount->setText("0");
    ui->deposit_amount_2->setText("0");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_numbers(){

    QPushButton *button = (QPushButton *)sender();
    if (ui->result_show->text() == "0"){
        ui->result_show->setText(button->text());
    } else {
        QString currentText = ui->result_show->text();
        QChar prevChar =  currentText.at( currentText.length() - 1);
        if (inputX == 1 && prevChar == ' '){
            ui->result_show->setText(button->text());
        } else {
            if ( prevChar != ')' && prevChar != 'x'){
                ui->result_show->setText(ui->result_show->text() + button->text());
            }
        }
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    int startPos;
    QString currentText = ui->result_show->text();
    if (currentText.isEmpty()) {
        ui->result_show->setText("0.");
    } else {
        int len = currentText.length();
        QChar lastChar = currentText.at(len - 1);
        if (lastChar.isDigit()) {
            startPos = currentText.lastIndexOf(QRegularExpression("[^0-9\\.]")) + 1;
            QString currentNumber = currentText.mid(startPos);

            if (!currentNumber.contains('.')) {
                ui->result_show->setText(currentText + ".");
            }
        }
    }
}


void MainWindow::on_pushButton_plus_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')' || lastChar == 'x') {
            if (currentText.length() == 1 && lastChar == '0'){}
            else {
                QString newLabel = currentText + "+";
                ui->result_show->setText(newLabel);
            }
        }
    }
}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_minus_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')'  || lastChar == '(' || lastChar == 'x') {
            if (currentText.length() == 1 && lastChar == '0'){
                ui->result_show->setText("-");
            }
            else {
                QString newLabel = currentText + "-";
                ui->result_show->setText(newLabel);
            }
        } else {
            if (lastChar == '+' || lastChar == '*' || lastChar == '/'){
                QString newLabel = currentText + "(-";
                ui->result_show->setText(newLabel);
            }
        }
    }
}


void MainWindow::on_pushButton_mult_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')' || lastChar == 'x') {
            if (currentText.length() == 1 && lastChar == '0'){}
            else {
                QString newLabel = currentText + "*";
                ui->result_show->setText(newLabel);
            }
        }
    }
}


void MainWindow::on_pushButton_division_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')' || lastChar == 'x') {
            if (currentText.length() == 1 && lastChar == '0'){}
            else {
                QString newLabel = currentText + "/";
                ui->result_show->setText(newLabel);
            }
        }
    }
}


void MainWindow::on_pushButton_grapsh_2_clicked()
{
    QString currentText = ui->result_show->text();
    currentText.chop(1);
    if (currentText.isEmpty()){
        ui->result_show->setText("0");
    } else {
        ui->result_show->setText(currentText);
    }

}


void MainWindow::on_pushButton_cos_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "cos(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "cos(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_sin_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "sin(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "sin(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_tng_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "tg(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "tg(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_ctg_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "ctg(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "ctg(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_acos_clicked()
{    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "acos(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "acos(";
                ui->result_show->setText(newLabel);
        }
    }

}


void MainWindow::on_pushButton_asin_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "asin(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "asin(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_atan_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "atan(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "atan(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_sqrt_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "sqrt(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "sqrt(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_ln_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "ln(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "ln(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_log_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "log(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "log(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_closed_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')' || lastChar == 'x') {
                int openingBracketCount = currentText.count('(');
                int canceleBracketCount = currentText.count(')');
                if (openingBracketCount - canceleBracketCount > 0){
                QString newLabel = currentText + ")";
                ui->result_show->setText(newLabel);
                }
        }
    }
}


void MainWindow::on_pushButton_open_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar prevChar =  currentText.at( currentText.length() - 1);
        if (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '^' || prevChar == '/' || prevChar == '(') {
                QString newLabel = currentText + "(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && prevChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "(";
                ui->result_show->setText(newLabel);
        }
    } else {
        if (inputX == 0){
        QString newLabel ="(";
        ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_degree_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (lastChar.isDigit() || lastChar == ')' || lastChar == 'x') {
                if (currentText.length() == 1 && lastChar == '0'){}
                else {
                QString newLabel = currentText + "^";
                ui->result_show->setText(newLabel);
                }
        }
    }
}


void MainWindow::on_pushButton_module_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty() && inputX == 0) {
        QChar lastChar = currentText.at(currentText.length() - 1);
        if (!lastChar.isDigit() && lastChar != ')' && lastChar != '.' && lastChar != 'x') {
                QString newLabel = currentText + "mod(";
                ui->result_show->setText(newLabel);
        } else if (currentText.length() == 1 && lastChar == '0'){
                currentText.chop(1);
                QString newLabel = currentText + "mod(";
                ui->result_show->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_x_clicked()
{
    if (ui->result_show->text() == "0"){
        ui->result_show->setText("x");
    } else {
        QString currentText = ui->result_show->text();
        QChar prevChar =  currentText.at( currentText.length() - 1);
        if ( prevChar != ')' && prevChar != 'x'  && !prevChar.isDigit()){
            ui->result_show->setText(ui->result_show->text() + "x");
        }

    }
}


void MainWindow::on_pushButton_equal_clicked()
{
    QString currentText = ui->result_show->text();
    if (!currentText.isEmpty()) {
        if (inputX == 1){
            xvalue = ui->result_show->text();
            inputX = 0;

            std::string stdString = mainString.toStdString();
            const char* cString = stdString.c_str();

            std::string xvalueStr = xvalue.toStdString();
            double x = strtod(xvalueStr.c_str(), nullptr);

            ui->result_show->setText(s21_smart_calc(cString, x));
        } else if (currentText.contains('x') && inputX == 0){
            mainString =  currentText;
            inputX = 1;
            ui->result_show->setText("Put x:                          ");
        } else {
            std::string stdString = currentText.toStdString();
            const char* cString = stdString.c_str();
            ui->result_show->setText((s21_smart_calc(cString, 0)));
        }

    }
}

void MainWindow::on_pushButton_grapsh_clicked()
{
    plot *plotting = new plot();

    QString currentText = ui->result_show->text();
    mainString =  currentText;
    connect(this, &MainWindow::signalSendFunction, plotting, &plot::slotReceiveFunction);
    emit signalSendFunction(currentText , -5,5,-5,5);

    plotting->show();
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->SummaCredit->selectAll();
    ui->months->selectAll();
    ui->persent->selectAll();
}


void MainWindow::on_buttonBox_accepted()
{
    QString S = QString::number(ui->SummaCredit->value());
    QString P = QString::number(ui->persent->value());
    double Per = P.toDouble()/100;
    QString N = QString::number(ui->months->value());

    if (ui->comboBox->currentIndex()== 0){

        QString summery = S + "*" + QString::number(Per) + "/12*((1+" + QString::number(Per) + "/12)^" + N + ")/(((1+" + QString::number(Per) + "/12)^" + N + ")-1)";
        std::string stdString = summery.toStdString();
        const char* cString = stdString.c_str();
        ui->month_pay->setText(s21_smart_calc(cString, 0));


        QString overpayment = "(" + S + "*" + QString::number(Per) + "/12*((1+" + QString::number(Per) + "/12)^" + N + ")/(((1+" + QString::number(Per) + "/12)^" + N + ")-1))*" + N + "-" + S;
        std::string OverPay = overpayment.toStdString();
        const char* cOverPay = OverPay.c_str();
        ui->label_10->setText(s21_smart_calc(cOverPay, 0));

        QString total = "(" + S + "*" + QString::number(Per) + "/12*((1+" + QString::number(Per) + "/12)^" + N + ")/(((1+" + QString::number(Per) + "/12)^" + N + ")-1))*" + N;
        std::string Total = total.toStdString();
        const char* cTotal = Total.c_str();
        QString ostat =  ".00";
        ui->label_11->setText(s21_smart_calc(cTotal, 0) + ostat);

    } else if (ui->comboBox->currentIndex()== 1){
        QString DEPi;
        double ostat = S.toDouble();
        double summ = 0;
        double main_plat = ostat/N.toDouble();
        double first_pay = 0;
        double last_pay = 0;



        for (int i = 1; i <= N.toInt(); i++){


            DEPi = S + "/" + N + "+" + QString::number(ostat) + "*" + QString::number(Per) + "/" + N;
            std::string depi = DEPi.toStdString();
            const char* cDepi = depi.c_str();
            ostat -= main_plat;
            summ = summ + s21_smart_calc_double(cDepi, 0);
            if (i == 1) first_pay = s21_smart_calc_double(cDepi, 0);
            if (i == N.toInt()) last_pay = s21_smart_calc_double(cDepi, 0);

        }
        ui->month_pay->setText(QString::number(first_pay,'d', 1) + " ... " + QString::number(last_pay,'d', 1));

        ui->label_10->setText(QString::number(summ -  S.toDouble(),'d', 6));
        ui->label_11->setText(QString::number(summ,'d', 6));
    }

}


void MainWindow::on_buttonBox_2_accepted()
{
    QString S = QString::number(ui->SummaDeposit->value());
    QString P = QString::number(ui->persent_deposit->value());
    QString N = QString::number(ui->months_deposit->value());

    double Su = S.toDouble();
    double Per = P.toDouble()/100;
    double n = N.toDouble();

        QString Pop = QString::number(ui->rep->value());
        QString Snat = QString::number(ui->with->value());

        double pop = Pop.toDouble();
        double snat = Snat.toDouble();
        int m = N.toInt();
        double repayment = 0;
        double ref = 0;
        double Start_sum = S.toDouble();
        int year_count = 12;
        double year_profit = 0;
        double tax = 0;


        for (int i = 1; i <= m; i++){
            if (ui->capitalization->isChecked()) ref = (Su) * (Per/12);

            Su = Su + pop - snat + ref;
            repayment += (Su) * (Per/12);
            year_profit += (Su) * (Per/12);

            if (i == year_count){
            if (year_profit > 160000) tax += (year_profit -160000) * 0.13;
               year_count += 12;
               year_profit = 0;
            }
        }
        ui->accured_interest->setText(QString::number(repayment,'d', 2));

        ui->tax_amount->setText(QString::number(tax,'d', 2));

        if (!ui->capitalization->isChecked()) ui->deposit_amount_2->setText(QString::number(Start_sum + repayment + (pop - snat) * n,'d', 2));
        else ui->deposit_amount_2->setText(QString::number(Su,'d', 2));

    //}
}



void MainWindow::on_pushButton_13_clicked()
{
        ui->SummaDeposit->selectAll();
        ui->months_deposit->selectAll();
        ui->persent_deposit->selectAll();
        ui->rep->selectAll();
        ui->with->selectAll();
}

