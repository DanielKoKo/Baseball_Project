#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarysearchtree.h"
#include "stadium.h"
#include "souvenir.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    //Displays all stadiums in preorder
    void displayPreOrder(StadiumNode *) const;

private:
    Ui::MainWindow *ui;

    BinarySearchTree b_amer; //American binary tree
    BinarySearchTree b_nat;  //National binary tree
};
#endif // MAINWINDOW_H
