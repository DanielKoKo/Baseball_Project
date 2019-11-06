#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree()
{
    stadiumRoot = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    delete stadiumRoot;
}

void BinarySearchTree::insertNode(StadiumNode *&nodePtr, bool is_amer)
{
    StadiumNode *newNode = new StadiumNode;

    //Sets the node as American if true
    if (is_amer)
        newNode->is_amer = true;

    //newNode->value = value;
    newNode->left = newNode->right = nullptr;

    //Insert the Node
    insert(stadiumRoot, newNode);
}

void BinarySearchTree::read_files()
{
    ifstream amerFile;  //American stadiums file
    ifstream natFile;   //National stadiums file
    string str;         //String to read
    string address;     //Address of stadium

    amerFile.open("/Users/daniel/Desktop/CS008/Assignments"
                  "/Proj_Baseball/americanStadiums.txt");
    natFile.open("/Users/daniel/Desktop/CS008/Assignments"
                 "/Proj_Baseball/nationalStadiums.txt");

    while (!amerFile.eof())
    {
        StadiumNode *newNode = new StadiumNode;

        //New node is from american stadiums' file
        newNode->is_amer = true;

        address = "";
        str = "";

        getline(amerFile, str);
        newNode->stadium = str;
        getline(amerFile, str);
        newNode->team = str;

        //Reads two lines for address
        getline(amerFile, str);
        address = address + str + " ";
        getline(amerFile, str);
        address += str;
        newNode->address = address;

        getline(amerFile, str);
        newNode->phone_num = str;

        //Reads in date
        getline(amerFile, str);
        newNode->open_date = str;

        //Reads in max capacity
        getline(amerFile, str);
        newNode->capacity = str;

        //Reads empty line
        getline(amerFile, str);

        //Initializes newNode
        newNode->left = newNode->right = nullptr;

        //Inserts american stadium node
        insert(stadiumRoot, newNode);
    }

    amerFile.close();
    natFile.close();
}

void BinarySearchTree::insert(StadiumNode *&nodePtr,
                              StadiumNode *&newNode)
{
    if (nodePtr == nullptr)
            nodePtr = newNode;
    else if (newNode->stadium < nodePtr->stadium)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void BinarySearchTree::displayPreOrder(StadiumNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->stadium << endl;
        cout << nodePtr->team << endl;
        cout << nodePtr->address << endl;
        cout << nodePtr->phone_num << endl;
        cout << nodePtr->open_date << endl;
        cout << nodePtr->capacity << endl;
        cout << endl << endl;

        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}





















