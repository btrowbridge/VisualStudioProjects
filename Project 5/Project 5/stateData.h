
#include <string>
#include <iostream>
#include <iomanip>




using namespace std;



class stateData {
private:
	string name;
	string capital;
	int unionNum;
	int year;
	int area;

public:
	//accessor
	string getName() { return name; }
	void setName(string n) { name = n; }
	string getCapital() { return capital; }
	void setCapital(string c) { capital = c; }
	int getUnionNum() { return unionNum; }
	void setUnionNum(int n) { unionNum = n; }
	int getYear() { return year; }
	void setYear(int y) { year = y; }
	int getArea() { return area; }
	void setArea(int a) { area = a; }

	stateData(string iname = " ", string icap = " ", int inum = 0, int iyear = 0, int iarea = 0) {
		name = iname;
		capital = icap;
		unionNum = inum;
		year = iyear;
		area = iarea;
	} // constructor


	//output overload
	friend ostream& operator<<(ostream& out, stateData& state) {
		if (state.getArea() > 0) {
			out << setw(15) << right << state.getName() << " | ";
			out << setw(15) << right << state.getCapital() << " | ";
			out << setw(15) << right << state.getYear() << " | ";
			out << setw(15) << right << state.getUnionNum() << " | ";
			out << setw(15) << right << state.getArea();
		}
		return out;
	}
	//input overload
	friend istream& operator>>(istream& in, stateData& state) {	
		char ch;
		getline(in, state.name);
		getline(in, state.capital);
		in >> state.area >> state.year >> state.unionNum;
		
		in.get(ch);
		
		return in;
	}
	//overload assignment operator
	stateData& operator=(const stateData& other) {
		name = other.name;
		capital = other.capital;
		unionNum = other.unionNum;
		year = other.year;
		area = other.area;

		return *this;
	}

	//overload boolean operators
	bool operator==(const stateData& other) const { return name == other.name; }
	bool operator!=(const stateData& other) const { return name != other.name; }
	bool operator>=(const stateData& other) const { return name >= other.name; }
	bool operator>(const stateData& other) const { return name > other.name; }
	bool operator<=(const stateData& other) const { return name <= other.name; }
	bool operator<(const stateData& other) const { return name < other.name; }
};

