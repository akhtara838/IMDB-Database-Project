//This program attemps to replicate the database used in the Golden Globe Awards; it uses a
//binary search tree as the main data structure and alters it accordingly as the user tries to change the records
#include "functions.cpp"
using namespace std;

int main()
{
	inputDataActor(); //gets actor file/records
	inputDataPicture(); //gets picture file/records
	bool exit = false;
	cout << "A. Add a record to the Actor-Actress database" << endl; //options...
	cout << "B. Add a record to the Movie database" << endl;
	cout << "C. Search for a record in the Actor-Actress database and modify the fields." << endl;
	cout << "D. Search for a record in the Movie database and modify the fields." << endl;
	cout << "E. Search for a record in the Actor-Actress database and delete the fields." << endl;
	cout << "F. Search for a record in the Movie database and delete the fields." << endl;
	cout << "G. Sort the Actor-Actress database by any field." << endl;
	cout << "H. Sort the Movie database by any field." << endl;
	cout << "I. Complete search the Actor-Actress database." << endl;
	cout << "J. Complete search the Movie database." << endl;
	cout << "K. Partial search the Actor-Actress database." << endl;
	cout << "L. Partial search the Movie database." << endl;
	cout << "M. Outputs the Actor-Actress database into a .csv file" << endl;
	cout << "N. Outputs the Movie database into a .csv file" << endl;
    cout << "O. Exit the program." << endl;
	do{
		cout << "Input your option: " << endl;
		string input;
		getline(cin,input); //user decides what they want to change
		switch (toupper(input.at(0))){
			case 'A':
				addnewActor(); //add new node to actor
				break;
			case 'B':
				addNewPicture(); //add new node to picture
				break;
			case 'C':
				editNodeActor(); //delete existing node in actor and add new one
				break;
			case 'D':
				editNodePicture(); //delete existing node in picture and add new one
				break;
			case 'E':
				removeActor(); //delete actor node
				break;
			case'F':
				removePicture(); //delete picture node
				break;
		    case'G':
		        sortActorDatabaseBy(); //sort actors
		        break;
		    case'H':
		        sortPictureDatabaseBy(); //sort pictures
		        break;
		    case'I':
		        actorCompleteSearch(); //complete search for actor
		        break;
		    case'J':
		        pictureCompleteSearch(); //complete search for pictures
		        break;
		    case'K':
		        actorPartialSearch(); //partial search for actors
		        break;
		    case'L':
		        picturePartialSearch(); //partial search for pictures
		        break;
		    case'M':
		        outputActor(); //output all actor records to external file
		        break;
		    case'N':
		        outputPicture(); //output all picture records to external file
		        break;
		    case'O':
		        cout << "Exiting program..." << endl;
		        exit = true;
		        return 0;
		        break;
			default:
				cout << "Invalid input! Please input one of the following: " << endl;
                break;
		}
        cout << "A. Add a record to the Actor-Actress database" << endl;
        cout << "B. Add a record to the Movie database" << endl;
        cout << "C. Search for a record in the Actor-Actress database and modify the fields." << endl;
        cout << "D. Search for a record in the Movie database and modify the fields." << endl;
        cout << "E. Search for a record in the Actor-Actress database and delete the fields." << endl;
        cout << "F. Search for a record in the Movie database and delete the fields." << endl;
        cout << "G. Sort the Actor-Actress database by any field." << endl;
        cout << "H. Sort the Movie database by any field." << endl;
        cout << "I. Complete search the Actor-Actress database." << endl;
        cout << "J. Complete search the Movie database." << endl;
        cout << "K. Partial search the Actor-Actress database." << endl;
        cout << "L. Partial search the Movie database." << endl;
        cout << "M. Outputs the Actor-Actress database into a .csv file" << endl;
        cout << "N. Outputs the Movie database into a .csv file" << endl;
        cout << "O. Exit the program." << endl;

	}while(exit == false);
}