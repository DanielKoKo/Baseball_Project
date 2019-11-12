#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree()
{
    stadiumRoot = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    delete stadiumRoot;
}

void BinarySearchTree::read_files(string file_name)
{
    ifstream file;      //Input file
    string str;         //String to read
    string address;     //Address of stadium

    file.open(file_name);

    while (!file.eof())
    {
        //Creates new node to store in binary tree
        StadiumNode *newNode = new StadiumNode;

        //New node is from american stadiums' file
        newNode->is_amer = true;

        address = "";
        str = "";

        getline(file, str);
        newNode->s.stadium = str;
        getline(file, str);
        newNode->s.team = str;

        //Reads two lines for address
        getline(file, str);
        address = address + str + " ";
        getline(file, str);
        address += str;
        newNode->s.address = address;

        getline(file, str);
        newNode->s.phone_num = str;

        //Reads in date and removes extra characters
        file >> str;
        file >> str;
        getline(file, str);
        str.erase(0, 1);
        newNode->s.open_date = str;

        //Reads in max capacity and removes extra characters
        file >> str;
        file >> str;
        getline(file, str);
        str.erase(0, 1);
        newNode->s.capacity = str;

        //Reads empty line
        getline(file, str);


        //Initializes newNode
        newNode->left = newNode->right = nullptr;

        //Inserts american stadium node
        insert(stadiumRoot, newNode);
    }

    file.close();
}

void BinarySearchTree::read_allFiles(string file_name1, string file_name2)
{
    string str;         //String to read
    string address;     //Address of stadium

    read_files(file_name1);
    read_files(file_name2);
}

void BinarySearchTree::insert(StadiumNode *&nodePtr, StadiumNode *&newNode)
{
    if (nodePtr == nullptr)
            nodePtr = newNode;
    //Compares stadium names for insertion
    else if (newNode->s.stadium.at(0) < nodePtr->s.stadium.at(0))
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void BinarySearchTree::sort(StadiumNode *nodePtr)
{
    stack<StadiumNode *> s;
    StadiumNode *curr = nodePtr;

    //delete stadiumRoot;
    stadiumRoot = new StadiumNode();

    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        stadiumRoot = curr;
        s.pop();

        insert(stadiumRoot, curr);

        curr = curr->right;
    }
    cout << endl;
}

bool BinarySearchTree::operator<(StadiumNode *compare) const
{
    return (stadiumRoot->s.address < compare->s.stadium);
}

StadiumNode BinarySearchTree::operator=(StadiumNode *nodePtr)
{
    stadiumRoot->s.stadium = nodePtr->s.stadium;
    stadiumRoot->s.team = nodePtr->s.team;
    stadiumRoot->s.address = nodePtr->s.address;
    stadiumRoot->s.phone_num = nodePtr->s.phone_num;
    stadiumRoot->s.open_date = nodePtr->s.open_date;
    stadiumRoot->s.capacity = nodePtr->s.capacity;

    return *stadiumRoot;
}

/***********
 * TESTING *
 * *********/
void BinarySearchTree::displayPreOrder(StadiumNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->s.stadium << endl;
        cout << nodePtr->s.team << endl;
        cout << nodePtr->s.address << endl;
        cout << nodePtr->s.phone_num << endl;
        cout << nodePtr->s.open_date << endl;
        cout << nodePtr->s.capacity << endl;
        cout << endl << endl;

        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}
