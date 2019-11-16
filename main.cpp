#include "mainwindow.h"
#include "stadium.h"
#include "binarysearchtree.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
