#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->incorrect_label->hide();
    //ui->label->setScaledContents(true);

    b_amer.read_files("/Users/daniel/Desktop/CS008/Assignments"
                      "/Proj_Baseball/americanStadiums.txt", "none");
    b_nat.read_files("/Users/daniel/Desktop/CS008/Assignments"
                     "/Proj_Baseball/nationalStadiums.txt", "none");
    b_major.read_allFiles("/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/americanStadiums.txt",
                          "/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/nationalStadiums.txt", "none");
    b_grass.read_allFiles("/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/americanStadiums.txt",
                          "/Users/daniel/Desktop/CS008/Assignments"
                          "/Proj_Baseball/nationalStadiums.txt", "grass");
    b_date.read_allFiles("/Users/daniel/Desktop/CS008/Assignments"
                         "/Proj_Baseball/americanStadiums.txt",
                         "/Users/daniel/Desktop/CS008/Assignments"
                         "/Proj_Baseball/nationalStadiums.txt", "date");
    b_capacity.read_allFiles("/Users/daniel/Desktop/CS008/Assignments"
                            "/Proj_Baseball/americanStadiums.txt",
                            "/Users/daniel/Desktop/CS008/Assignments"
                            "/Proj_Baseball/nationalStadiums.txt", "capacity");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayPreOrder(StadiumNode *nodePtr) const
{
    ui->incorrect_label->hide();
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

void MainWindow::displayInOrder(StadiumNode *nodePtr) const
{
    ui->incorrect_label->hide();
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);

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

        displayInOrder(nodePtr->right);
    }

    //Shows the top of the textBrowser first
    ui->stadium_TextBrowser->reload();
}

void MainWindow::displayGrass(StadiumNode *nodePtr) const
{
    ui->incorrect_label->hide();
    if (nodePtr)
    {
        if (nodePtr->s.is_grass)
        {
            displayGrass(nodePtr->left);
            //cout << "Grass!" << endl;
            //Outputs stadium's info to textBrowser if it's grass
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
            ui->stadium_TextBrowser->append("Grass");
            ui->stadium_TextBrowser->append("\n");
            displayGrass(nodePtr->right);
        }
    }

    //Shows the top of the textBrowser first
    ui->stadium_TextBrowser->reload();
}

void MainWindow::displaySouvenirs(StadiumNode *nodePtr) const
{
    if (nodePtr)
    {
        displaySouvenirs(nodePtr->left);

        //Outputs stadium's info to textBrowser
        ui->souvenir_TextBrowser
              ->append(QString::fromStdString(nodePtr->s.team));
        ui->souvenir_TextBrowser->append("------------------------------");
        for (unsigned i = 0; i < b_major.stadiumRoot->s.souvenir.size(); i++)
        {
            ui->souvenir_TextBrowser
              ->append(QString::fromStdString(b_major.stadiumRoot
                                              ->s.souvenir.at(i)));
        }
        ui->souvenir_TextBrowser->append("\n");

        displaySouvenirs(nodePtr->right);
    }

    //Shows the top of the textBrowser first
    ui->souvenir_TextBrowser->reload();
}

void MainWindow::on_american_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("American Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_amer.stadiumRoot);
}

void MainWindow::on_national_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("National Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_nat.stadiumRoot);
}

void MainWindow::on_major_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("Major Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_major.stadiumRoot);
}

void MainWindow::on_capacity_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("All Stadiums \n Sorted by Capacity");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_capacity.stadiumRoot);
}

void MainWindow::on_date_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("All Stadiums \n Sorted by Date");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_date.stadiumRoot);
}

void MainWindow::on_admin_button_clicked()
{
    ui->incorrect_label->hide();
    //Checks if password is correct
    if (ui->password_textEdit->toPlainText() == password)
        ui->stack1->setCurrentIndex(1);
    else
        ui->incorrect_label->show();
}

void MainWindow::on_back_button_clicked()
{
    //Resets page number to 0
    ui->stack1->setCurrentIndex(0);
}

void MainWindow::on_souvenir_button_clicked()
{
    displaySouvenirs(b_major.stadiumRoot);
}

void MainWindow::on_souvenir_button_2_clicked()
{
    ui->stack1->setCurrentIndex(2);
}

void MainWindow::on_back_button_2_clicked()
{
    ui->stack1->setCurrentIndex(0);
}

void MainWindow::on_grass_button_clicked()
{
    ui->incorrect_label->hide();
    ui->stadium_label->setText("All Grass Stadiums \n Sorted by Team Name");

    //Clears previous team display
    ui->stadium_TextBrowser->clear();

    displayInOrder(b_grass.stadiumRoot);
}
