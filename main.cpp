#include "mainwindow.h"
#include "stadium.h"
#include "binarysearchtree.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    BinarySearchTree b_amer;
    BinarySearchTree b_nat;

    //Reads American stadium file
    cout << "\n--AMERICAN--\n";
    b_amer.read_files();
    b_amer.displayPreOrder();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
