#include "stadium.h"
#include <fstream>

Stadium::Stadium()
{
    //Initializes private member variables
    stadium = "";
    team = "";
    address = "";
    phone_num = "";
    open_date = "";
    capacity = "";
}

void Stadium::read_files()
{
    ifstream amerFile;
    ifstream natFile;
    string str;
    string address;
    string delim;

    amerFile.open("/Users/daniel/Desktop/CS008/Assignments"
                  "/Proj_Baseball/americanStadiums.txt");
    natFile.open("/Users/daniel/Desktop/CS008/Assignments"
                 "/Proj_Baseball/nationalStadiums.txt");

    while (!amerFile.eof())
    {
        Stadium* s = new Stadium();
        address = "";
        str = "";

        getline(amerFile, str);
        s->stadium = str;
        getline(amerFile, str);
        s->team = str;

        //Reads two lines for address
        getline(amerFile, str);
        address = address + str + " ";
        getline(amerFile, str);
        address += str;
        s->address = address;

        getline(amerFile, str);
        s->phone_num = str;

        //Reads in date
        getline(amerFile, str);
        s->open_date = str;

        //Reads in max capacity
        getline(amerFile, str);
        s->capacity = str;

        getline(amerFile, str);

        cout << s->stadium << endl;
        cout << s->team << endl;
        cout << s->address << endl;
        cout << s->phone_num << endl;
        cout << s->open_date << endl;
        cout << s->capacity << endl;
        cout << endl;

    }

    amerFile.close();
    natFile.close();
}
















































