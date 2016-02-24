#include <iostream>
#include <string>
#include "videoBinaryTree.h"

using namespace std;

bool videoBinaryTree::isVideoAvailable(string title) 
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		return current->info.getNoOfCopiesInStock() > 0;
	else
		cout << "Video is not in database";
	return false;

}

void videoBinaryTree::videoCheckIn(string title)
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	current->info.checkIn();
}

void videoBinaryTree::videoCheckOut(string title)
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		current->info.checkOut();
	else
		cout << "Video is not in database";
	
}

bool videoBinaryTree::videoCheckTitle(string title)
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		return current->info.checkTitle(title);
	else
		cout << "Video is not in database";
	return false;
}

void videoBinaryTree::videoUpdateInStock(string title, int num)
{	
	
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		num = current->info.getNoOfCopiesInStock();
	else
		cout << "Video is not in database";
	
}

void videoBinaryTree::videoSetCopiesInStock(string title, 
											int num)
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		current->info.setCopiesInStock(num);
	else
		cout << "Video is not in database";
	
}

bool videoBinaryTree::videoSearch(string title)
{
	bool found;
	binaryTreeNode<videoType>* current;
	searchVideoList(title, found, current);
	if (found)
		return search(current->info);
	else
		cout << "Video is not in database";
	return false;
}


void videoBinaryTree::searchVideoList(string title, bool& found,
                                   binaryTreeNode<videoType>* &current)
{
    found = false;   
   
    videoType temp;

    temp.setVideoInfo(title, "", "", "", "", "", 0);

    if (root == NULL)  //the tree is empty
        cout << "Cannot search an empty list. " << endl;
    else
    {
        current = root; //set current point to the root node 
                        //of the binary tree
        found = false;  //set found to false

        while (!found && current != NULL) //search the tree
            if (current->info == temp)    //the item is found
                found = true;
            else if(current->info > temp)
                current = current->llink;
            else
                current = current->rlink;
    } //end else
}

void videoBinaryTree::videoPrintTitle()
{
	inorderTitle(root);
}

void videoBinaryTree::inorderTitle(binaryTreeNode<videoType> *p)
{
    if (p != NULL)
    {
        inorderTitle(p->llink);
        p->info.printTitle();
        inorderTitle(p->rlink);
    }
}



