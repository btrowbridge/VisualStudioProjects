
#include <iostream>
#include <cassert>
#include <fstream>
#include "testProgHashing.cpp"
#include "orderedArrayListType.h"
#include "hashT.h"
#include "stateData.h"


using namespace std;

void part1();
void part2();

int main() {
	//part1();
	part2();
};

void part1()
{
	cout << "\n \n  \n ============================|Problem 1|======================================= \n \n \n" << endl;

	orderedArrayListType<int> myList = orderedArrayListType<int>(1000);
	myList.fill();

	int searchElem;
	cout << "Pick an integer  to search." << endl;
	cin >> searchElem;
	
	//following should print number of comparisons within each function
	//search user input for three
	cout << "Sequential search found " << searchElem << " at " << myList.seqSearch(searchElem) << endl;
	cout << "Binary search found " << searchElem << " at " << myList.binarySearch(searchElem) << endl;
	cout << "Binary with seq search found " << searchElem << " at " << myList.binaryWithSeqSearch(searchElem) << endl;

	cout << "********************Searching existing number early at index 250**************************" << endl;
	myList.retrieveAt(250, searchElem);
	cout << "Sequential search found " << searchElem << " at " << myList.seqSearch(searchElem) << endl;
	cout << "Binary search found " << searchElem << " at " << myList.binarySearch(searchElem) << endl;
	cout << "Binary with seq search found " << searchElem << " at " << myList.binaryWithSeqSearch(searchElem) << endl;

	cout << "********************Searching existing number late at index 750*********************************" << endl;
	myList.retrieveAt(750, searchElem);
	cout << "Sequential search found " <<  searchElem << " at " << myList.seqSearch(searchElem) << endl;
	cout << "Binary search found " << searchElem << " at " << myList.binarySearch(searchElem) << endl;
	cout << "Binary with seq search found " << searchElem << " at " << myList.binaryWithSeqSearch(searchElem) << endl;

	int indexSearch;
	cout << "*********************Pick an index to search for (0-999)********************************************" << endl;
	cin >> indexSearch;
	myList.retrieveAt(indexSearch, searchElem);
	cout << "Sequential search found " << searchElem << " at " << myList.seqSearch(searchElem) << endl;
	cout << "Binary search found " << searchElem << " at " << myList.binarySearch(searchElem) << endl;
	cout << "Binary with seq search found " << searchElem << " at " << myList.binaryWithSeqSearch(searchElem) << endl;

	
}

void part2() {
	cout << "\n \n \n ============================|Problem 2|======================================= \n \n \n" << endl;
	
	//create hash
	hashT<stateData> stateHash(101);

	cout << "Opening file..." << endl;
	//opening file
	ifstream infile;
	infile.open("state_data.txt");
	assert(infile.is_open());
	
	cout << "Creating hash from file..." << endl;
	//using file as input to supply our hash with states
	while (infile){
		stateData newState;

		infile >> newState;

		int stateIndex = stateHash.hashFunc(newState.getName()); //creating index using hash function

		stateHash.insert(stateIndex, newState); //add to hash
	}

	infile.close(); // close file

	//Searching for a state
	bool found1;
	int hashIndex;
	string stateName;
	stateData searchState;

	cout << "Search the hash, Type the name of a state: ";
	cin >> stateName;

	hashIndex = stateHash.hashFunc(stateName);
	searchState = stateData(stateName);
	
	stateHash.search(hashIndex, searchState, found1);
	if (found1 && stateHash.isItemAtEqual(hashIndex, searchState))
	{
		cout << "Success!" << endl;
		stateHash.retrieve(hashIndex, searchState);
		cout << searchState << endl;
	}
	else {
		cout << "Not Found!" << endl;
	}


	cout << "REMOVING STATE" << endl;
	stateHash.remove(hashIndex, searchState);
	bool found2;
	stateHash.search(hashIndex, searchState, found2);
	if (found2 && stateHash.isItemAtEqual(hashIndex,searchState))
	{
		cout << "Failed to remove state." << endl;
		cout << searchState << endl;
	}
	else {
		cout << "Successfully removed state." << endl;
		cout << "Printing States" << endl;
		cout << setw(15) << left << "Name: " << " | ";
		cout << setw(15) << left << "Capital: " << " | ";
		cout << setw(15) << left << "Joined Union: " << " | ";
		cout << setw(15) << left << "Join Number: " << " | ";
		cout << setw(15) << left << "Area: " << endl;
		stateHash.print();
	}
}
