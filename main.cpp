#include "mainwindow.h"
#include "stadium.h"
#include "binarysearchtree.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    BinarySearchTree b_amer;
    BinarySearchTree b_nat;
    BinarySearchTree b_major;

    /*
    //Reads American stadium file
    cout << "\n--AMERICAN--\n";
    b_amer.read_files("/Users/daniel/Desktop/CS008/Assignments"
                      "/Proj_Baseball/americanStadiums.txt");
    b_amer.displayPreOrder();

    //Reads National stadium file
    cout << "\n--NATIONAL--\n";
    b_nat.read_files("/Users/daniel/Desktop/CS008/Assignments"
                     "/Proj_Baseball/nationalStadiums.txt");
    b_nat.displayPreOrder();
    */

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
