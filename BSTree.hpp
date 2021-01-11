//To be used in conjunction with BSTree.h and Node.h


#include "BSTree.h"
// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
		if(root == leaf){
			delete leaf;//if the root is the leaf, delete that leaf
		} else if(leaf != NULL){ 	// otherwise if the leaf is not null
			freeNode(leaf->Left()); //recursive call of the leaf's left
			freeNode(leaf->Right());//recursive call of the leaf's right
			delete leaf;//now delete the leaf
		}
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data) //adds node to tree
{
	if (Root() == nullptr) //if no nodes present
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>; //make a node
		newNodePtr->setKey(key); //get and set its data type
		newNodePtr->setData(data); //set its data
		root = newNodePtr; //make it root
		root->setParent(root); //set it as root node

	}
	else //if there are already nodes
		addNode(key, root, data);  //add another one
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
		if(leaf!=NULL)
		{
			//	if	the	key	is	less	than	whatever	in	the	node	then	move	to	the	lec	of	the	tree
			if(leaf->Key()>key){
				//	call	the	func7on	again	if	there	s7ll	childern	for	this	node
				if(	leaf->Left() !=	nullptr)
					addNode(key, leaf->Left(), data);
					//	if	there	is	no	children	for	this	node	we	will	place	to	the	lec	of	this	node
				else
				{
					Node<DATATYPE,	KEYTYPE>	*	newNodePtr	=	new	Node<DATATYPE,	KEYTYPE>;
					newNodePtr->setKey(key);
					newNodePtr->setData(data);
					leaf->setLeft(newNodePtr);
				}
			}
				//	if	the	key	is	grater	than	whatever	in	the	node	then	move	to	the	lec	of	the	tree
			else
			{
				if(	leaf->Right() !=	nullptr)
					addNode(key, leaf->Right(),	data);
					//	if	there	is	no	children	for	this	node	we	will	place	to	the	right	of	this	node
				else
				{
					Node<DATATYPE, KEYTYPE>* newNodePtr =	new	Node<DATATYPE,	KEYTYPE>;
					newNodePtr->setKey(key);
					newNodePtr->setData(data);
					leaf->setRight(newNodePtr);
				}}}}


template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key) //public find node function
{
	return findNode(key, root); //recursive call to private find node function
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{ //private find node function
	if((node == nullptr) || (node->Key() == key) ) //if no node or if node is root
	{
	    return node; //return the node
	}
	if(node->Key() < key) { //if the key is greater than node
        return findNode(key,node->Right()); //look for the key in the right subtree
    }
    if(node->Key() > key){ //otherwise
	    return findNode(key,node->Left()); //look for key in left subtree
	}
	
}



template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreePicturePartial(string searchWord,BSTree<PictureData, string> *newTree){
    searchTreePicturePartial(root,searchWord,newTree); //recursive call to private partial search picture function
}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreePicturePartial(Node<DATATYPE, KEYTYPE> *node, string searchWord,BSTree<PictureData, string> *newTree) {
    //we need to go through the entire tree no matter what because we need to search all text and the tree is not
    //sorted by every field
    if(node == NULL) //if there are no nodes
    {
        return; //theres nothing to sort
    }
    searchTreePicturePartial(node->Left(),searchWord,newTree); //recursively sort the left subtree
    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
    PictureData temp = node->Data(); //get node
    if(node->Data().name.find(searchWord) != -1) //if the name part of node is equal to the searchword
    {
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl; //output it
        newTree->addNode(temp.name,temp);//add to another tree for secondary search later
    } else if(node->Data().year.find(searchWord) != -1) //if year part of node is equal to search word
    {
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp); //for secondary search
    }
    else if(node->Data().nominations.find(searchWord) != -1) //if nomination part of node is equal to search word
    {
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);

    }
    else if(node->Data().rating.find(searchWord) != -1) //if rating part of node is equal to search word
    {
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().duration.find(searchWord) != -1){ //if duration part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().genre1.find(searchWord) != -1){ //if genre 1 part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().genre2.find(searchWord) != -1){ //if genre 2 part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().release.find(searchWord) != -1){ //if release data part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().metacritic.find(searchWord) != -1){ //if metacritic part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().synopsis.find(searchWord) != -1){ //if synopsis part of node is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }

    searchTreePicturePartial(node->Right(),searchWord,newTree); //recursively search for search word in right subtree


}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreeActor(string searchWord, BSTree<ActorData, string> *newTree) {
    searchTreeActor(root,searchWord,newTree); //recursive call for private complete actor search
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreeActor(Node<DATATYPE, KEYTYPE> *node, string searchWord, BSTree<ActorData, string> *newTree) {
    //we need to go through the entire tree no matter what because we need to search all text and the tree is not
    //sorted by every field
    if(node == NULL){ //if no nodes
        return; //nothing to search for
    }
    searchTreeActor(node->Left(),searchWord, newTree); //recursively search through left subtree
    //Year,Award,Winner,Name,Film
    ActorData temp = node->Data(); //gets actor data
    if(node->Data().year == searchWord){ //if year is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);//add to another tree for secondary search later
    } else if(node->Data().award == searchWord) { //if award is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().winner == searchWord){ //if winner is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().name == searchWord){ //if name is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().film == searchWord){ //if film is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    }
    searchTreeActor(node->Right(),searchWord, newTree); //recursively search for search word in right subtree
}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreeActorPartial(string searchWord, BSTree<ActorData, string> *newTree) {
    searchTreeActorPartial(root,searchWord,newTree); //recursively calls private partial actor search
}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreeActorPartial(Node<DATATYPE, KEYTYPE> *node, string searchWord, BSTree<ActorData, string> *newTree) {
    //we need to go through the entire tree no matter what because we need to search all text and the tree is not
    //sorted by every field
    if(node == NULL){ //if no nodes
        return; //nothing to search for
    }
    searchTreeActorPartial(node->Left(),searchWord, newTree); //recursively look through left subtree
    //Year,Award,Winner,Name,Film
    ActorData temp = node->Data();
    if(node->Data().year.find(searchWord) != -1){ //if year is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);//add to another tree for secondary search later
    } else if(node->Data().award.find(searchWord) != -1) { //if award is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().winner.find(searchWord) != -1){ //if winner is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().name.find(searchWord) != -1){ //if name is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    } else if(node->Data().film.find(searchWord) != -1){ //if film is equal to search word
        cout << "The acting award for " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name, temp);
    }
    searchTreeActorPartial(node->Right(),searchWord, newTree); //recursively look through right subtree
}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreePicture(string searchWord,BSTree<PictureData, string> *newTree){
    searchTreePicture(root,searchWord,newTree); //recursive complete search for pictures
}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::searchTreePicture(Node<DATATYPE, KEYTYPE> *node, string searchWord,BSTree<PictureData, string> *newTree) {
    //we need to go through the entire tree no matter what because we need to search all text and the tree is not
    //sorted by every field
    if(node == NULL){ //if no nodes
        return; //nothing to search for
    }
    searchTreePicture(node->Left(),searchWord, newTree); //recursively searching through left subtree
    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
    PictureData temp = node->Data();
    if(node->Data().name == searchWord){ //if name is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
       newTree->addNode(temp.name,temp);//add to another tree for secondary search later
    } else if(node->Data().year == searchWord){ //is year is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    } else if(node->Data().nominations == searchWord){ //if nomination is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().rating == searchWord){ //if rating is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().duration == searchWord){ //if duration is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().genre1 == searchWord){ //if genre1 is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().genre2 == searchWord){ //if genre2 is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().release == searchWord){ //if release date is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().metacritic == searchWord){ //if metacritic is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }else if(node->Data().synopsis == searchWord){ //if synopsis is equal to search word
        cout << "The picture named " << node->Data().name << " contains the search word: " << searchWord << endl;
        newTree->addNode(temp.name,temp);
    }

    searchTreePicture(node->Right(),searchWord, newTree); //recursively search for searchword in right subtree


}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::resortTree(BSTree<PictureData, string> *newTree,string sortedBy){
    resortTree(root, newTree,sortedBy); //sort picture tree
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::resortTree(Node<DATATYPE, KEYTYPE> * node, BSTree<PictureData, string> *newTree,string sortedBy){
    if(node == NULL){ //if no nodes
        return; //nothing to sort
    }
    resortTree(node->Left(),newTree,sortedBy); //recursively start sorting left tree
    //add it to the new tree according to this:
    PictureData temp = node->Data();

    if(sortedBy == "Name") //if user wants to sort by name
    {
        newTree->addNode(temp.name,temp);//compare data to name and add
    } else if(sortedBy == "Year"){  //if user wants to sort by year
        newTree->addNode(temp.year,temp); //compare data to year and add
    } else if(sortedBy == "Nominations"){ //if user wants to sort by nominations
        newTree->addNode(temp.nominations,temp); //compare data to nomination and add
    } else if(sortedBy == "Rating"){ //if user wants to sort by ratings
        newTree->addNode(temp.rating,temp); //compare data to ratings and add
    } else if(sortedBy == "Duration"){ //if user wants to sort by duration
        newTree->addNode(temp.duration,temp); //compare data to duration and add
    } else if(sortedBy == "Genre1"){ //if user wants to sort by genre1
        newTree->addNode(temp.genre1,temp); //compare data to genre 1 and add
    } else if(sortedBy == "Genre2"){ //if user wants to sort by genre2
        newTree->addNode(temp.genre2,temp); //compare data to genre 2 and add
    } else if(sortedBy == "Release"){ //if user wants to sort by release date
        newTree->addNode(temp.release,temp); //compare data to release date and add
    } else if(sortedBy == "Metacritic"){ //if user wants to sort by metacritic
        newTree->addNode(temp.metacritic,temp); //compare to metacritic and add
    } else if(sortedBy == "Synopsis"){ //if user wants to sort by synopsis
        newTree->addNode(temp.synopsis,temp); //compare to synopsis and add
    }

    resortTree(node->Right(),newTree,sortedBy); //recursively sort right subtree
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::resortTreeActor(BSTree<ActorData, string> *newTree,string sortedBy){
    resortTreeActor(root, newTree,sortedBy); //recursive sort actor tree
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::resortTreeActor(Node<DATATYPE, KEYTYPE> * node, BSTree<ActorData, string> *newTree,string sortedBy){
    if(node == NULL){ //if no nodes
        return; //nothing to sort
    }
    resortTreeActor(node->Left(),newTree,sortedBy); //recusrively sort left subtree
    //add it to the new tree according to this:
    ActorData temp = node->Data();

    if(sortedBy == "Year"){ //if user wants to sort by year
        newTree->addNode(temp.year,temp); //compare data to year and add
    } else if(sortedBy == "Award"){ //if user wants to sort by award
        newTree->addNode(temp.award,temp); //compare data to award and add
    } else if(sortedBy == "Winner"){ //if user wants to sort by winner
        newTree->addNode(temp.winner,temp); //compare data to winner and add
    } else if(sortedBy == "Name"){ //if user wants to sort by name
        newTree->addNode(temp.name,temp); //compare data to name and add
    } else if(sortedBy == "Film"){ //if user wants to sort by film
        newTree->addNode(temp.film,temp); //compare data to film and add
    }

    resortTreeActor(node->Right(),newTree,sortedBy); //recursively sort right subtree
}



template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(string sortedBy)
{
	printInorder(root,sortedBy); //print out sorted pictures
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node,string sortedBy)
{
	//Student must fill in.  Use recursive algorithm.
	//Note that this prints using an Inorder, Depth-first search
	//but you may want to do something else when "visiting" the node....
	//like moving visited data to another datastructure
	//Don't forget your base case!

	if(node == NULL){
	    return;
	}
	printInorder(node->Left(),sortedBy); //print out sorted left tree

    if(sortedBy == "Name"){ //if sorted out by name
        cout << node->Data().name << ", "; //print out the sorted names
    } else if(sortedBy == "Year"){ //if sorted by year
        cout << node->Data().year << ", "; //print out sorted years
    } else if(sortedBy == "Nominations"){ //if sorted by nominations
        cout << node->Data().nominations << ", "; //print out by nominations
    } else if(sortedBy == "Rating"){ //if sorted by rating
        cout << node->Data().rating << ", "; //print out by ratings
    } else if(sortedBy == "Duration"){ //if sorted by duration
        cout << node->Data().duration << ", "; //print out by duration
    } else if(sortedBy == "Genre1"){ //if sorted by genre1
        cout << node->Data().genre1 << ", "; //print out by genre1
    } else if(sortedBy == "Genre2"){ //if sorted by genre2
        cout << node->Data().genre2 << ", "; //print out by genre2
    } else if(sortedBy == "Release"){ //if sorted by release date
        cout << node->Data().release << ", "; //print out by release
    } else if(sortedBy == "Metacritic"){ //if printed by metacritic
        cout << node->Data().metacritic << ", "; //print out by metacritic
    } else if(sortedBy == "Synopsis"){ //is sorted by synopsis
        cout << node->Data().synopsis << ", ";
    }
	printInorder(node->Right(),sortedBy); //print out sorted right tree


}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::outputTreeActor(ofstream &out) {
    out << "Year,Award,Winner,Name,Film" << endl;
    outputTreeActor(root,out); //outputs current pic records to external file
}
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::outputTreeActor(Node<DATATYPE, KEYTYPE> * node, ofstream &out) {
    if(node == NULL){
        return;
    }
    outputTreeActor(node->Left(),out); //output left subtree into file

    //output the data
    ActorData temp = node->Data();
    out << temp.year << ","; //output year
    out << temp.award << ","; //output award
    out << temp.winner<< ","; //output winner
    if(temp.name.find(",") != -1){ //the input has special cases for films with commas inside where they are also placed inside quotation marks ^_^
        out << "\"" << temp.name << "\"" << ",";
    } else {
        out << temp.name << ","; //outut name
    }
    if(temp.film.find(",") != -1){ //if there is a comma in the name
        out << "\"" << temp.film << "\"" << endl; //output it with tabs
    } else {//otherwise
        out << temp.film << endl; //print it normally
    }
    outputTreeActor(node->Right(),out); //output right subtree
}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::outputTreePicture(ofstream &out) {
    out << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
    outputTreePicture(root,out); //outputs pictures to external file
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::outputTreePicture(Node<DATATYPE, KEYTYPE> * node, ofstream &out) {
    if(node == NULL){
        return;
    }
    outputTreePicture(node->Left(),out); //print out left subtree
    //output the data
    PictureData temp = node->Data();
    out << temp.name << ","; //print name
    out << temp.year << ","; //print year
    out << temp.nominations << ","; //print nominations
    out << temp.rating << ","; //print rating
    out << temp.duration << ","; //print duration
    out << temp.genre1 << ","; //print genre1
    out << temp.genre2 << ","; //print genre2
    out << temp.release << ","; //print release date
    out << temp.metacritic << ","; //print metacritic
    out << temp.synopsis << endl; //print synopsis
    outputTreePicture(node->Right(),out); //print out right subtree
}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorderActor(string sortedBy)
{
    printInorderActor(root,sortedBy); //prints sorted actors
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorderActor(Node<DATATYPE, KEYTYPE> * node,string sortedBy)
{
    if(node == NULL){ //if no nodes
        return;//nothing to print
    }
    printInorderActor(node->Left(),sortedBy); //print out left subtree

    if(sortedBy == "Year"){ //if sorted by year
        cout << node->Data().year << ", "; //print out year
    } else if(sortedBy == "Award"){ //if sorted by award
        cout << node->Data().award << ", "; //print out award
    } else if(sortedBy == "Winner"){ //if sorted by winner
        cout << node->Data().winner << ", "; //print out winner
    } else if(sortedBy == "Name"){ //if sorted by name
        cout << node->Data().name << ", "; //print out name
    } else if(sortedBy == "Film"){ //if sorted by film
        cout << node->Data().film << ", "; //print out film
    }

    printInorderActor(node->Right(),sortedBy); //recursively print right subtree


}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data.number << "\t" << data.name << endl; //provided example from binary search tree files
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key)); //recursive call to private delete node function
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		root->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr) //keeps going until we reach last node in left subtree
		current = current->Left(); //current keeps going farther into subtree

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr) //if node is null
		tempNode = nullptr; //then tempnode is also null
	else if (node->Right())
		tempNode = max(node->Right()); //tempNode traverses through right subtree
	else
		tempNode = node;

	return tempNode; //get max node
}