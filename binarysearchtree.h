 #ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <fstream>
#include "stadium.h"

using namespace std;

//Binary tree for all stadiums
struct StadiumNode
{
    string stadium;        //Name of stadium
    string team;           //Name of team
    string address;        //Address
    string phone_num;      //Phone number
    string open_date;      //Opening date
    string capacity;       //Maximum capacity

    //Subtrees
    StadiumNode *left;
    StadiumNode *right;

    //Checks if inserting to American node
    bool is_amer;
};

class BinarySearchTree
{
public:
    //Root is public so we can access it in mainWindow class
    StadiumNode *stadiumRoot;  //Root of Major stadium tree

    //Default constructor
    BinarySearchTree();

    //Destructor
    ~BinarySearchTree();

    //Calls read_files function from Stadium class
    void read_files();

    //Inserts new node to binary tree
    void insertNode(StadiumNode *&, bool);

    void displayPreOrder() const { displayPreOrder(stadiumRoot); }

private:
    //Inserts sorted stadiums to binary tree
    void insert(StadiumNode *&, StadiumNode *&);

    //Displays tree pre-order
        void displayPreOrder(StadiumNode *) const;
};








































#endif // BINARYSEARCHTREE_H
