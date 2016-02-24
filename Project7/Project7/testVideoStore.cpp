#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "videoType.h"
#include "videoBinaryTree.h"
#include "unorderedLinkedList.h"
#include "customerType.h"

//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the classes videoType 
// and videoBinaryTree to create and process a list of videos.
//****************************************************************

using namespace std;

void createVideoList(ifstream& infile, 
					 videoBinaryTree& videoList);
void createCustomerList(ifstream& infile,
					unorderedLinkedList<customerType>& videoList);

void displayMenu();

void loginView(customerType&, unorderedLinkedList<customerType>&, bool&);

int main()
{
    videoBinaryTree  videoList; 
	unorderedLinkedList<customerType> custList;
	customerType currentCustomer;
    int choice;
	bool found;	//finding customer rented movies
	bool custLogin = false;	//whether there is a customer logged in
    char ch;
    string title;

    ifstream infile;

    infile.open("videoDat.txt");
    if (!infile)
    {
        cout << "The input file does not exist" << endl;
        return 1;
    }

    createVideoList(infile, videoList);
    infile.close();

	infile.open("custDat.txt");
	if (!infile)
	{
		cout << "The input file does not exist" << endl;
		return 1;
	}

	createCustomerList(infile, custList);
	infile.close();


	loginView(currentCustomer, custList, custLogin); //logs in the customer
	while (custLogin) { //if customer is logged in
		cout << "Your checked out videos:" << endl;
		currentCustomer.printVideos();
		cout <<"________________________"<< endl;
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;  //get the request
		cin.get(ch);
		cout << endl;

		//process the request
		while (choice != 9)
		{
			switch (choice)
			{
			case 1:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (videoList.videoSearch(title))
					cout << "Title found." << endl;
				else
					cout << "The store does not carry this title."
					<< endl;
				break;

			case 2:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (videoList.videoSearch(title))
				{
					if (videoList.isVideoAvailable(title))
					{
						currentCustomer.checkOut(title); //updates customers titles
						videoList.videoCheckOut(title);
						cout << "Enjoy your movie: " << title << endl;
					}
					else
						cout << "The video is currently out of stock."
						<< endl;
				}
				else
					cout << "The video is not in the store." << endl;
				break;

			case 3:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (videoList.videoSearch(title))
				{
					found = false;
					currentCustomer.checkIn(title, found); // searches in customer's list
					if (!found) { // if not found
						cout << "You dont have this movie" << endl;
						break;
					}
					videoList.videoCheckIn(title);
					cout << "Thanks for returning " << title << endl;
				}
				else
					cout << "This video is not from our store." << endl;
				break;

			case 4:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if (videoList.videoSearch(title))
				{
					if (videoList.isVideoAvailable(title))
						cout << "The video is currently in stock."
						<< endl;
					else
						cout << "The video is out of stock." << endl;
				}
				else
					cout << "The video is not in the store." << endl;
				break;

			case 5:
				videoList.videoPrintTitle();
				break;

			case 6:
				videoList.inorderTraversal();
				break;

			default: cout << "Invalid selection." << endl;
			}//end switch

			cout << "Your checked out videos:" << endl;
			currentCustomer.printVideos();
			cout << "________________________" << endl;
			displayMenu();
			cout << "Enter your choice: ";
			cin >> choice;  //get the next request
			cin.get(ch);
			cout << endl;
		}//end while
		loginView(currentCustomer, custList, custLogin);
	}
    return 0;
}
void createCustomerList(ifstream& infile, unorderedLinkedList<customerType>& custList)
{
	string fname;
	string lname;
	int num;

	//char   ch;


	

	
	while (infile>>fname >> lname >> num)
	{
		cout << "Inserting " << fname << " " << lname << endl; // debug
		custList.insertLast(customerType(fname, lname));
		
	}//end while
}//end createVideoList
void createVideoList(ifstream& infile, videoBinaryTree& videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char   ch;
    int   inStock;

    videoType newVideo;

    getline(infile, title);
    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
        newVideo.setVideoInfo(title, star1, star2, producer,
                             director, productionCo, inStock);
        videoList.insert(newVideo);

        getline(infile, title);
    }//end while
}//end createVideoList

void displayMenu()
{
    cout << "Select one of the following: " << endl;
    cout << "1: To check whether a particular video is in "
         << "the store" << endl;
    cout << "2: To check out a video" << endl;
    cout << "3: To check in a video" << endl;
    cout << "4: To see whether a particular video is in stock"
         << endl;
    cout << "5: To print the titles of all the videos" << endl;
    cout << "6: To print a list of all the videos" << endl;
    cout << "9: To exit" << endl;
}


void loginView(customerType& current, unorderedLinkedList<customerType>& custList, bool& custLogin)
{
	int choice;
	bool loggingIn = true; // for log in looop
	custLogin = false; //updates global bool of having a customer logged in
	string fname, lname, ftemp, ltemp;//for use of finding customer in list
	customerType temp, newCust;
	while (loggingIn) { // customer has these options that loop until customer is found, created a new account or exited
		cout << "Welcome to the Video store type a number and hit enter to make a choice" << endl;
		cout << " 1: Existing user (from database)" << endl;
		cout << " 2: New user" << endl;
		cout << " 3: Exit now" << endl;
		cin >> choice;

		
		switch (choice) {
			case 1:
				
				cout << "Enter a first name" << endl;
				cin >> ftemp;
				cout << "Enter a last name" << endl;
				cin >> ltemp;
				temp = customerType(ftemp, ltemp); //temp customer for search
				if (custList.search(temp)) { //search customer
					current = custList.get(temp); //retrieves that customer
					cout << "Hello " << current.getFullName(); //greet
					//set boolean parameters
					loggingIn = false;
					custLogin = true;
				}
				else {
					cout << "Customer not found" << endl;
				}
				break;
			case 2:
				
				cout << "Enter a first name" << endl;
				cin >> fname;
				cout << "Enter a last name" << endl;
				cin >> lname;
				newCust = customerType(fname, lname); // create a new customer
				custList.insertLast(newCust);//insert to list
				current = newCust; // set current to the new customer
				cout << "Welcome " << current.getFullName(); // greet
				//set boolean params
				custLogin = true;
				loggingIn = false;
				break;
			case 3:
				cout << "Good bye" << endl;

				custLogin = false;
				loggingIn = false;
				break;
			default:
				cout << "Incorrect input" << endl;
				break;
		}

			
	}
}

