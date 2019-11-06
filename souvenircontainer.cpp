#include "souvenircontainer.h"

SouvenirContainer::SouvenirContainer()
{
    head = new SouvenirNode;
    tail = head;
}

void SouvenirContainer::addSouvenir(Souvenir souv)
{
    if(head == tail)
    {
        head = new SouvenirNode;
        head->souv = souv;
        tail = head;
    }
    else
    {
        tail->next = new SouvenirNode;
        tail->next->souv = souv;
        tail = tail->next;
    }
}

void SouvenirContainer::removeSouvenir(Souvenir souv)
{
    SouvenirNode *d = head;
    if(head->souv.getName() == souv.getName())
    {
        head = head->next;
        delete d;
    }
    else
    {
        SouvenirNode *p = head;
        d = head->next;

        while(d != nullptr)
        {
            if(d->souv.getName() == souv.getName())
            {
                p->next = d->next;
            }
            p = p->next;
            d = d->next;
        }

        d = new SouvenirNode;
        p = new SouvenirNode;
        delete p;
        delete d;
    }
}

void SouvenirContainer::displaySouveniers()
{
    SouvenirNode *d = head;

    while(d != nullptr)
    {
        cout << "Name: " << d->souv.getName() << " Price: ";
        cout << d->souv.getPrice() << endl;
        d = d->next;
    }

    d = new SouvenirNode;
    delete d;
}

double SouvenirContainer::returnTotal()
{
    double total = 0;
    SouvenirNode *d = head;

    while(d != nullptr)
    {
        total += d->souv.getPrice();
        d = d->next;
    }

    d = new SouvenirNode;
    delete d;
    return total;
}
