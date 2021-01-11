#ifndef BSTREEINT_H
#define BSTREEINT_H
#include <iostream>
#include <fstream> //to open files
using namespace std;
#include "Node.h"

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root; //root node
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data); //function to add nodes
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key); //function to delete nodes
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf); //function to clear tree
	void printInorder(Node<DATATYPE, KEYTYPE> * node,string sortedBy); //to print in order
    void printInorderActor(Node<DATATYPE, KEYTYPE> * node,string sortedBy); //print actors in order
	void searchTreePicture(Node<DATATYPE, KEYTYPE> * node,string searchWord,BSTree<PictureData, string> *newTree); //complete search pictures
	void searchTreePicturePartial(Node<DATATYPE, KEYTYPE> * node,string searchWord,BSTree<PictureData, string> *newTree); //partial search pictures
	void searchTreeActor(Node<DATATYPE, KEYTYPE> * node,string searchWord,BSTree<ActorData, string> *newTree); //complete search actors
	void searchTreeActorPartial(Node<DATATYPE, KEYTYPE> * node,string searchWord,BSTree<ActorData, string> *newTree); //partial search actors
    void resortTree(Node<DATATYPE, KEYTYPE> * node,BSTree<PictureData, string> *newTree,string sortedBy); //sort pictures by key
    void resortTreeActor(Node<DATATYPE, KEYTYPE> * node,BSTree<ActorData, string> *newTree,string sortedBy); //sort actors by key
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node); //search for node
	void outputTreeActor(Node<DATATYPE, KEYTYPE> * node, ofstream &out); //output to external file actors
	void outputTreePicture(Node<DATATYPE, KEYTYPE> *node, ofstream &out); //output to external file pictures

public:
    BSTree<DATATYPE, KEYTYPE>(); //constructor
    ~BSTree<DATATYPE, KEYTYPE>(); //destructor
    Node<DATATYPE, KEYTYPE> * Root() { return root; } //gets root of tree
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;} //sets root of tree
    void addNode(KEYTYPE key, DATATYPE &data); //adds node to tree
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key); //search for node
	void printInorder(string sortedBy); //print pictures in order
    void printInorderActor(string sortedBy); //print actors in order
	void searchTreePicture(string searchWord,BSTree<PictureData, string> *newTree); //complete search picture
	void searchTreePicturePartial(string searchWord,BSTree<PictureData, string> *newTree); //partial search picture
	void searchTreeActor(string searchWord,BSTree<ActorData, string> *newTree); //complete search actor
    void searchTreeActorPartial(string searchWord,BSTree<ActorData, string> *newTree); //partial search actor
    void resortTree(BSTree<PictureData, string> *newTree,string sortedBy); //sort pictures by key
    void resortTreeActor(BSTree<ActorData, string> *newTree,string sortedBy); //sort actors by key
	void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key); //delete node
    void outputTreeActor(ofstream &out); //output actor to external file
    void outputTreePicture(ofstream &out);//output pictures to external file
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node); //gets smallest node
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node); //gets highest node
};
#endif  //BST
