#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
	void insertOrd(const elemType&);
	
	void fill();

	int binarySearch(const elemType& item) const;
	int binaryWithSeqSearch(const elemType& item)const;

	orderedArrayListType(int size = 100);
};
 
template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    if (length == 0)   //the list is empty
    {
        list[0] = item;
        length++;
    }
    else if (length == maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (list[mid] == item)
                found = true;
            else if (list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while

        if (found)
            cerr << "The insert item is already in the list. "
                 << "Duplicates are not allowed." << endl;
        else
        {
            if (list[mid] < item)
                mid++;

            insertAt(mid, item);
        }
    }
}//end insertOrd

template<class elemType>
int orderedArrayListType<elemType>::binaryWithSeqSearch
                                       (const elemType& item) const
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

	int count = 0;


		while (first <= last && !found)
		{
			mid = (first + last) / 2;
			count++;
			if (list[mid] == item)
				found = true;
			else if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
			//once the partition has reached 15 or below
			if (last - first <= 15) {
				for (int i = first; i <= last; i++) {
					count++;
					if (list[i] == item) { 
						found = true;
						break; 
					}	
				}
				break;
			}
		}
	

	cout << "Binary search with sequential comparisons: " << count << endl;

    if (found) 
        return mid;
    else
        return -1;
}//end binaryWithSeqSearch 

template<class elemType>
int orderedArrayListType<elemType>::binarySearch
(const elemType& item) const
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	int count = 0;


		count = 2;
		while (first <= last && !found)
		{
			mid = (first + last) / 2;
			count++;
			if (list[mid] == item)
				found = true;
			else if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	

	cout << "Binary search comparisons: " << count << endl;

	if (found)
		return mid;
	else
		return -1;
}//end binarySearch


template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}
template<class elemType>
void orderedArrayListType<elemType> :: fill()
{
	int seed = 47;
	int multiplier = 2743;
	int addOn = 5923;
	while (listSize() < maxListSize())
	{
		insertOrd(seed);
		seed = int((seed * multiplier + addOn) % 100000);
	}
}
#endif