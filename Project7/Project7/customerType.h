#include "videoType.h"
#include "unorderedLinkedList.h"
#include "videoBinaryTree.h"
using namespace std;


class customerType {
public:
	customerType(string,string);
	customerType();
	string getFullName()const;
	string getFirstName() const;
	string getLastName() const;
	int getNumCheckedOut()const;
	void setFisrtName(string);
	void setFirstName(string);
	void checkOut(string video);
	void checkIn(string,bool);
	void printVideos();
	
	bool operator==(const customerType&) const;
	bool operator!=(const customerType&) const;
	bool operator<(const customerType&) const;
	bool operator<=(const customerType&) const;
	bool operator>(const customerType&) const;
	bool operator>=(const customerType&) const;

	
private:
	string fname;
	string lname;
	unorderedLinkedList<string> videoList;


};