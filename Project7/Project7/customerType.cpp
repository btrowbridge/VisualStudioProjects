#include "customerType.h"

customerType::customerType(string f, string l)
{
	fname = f;
	lname = l;
}

customerType::customerType()
{
}

string customerType::getFullName() const
{
	return fname + " " + lname;
}

string customerType::getFirstName() const
{
	return fname;
}

string customerType::getLastName() const
{
	return lname;
}

int customerType::getNumCheckedOut() const
{
	return videoList.length();
}


void customerType::setFisrtName(string name)
{
	fname = name;
}

void customerType::setFirstName(string name)
{
	fname = name;
}

void customerType::printVideos()
{
	videoList.print();
}



void customerType::checkOut(string video)
{
	videoList.insertFirst(video);
}

void customerType::checkIn(string video, bool found)
{
	if (videoList.search(video)) {
		videoList.deleteNode(video);
		found = true;
	}
	else {
		cout << "You dont have that video" << endl;
		found = false;
	}

}

bool customerType::operator==(const customerType& right) const
{
	return (getFullName() == right.getFullName());
}

bool customerType::operator!=(const customerType& right) const
{
	return (getFullName() != right.getFullName());
}

bool customerType::operator<(const customerType& right) const
{
	return (getFullName() < right.getFullName());
}

bool customerType::operator<=(const customerType& right) const
{
	return (getFullName() <= right.getFullName());
}

bool customerType::operator>(const customerType& right) const
{
	return (getFullName() > right.getFullName());
}

bool customerType::operator>=(const customerType& right) const
{
	return (getFullName() >= right.getFullName());
}

ostream& operator<<(ostream& os, const customerType &cust)
{
	os << endl;
	os << "First Name " << cust.getFirstName() << endl;
	os << "Last Name " << cust.getLastName() << endl;
	os << "Movies Checked out: "<< cust.getNumCheckedOut() << endl;
	
	os << "_____________________________________" << endl;
	return os;
}