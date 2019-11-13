#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree()
{
    stadiumRoot = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    delete stadiumRoot;
}

void BinarySearchTree::read_files(string file_name, string type)
{
    ifstream file;      //Input file
    string str;         //String to read
    string address;     //Address of stadium
    string souv;

    file.open(file_name);

    while (!file.eof())
    {
        //Creates new node to store in binary tree
        StadiumNode *newNode = new StadiumNode;

        //New node is from american stadiums' file
        newNode->s.is_amer = true;

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

        //Reads in phone number
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

        //Reads in souvenirs
        getline(file, str);
        newNode->s.souvenir.push_back(str);
        getline(file, str);
        newNode->s.souvenir.push_back(str);
        getline(file, str);
        newNode->s.souvenir.push_back(str);
        getline(file, str);
        newNode->s.souvenir.push_back(str);

        //Reads empty line
        getline(file, str);

        //Initializes newNode
        newNode->left = newNode->right = nullptr;

        //Inserts american stadium node
        if (type == "none")
            insert(stadiumRoot, newNode);
        else if (type == "grass")
        {

        }
        else if (type == "date")
            insertDate(stadiumRoot, newNode);
        else if (type == "capacity")
            insertCap(stadiumRoot, newNode);
    }

    file.close();
}

void BinarySearchTree::read_allFiles(string file_name1, string file_name2,
                                     string type)
{
    string str;         //String to read
    string address;     //Address of stadium

    //Checks which type of comparison to run when storing stadiums
    if (type == "none")
    {
        read_files(file_name1, "none");
        read_files(file_name2, "none");
    }
    else if (type == "grass")
    {

    }
    else if (type == "date")
    {
        read_files(file_name1, "date");
        read_files(file_name2, "date");
    }
    else if (type == "capacity")
    {
        read_files(file_name1, "capacity");
        read_files(file_name2, "capacity");
    }
}

void BinarySearchTree::insert(StadiumNode *&nodePtr, StadiumNode *&newNode)
{
    if (nodePtr == nullptr)
            nodePtr = newNode;
    //Compares stadium names for insertion
    else if (newNode->s.team < nodePtr->s.team)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void BinarySearchTree::insertCap(StadiumNode *&nodePtr, StadiumNode *&newNode)
{
    if (nodePtr == nullptr)
            nodePtr = newNode;
    //Compares stadium names for insertion
    else if (newNode->s.capacity < nodePtr->s.capacity)
        insertCap(nodePtr->left, newNode);
    else
        insertCap(nodePtr->right, newNode);
}

void BinarySearchTree::insertDate(StadiumNode *&nodePtr, StadiumNode *&newNode)
{
    string str1 = newNode->s.open_date; //newNode's date
    string str2;                        //Current node's date

    //Checks if current node contains a date for comparison
    if (nodePtr)
    {
        str2 = nodePtr->s.open_date;
        while (str2.at(0) != ',')
            str2.erase(0, 1);

        str2.erase(0, 1);
    }

    //Removes all characters except year for comparison
    while (str1.at(0) != ',')
        str1.erase(0, 1);
    str1.erase(0, 1);

    if (nodePtr == nullptr)
        nodePtr = newNode;
    //Compares stadium names for insertion
    else if (str1 < str2)
        insertDate(nodePtr->left, newNode);
    else
        insertDate(nodePtr->right, newNode);

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
