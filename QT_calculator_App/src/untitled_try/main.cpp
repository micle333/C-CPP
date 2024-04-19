#include "mainwindow.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QString rootPath = QCoreApplication::applicationFilePath() + "/source/16201-2001.png";
//    qDebug() << "Root path:" << rootPath;


    w.show();

    return a.exec();
}
