#include <QtGui/QApplication>
#include "mainwindow.h"
#include "mywidget.h"
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("paintTest_zh.qm");       //中文
    //translator.load("paintTest_en.qm");          //英文
    a.installTranslator(&translator);
    MainWindow windows;
    windows.show();
    return a.exec();
}
