#include "souvenir.h"

Souvenir::Souvenir()
{
    name = "";
    price = 0;
}

Souvenir::Souvenir(string n, double p)
{
    name = n;
    price = p;
}

void Souvenir::setName(string n)
{
    name = n;
}

string Souvenir::getName()
{
    return name;
}

void Souvenir::setPrice(double p)
{
    price = p;
}

double Souvenir::getPrice()
{
    return price;
}
