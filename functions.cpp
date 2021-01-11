#include <iostream>
#include "BSTree.h"
#include "BSTree.hpp"
#include <fstream>

BSTree<PictureData, string> *pictureTree = new BSTree<PictureData, string>; //used to obtain picture records
BSTree<ActorData, string> *actorTree = new BSTree<ActorData, string>; //used to obtain actor records

void inputDataPicture(){ //opens pic file and gets records
    ifstream infile2("pictures.csv"); //open file
    string tempString;
    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
    getline(infile2,tempString); //ignore the first line
    while (getline(infile2,tempString, ',')){ //gets name
        PictureData tempData;
        tempData.name = tempString.substr(1);//turns out there's a space at the start of the name input, we will be removing it!
        getline(infile2,tempString, ','); //gets year
        tempData.year = tempString;
        getline(infile2,tempString, ',');//gets number of nominations
        tempData.nominations = tempString;
        getline(infile2,tempString, ',');//gets rating (double)
        tempData.rating = tempString;
        getline(infile2,tempString, ',');//gets duration
        tempData.duration = tempString;
        getline(infile2,tempString, ',');//gets genre1
        tempData.genre1 = tempString;
        getline(infile2,tempString, ',');//gets genre2
        tempData.genre2 = tempString;
        getline(infile2,tempString, ',');//gets release month
        tempData.release = tempString;
        getline(infile2,tempString, ',');//gets metacritic score (int)
        tempData.metacritic = tempString;
        getline(infile2,tempString);//gets synopsis and ends input at the line break
        tempData.synopsis = tempString;
        pictureTree->addNode(tempData.name,tempData); //adds all the data into the picture tree, while sorting by name
    }
}

void inputDataActor(){ //opens actor file and gets records
    ifstream infile("actor-actress.csv"); //open file
    string tempString;
    getline(infile,tempString); //ignore first line
    //Year,Award,Winner,Name,Film
    while (getline(infile,tempString, ',')){ //gets year
        ActorData tempData;
        tempData.year = tempString;
        getline(infile,tempString, ','); //gets award
        tempData.award = tempString;
        getline(infile,tempString, ',');//gets whether they won
        tempData.winner = tempString;
        getline(infile,tempString, ',');//gets name of actor
        if(tempString.at(0) == '"') //if the string has quotes
        {
            string tempString2;
            getline(infile,tempString2, ','); //look for any commas within the quotes
            tempString = tempString+tempString2;
            tempString = tempString.substr(1,tempString.length()-2); //and delete those commas
        }
        tempData.name = tempString;
        getline(infile,tempString);//gets name of film
        if(tempString.at(0) == '"') //if film has quotes
        {
            tempString = tempString.substr(1,tempString.length()-2); //get rid of quotes
        }
        tempData.film = tempString;
        actorTree->addNode(tempData.name,tempData); //add all the data into actor tree, while sorting by name
    }
}

void sortPictureDatabaseBy(){ //function to sort picture tree
    cout << "What would you like to sort the Movie database by?" << endl;
    cout << "Your options are: Name, Year, Nominations, Rating, Duration, Genre1, Genre2, Release, Metacritic, Synopsis" << endl;
    cout << "Type one, without commas." << endl;
    string data;
    getline(cin,data); //user inputs what they want to sort by
    data.at(0) = toupper(data.at(0));
    if(data == "Name" || data == "Year" || data == "Nominations" || data == "Rating" || data == "Duration" || data == "Genre1" || data == "Genre2" || data == "Release" || data == "Metacritic" || data == "Synopsis"){
        //if they chose a sortable field
        BSTree<PictureData, string> *sortedTree = new BSTree<PictureData, string>;
        pictureTree->resortTree(sortedTree, data); //sorted pictures by that field
        cout << "Sorted database: " << endl;
        sortedTree->printInorder(data); //and print it out
    } else{ //otherwise
        cout << "Invalid type!" << endl; //error message
    }
    cout << endl;
    //THE PROGRAM DOES NOT CHANGE THE WAY THE BINARY TREE IS SORTED PERMANENTLY, IT WILL ONLY BE SORTED DIFFERENTLY IN THIS ONE SECTION TO OUTPUT
    //HOW THE RECORDS WOULD LOOK IF SORTED BY THAT DATA.
}

void sortActorDatabaseBy(){ //function to sort actor tree
    cout << "What would you like to sort the Actor-Actress database by?" << endl;
    cout << "Your options are: Year, Award, Winner, Name, Film" << endl;
    cout << "Type one, without commas." << endl;
    string data;
    getline(cin,data); //user selects what they want to sort by
    data.at(0) = toupper(data.at(0));
    if(data == "Year" || data == "Award" || data == "Winner" || data == "Name" || data == "Film")
    { //if user selects sortable field
        BSTree<ActorData, string> *sortedTree = new BSTree<ActorData, string>;
        actorTree->resortTreeActor(sortedTree, data); //sort actors by that field
        cout << "Sorted database: " << endl;
        sortedTree->printInorderActor(data); //and output the results
    } else{ //otherwise
        cout << "Invalid type!" << endl; //error message
    }
    cout << endl;

}

//name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis

void printDataPicture(){ //used to print pictures
    pictureTree->printInorder("Name"); //prints when sorted by name
}
void printDataActor(){ //used to print actors
    actorTree->printInorderActor("Name"); //prints when sorted by name
}

void addNewPicture(){ //used to add new pictures
    PictureData temp;
    string tempString;
    //get new name
    cout << "Please enter the new picture name: " << endl;
    getline(cin,tempString);//user enters new name
    temp.name = tempString;  //new name is saved in data
    //get new year
    cout << "Please enter the new picture year: " << endl;
    getline(cin,tempString); //user enters new year
    temp.year = tempString; //new year is saved in data
    //get new etc.
    cout << "Please enter the new picture nominations: " << endl;
    getline(cin,tempString); //user enteres new nomination
    temp.nominations = tempString; //nom is saved in data
    cout << "Please enter the new picture rating: " << endl;
    getline(cin,tempString); //user enters new rating
    temp.rating = tempString; //rating is saved
    cout << "Please enter the new picture duration: " << endl;
    getline(cin,tempString); //user enters new duration
    temp.duration = tempString; //duration is saved
    cout << "Please enter the new picture genre one: " << endl;
    getline(cin,tempString); //user enters genre1
    temp.genre1 = tempString; //genre1 is saved
    cout << "Please enter the new picture genre two: " << endl;
    getline(cin,tempString); //user enters genre2
    temp.genre2 = tempString; //genre2 is saved
    cout << "Please enter the new picture release month: " << endl;
    getline(cin,tempString); //user enters release data
    temp.release = tempString; //release date is saved
    cout << "Please enter the new picture metacritic score: " << endl;
    getline(cin,tempString); //user enters score
    temp.metacritic = tempString; //score is saved
    cout << "Please enter the new picture synopsis: " << endl;
    getline(cin,tempString); //user enters synopsis
    temp.synopsis = tempString; //synopsis is saved
    pictureTree->addNode(temp.name,temp); //add new data is added into node in tree

    cout << "Entry added! " << endl;
}

void addnewActor(){ //function to add new actor node

    ActorData temp;
    string tempString;
    //Year,Award,Winner,Name,Film
    //get new year
    cout << "Please enter the new year: " << endl;
    getline(cin,tempString); //user enters year
    temp.year = tempString; //year is saved as data
    //get new award
    cout << "Please enter the name of the award: " << endl;
    getline(cin,tempString); //user enters award
    temp.award = tempString; //award is saved
    //get new etc.
    cout << "Please enter whether the award was won or not. 1 for won, 0 for not won: " << endl;
    getline(cin,tempString); //user enters winning status
    temp.winner = tempString; //winning status is saved
    cout << "Please enter the name of the actor/actress nominated: " << endl;
    getline(cin,tempString); //user enters name
    temp.name = tempString; //name is saved
    cout << "Please enter the name of the film for which the actor/actress was nominated: " << endl;
    getline(cin,tempString); //user enters film
    temp.film = tempString; //film is saved

    actorTree->addNode(temp.name,temp); //all new info is put into node and added to tree
    cout << "Entry added! " << endl;
}

void editNodeActor(){ //modifies actor nodes
    cout << "Input full name of actor you would like to edit: " << endl;
    string key;
    getline(cin,key); //enter which actor you want you edit

    if(actorTree->findNode(key)!= nullptr) //if we can find the key
    {
        actorTree->deleteNode(key); //we need to first remove the element
    }
    else{
        cout << "Actor not found! Canceling!" << endl;
        return;
    }

    ActorData temp;
    string tempString;
    //Year,Award,Winner,Name,Film
    //get new year
    cout << "Please enter the new award year: " << endl;
    getline(cin,tempString);//enter in new
    temp.year = tempString;
    //get new award
    cout << "Please enter the name of the award: " << endl;
    getline(cin,tempString); //eneter in new award
    temp.award = tempString;
    //get new etc.
    cout << "Please enter whether the award was won or not. 1 for won, 0 for not won: " << endl;
    getline(cin,tempString); //enter in new winning status
    temp.winner = tempString;
    cout << "Please enter the name of the actor/actress nominated: " << endl;
    getline(cin,tempString); //enter in new name
    temp.name = tempString;
    cout << "Please enter the name of the film for which the actor/actress was nominated: " << endl;
    getline(cin,tempString); //enter in new film
    temp.film = tempString;

    actorTree->addNode(temp.name,temp); //add all new data into node to go into tree
    cout << "Entry changed! " << endl;
}

void pictureCompleteSearch(){ //do complete search for pictures
    cout << "Input a search term for the movie database please: " << endl;
    string searchWord;
    getline(cin,searchWord); //user enters word

    BSTree<PictureData, string> *secondaryTree = new BSTree<PictureData, string>;
    pictureTree->searchTreePicture(searchWord,secondaryTree); //look for word in picture database
    BSTree<PictureData, string> *tertiaryTree = new BSTree<PictureData, string>; //unused but could be used for a third search
    cout << "Perform a second search? Input Y for yes, N for no." << endl; //asks user for second search
    string tempString;
    getline(cin,tempString); //yes or no
    if(tempString == "Y"){ //if yes
        cout << "Input second search term:" << endl;
        string tempString;
        getline(cin,tempString); //intput new search word
        secondaryTree->searchTreePicture(tempString,tertiaryTree); //search for word
        cout << "Search complete!" << endl;
        return;
    }
    cout << "Search complete!" << endl;
}

void picturePartialSearch(){ //picture partial search
    cout << "Input a search term for the movie database please: " << endl;
    string searchWord;
    getline(cin,searchWord); //enter substring
    BSTree<PictureData, string> *secondaryTree = new BSTree<PictureData, string>;
    pictureTree->searchTreePicturePartial(searchWord,secondaryTree); //look for substring
    BSTree<PictureData, string> *tertiaryTree = new BSTree<PictureData, string>; //unused but could be used for a third search
    cout << "Perform a second search? Input Y for yes, N for no." << endl; //second search?
    string tempString;
    getline(cin,tempString); //yes or no
    if(tempString == "Y"){ //if yes
        cout << "Input second search term:" << endl;
        string tempString;
        getline(cin,tempString);//enter new substring
        secondaryTree->searchTreePicturePartial(tempString,tertiaryTree); //search for substring
        cout << "Search complete!" << endl;
        return;
    }
    cout << "Search complete!" << endl;
}

void actorCompleteSearch(){ //complete search for actor
    cout << "Input a search term for the actor database please: " << endl;
    string searchWord;
    getline(cin,searchWord); //get search word
    BSTree<ActorData, string> *secondaryTree = new BSTree<ActorData, string>;
    actorTree->searchTreeActor(searchWord,secondaryTree); //search for search word
    BSTree<ActorData, string> *tertiaryTree = new BSTree<ActorData, string>; //unused but could be used for a third search
    cout << "Perform a second search? Input Y for yes, N for no." << endl; //second search?
    string tempString;
    getline(cin,tempString); //yes or no
    if(tempString == "Y"){ //if yes
        cout << "Input second search term:" << endl;
        string tempString;
        getline(cin,tempString);//enter new search word
        secondaryTree->searchTreeActor(tempString,tertiaryTree); //search for search word
        cout << "Search complete!" << endl;
        return;
    }
    cout << "Search complete!" << endl;
}

void actorPartialSearch(){ //partial search for actor
    cout << "Input a search term for the actor database please: " << endl;
    string searchWord;
    getline(cin,searchWord); //enter substring
    BSTree<ActorData, string> *secondaryTree = new BSTree<ActorData, string>;
    actorTree->searchTreeActorPartial(searchWord,secondaryTree); //look for substring
    BSTree<ActorData, string> *tertiaryTree = new BSTree<ActorData, string>; //unused but could be used for a third search
    cout << "Perform a second search? Input Y for yes, N for no." << endl; //second search?
    string tempString;
    getline(cin,tempString); //yes or no
    if(tempString == "Y"){ //if yes
        cout << "Input second search term:" << endl;
        string tempString;
        getline(cin,tempString);//enter new subtring
        secondaryTree->searchTreeActorPartial(tempString,tertiaryTree); //look for it
        cout << "Search complete!" << endl;
        return;
    }
    cout << "Search complete!" << endl;
}

void removePicture(){ //delete picture node
    cout << "Input full name of picture you would like to remove: " << endl;
    string key;
    getline(cin,key); //enter key you want to delete

    if(pictureTree->findNode(key)!= nullptr){ //if the key is found in picture tree
        pictureTree->deleteNode(key); //we need to first remove the element
    } else{
        cout << "Picture not found! Canceling!" << endl;
        return;
    }
    cout << "Deleted picture " << key << endl;
}

void removeActor(){ //delete actor node
    cout << "Input full name of actor you would like to remove: " << endl;
    string key;
    getline(cin,key); //enter key you want to delete

    if(actorTree->findNode(key)!= nullptr){  //if key is found
        actorTree->deleteNode(key); //we need to first remove the element
    } else{
        cout << "Actor not found! Canceling!" << endl;
        return;
    }
    cout << "Deleted actor " << key << endl;
}

void editNodePicture() //modify the picture node
{
    cout << "Input full name of picture you would like to edit: " << endl;
    string key;
    getline(cin,key); //enter key you want to modify

    if(pictureTree->findNode(key)!= nullptr){ //if we find it
        pictureTree->deleteNode(key); //we need to first remove the element
    } else{
        cout << "Picture not found!" << endl;
        return;
    }

    PictureData temp;
    string tempString;
    //get new name
    cout << "Please enter the new picture name: " << endl;
    getline(cin,tempString);//enter new name
    temp.name = tempString; //set name new
    //get new year
    cout << "Please enter the new picture year: " << endl;
    getline(cin,tempString); //enter new year
    temp.year = tempString; //set new year
    //get new etc.
    cout << "Please enter the new picture nominations: " << endl;
    getline(cin,tempString); //enter new nomination
    temp.nominations = tempString; //set new nomination
    cout << "Please enter the new picture rating: " << endl;
    getline(cin,tempString); //enter new string
    temp.rating = tempString; //set new string
    cout << "Please enter the new picture duration: " << endl;
    getline(cin,tempString); //enter new duration
    temp.duration = tempString; //set new duration
    cout << "Please enter the new picture genre one: " << endl;
    getline(cin,tempString); //enter new genre1
    temp.genre1 = tempString; //set new genre1
    cout << "Please enter the new picture genre two: " << endl;
    getline(cin,tempString); //enter new gener2
    temp.genre2 = tempString;//set new genre2
    cout << "Please enter the new picture release month: " << endl;
    getline(cin,tempString); //enter new release date
    temp.release = tempString; //set new release date
    cout << "Please enter the new picture metacritic score: " << endl;
    getline(cin,tempString); //eneter new score
    temp.metacritic = tempString; //set new score
    cout << "Please enter the new picture synopsis: " << endl;
    getline(cin,tempString); //enter new synopsis
    temp.synopsis = tempString; //set new synoposis
    pictureTree->addNode(temp.name,temp); //add new data to node and then to tree
    cout << "Entry changed! " << endl;
}

void outputActor(){ //output actor record to external file
    ofstream out;
    out.open("actor-actress2.csv"); //make extrenal file
    actorTree->outputTreeActor(out); //output all records to it
    out.close(); //close it
    cout << "Output file: actor-actress2.csv" << endl;
}

void outputPicture(){ //ouput picture record to external file
    ofstream out;
    out.open("pictures2.csv"); //make external file
    pictureTree->outputTreePicture(out); //output all records to it
    out.close(); //close i t
    cout << "Output file: pictures2.csv" << endl;
}