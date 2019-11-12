 #ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "stadium.h"

using namespace std;

//Binary tree for all stadiums
struct StadiumNode
{
    Stadium s; //Stadium to store

    //Subtrees
    StadiumNode *left;
    StadiumNode *right;

    //Checks if inserting to American node
    bool is_amer;
};

class BinarySearchTree
{
public:
    StadiumNode *stadiumRoot;  //Root of Major stadium tree

    //Default constructor
    BinarySearchTree();

    //Destructor
    ~BinarySearchTree();

    //Reads specified file and stores stadium information
    void read_files(string file_name);

    //Reads specified files and stores all stadium information
    void read_allFiles(string file_name1, string file_name2);

    void sort(StadiumNode *nodePtr);

    void displayPreOrder() const { displayPreOrder(stadiumRoot); }

private:
    vector<Stadium> newStadium;
    int size;

    //Inserts sorted stadiums to binary tree
    void insert(StadiumNode *&, StadiumNode *&);

    //Displays tree pre-order
    void displayPreOrder(StadiumNode *) const;

    bool operator<(StadiumNode *) const;

    StadiumNode operator=(StadiumNode *);
};








































#endif // BINARYSEARCHTREE_H
