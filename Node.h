#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Placeholder for a composite data type

struct PictureData //used for picture file and picture tree
{
public:
    string name;
    string year;
    string nominations;
    string rating;
    string duration;
    string genre1;
    string genre2;
    string release;
    string metacritic;
    string synopsis;
};

struct ActorData{ //used for actor file and actor tree
public:
    string year;
    string award;
    string winner;
    string name;
    string film;
};

//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    string key; //This should be the datatype of your key...sorted field in tree
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left; //left node
    Node<DATATYPE, KEYTYPE> * right; //right node
    Node<DATATYPE, KEYTYPE> * parent; //parent node
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;}; //initialize all to null
    void setKey(KEYTYPE aKey) { key = aKey; }; //set key
	void setData(DATATYPE aData) { data = aData; } //set data
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; }; //set left
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; }; //set right
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; }; //set parent
    KEYTYPE Key() { return key; };  //get key
	DATATYPE Data() { return data; } //get data
    Node<DATATYPE, KEYTYPE> * Left() { return left; }; //get left node
    Node<DATATYPE, KEYTYPE> * Right() { return right; }; //get right node
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; }; //get parent node
};

#endif
