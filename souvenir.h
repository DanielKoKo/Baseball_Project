#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <iostream>
using namespace std;

class Souvenir
{
private:
    string name;
    double price;

public:
    Souvenir();
    Souvenir(string n, double p);
    void setName(string n);
    string getName();
    void setPrice(double p);
    double getPrice();
};

#endif // SOUVENIR_H
