#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    b_amer.read_files();

    /****************
     * TEST DISPLAY *
     ****************/
    //ONLY DISPLAYS AMERICAN TEAMS
    displayPreOrder(b_amer.stadiumRoot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayPreOrder(StadiumNode *nodePtr) const
{
    ui->stadium_label->setText("American Stadiums \n Sorted by Team Name");

    if (nodePtr)
    {
        //Outputs stadium's info to textBrowser
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->stadium));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->team));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->address));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->phone_num));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->open_date));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->capacity));
        ui->stadium_TextBrowser->append("\n");

        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}




















