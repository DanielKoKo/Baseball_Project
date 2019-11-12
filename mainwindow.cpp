#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    b_amer.read_files("/Users/daniel/Desktop/CS008/Assignments"
                      "/Proj_Baseball/americanStadiums.txt");
    b_nat.read_files("/Users/daniel/Desktop/CS008/Assignments"
                     "/Proj_Baseball/nationalStadiums.txt");
    b_major.read_allFiles("/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/americanStadiums.txt",
                          "/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/nationalStadiums.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayPreOrder(StadiumNode *nodePtr) const
{
    if (nodePtr)
    {
        //Outputs stadium's info to textBrowser
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->s.stadium));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->s.team));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->s.address));
        ui->stadium_TextBrowser
              ->append(QString::fromStdString(nodePtr->s.phone_num));
        ui->stadium_TextBrowser
              ->append("Opened - "
                       + QString::fromStdString(nodePtr->s.open_date));
        ui->stadium_TextBrowser
              ->append("Capacity - "
                       + QString::fromStdString(nodePtr->s.capacity));
        ui->stadium_TextBrowser->append("\n");

        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }

    //Shows the top of the textBrowser first
    ui->stadium_TextBrowser->reload();
}

void MainWindow::on_american_button_clicked()
{
    ui->stadium_label->setText("American Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayPreOrder(b_amer.stadiumRoot);
}

void MainWindow::on_national_button_clicked()
{
    ui->stadium_label->setText("National Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayPreOrder(b_nat.stadiumRoot);
}

void MainWindow::on_major_button_clicked()
{
    ui->stadium_label->setText("Major Stadiums \n Sorted by Team Name");
    b_major.sort(b_major.stadiumRoot);

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    b_major.displayPreOrder();
}
