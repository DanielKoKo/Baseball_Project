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
    Stadium s;                   //Stadium to store
    //SouvenirContainer souvenir;  //Souvenir to store
    //vector<SouvenirContainer> souvenir;
    //Subtrees
    StadiumNode *left;
    StadiumNode *right;
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
    void read_files(string file_name, string);

    //Reads specified files and stores all stadium information
    void read_allFiles(string file_name1, string file_name2, string);

    void displayPreOrder() const { displayPreOrder(stadiumRoot); }

private:
    vector<Stadium> newStadium;
    StadiumNode *allStadiums = new StadiumNode();

    //Inserts sorted stadiums to binary tree
    void insert(StadiumNode *&, StadiumNode *&);

    void insertCap(StadiumNode *&, StadiumNode *&);

    void insertDate(StadiumNode *&, StadiumNode *&);

    //Displays tree pre-order
    void displayPreOrder(StadiumNode *) const;

    bool operator<(StadiumNode *) const;

    StadiumNode operator=(StadiumNode *);
};








































#endif // BINARYSEARCHTREE_H
