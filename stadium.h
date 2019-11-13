#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <string>
#include "souvenircontainer.h"

using namespace std;

class Stadium
{
private:  
    //SouvenirContainer s;                //Souvenir for the stadium

public:
    //Variables are public so we can access them in mainWindow
    string stadium;            //Name of stadium
    string team;               //Name of team
    string address;            //Address
    string phone_num;          //Phone number
    string open_date;          //Opening date
    string capacity;           //Maximum capacity
    bool is_amer;              //Checks if stadium is American
    //Default constructor
    Stadium();

    //Reads in files' data to store
    void read_files();

    //Modifies a stadium's information
    void modify_stadium();

    //Adds a team to an existing stadium
    void add_team();

    //Sets souvenirs
    //void setSouvenirs(Souvenir *&s);

    //Gets souvenirs
    //Souvenir getSouvenir(Souvenir *&s);
};


























#endif // STADIUM_H
