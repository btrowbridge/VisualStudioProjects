#include "arrayListType.h"
#include <iostream>
#include <iomanip>

void fill(arrayListType<int>& , int);

int main() {
	int size = 1000;

	arrayListType<int> insertion(size);
	arrayListType<int> shell(size);
	arrayListType<int> heap(size);

	fill(insertion,size);
	fill(shell, size);
	fill(heap, size);
	int comp, move;

	cout << size << endl;
	cout << setw(20) << left << "Method" << setw(15) << left << "Comparisons" << setw(15) << left << "Movement" << endl;

	insertion.insertionSort(comp,move);
	cout << setw(20) << left << "Insertion Sort: " << setw(15) << left << comp << setw(15) << left << move << endl;
	shell.shellSort(comp, move);
	cout << setw(20) << left << "Shell Sort: " << setw(15) << left << comp << setw(15) << left << move << endl;
	heap.heapSort(comp, move);
	cout << setw(20) << left << "Heap Sort: " << setw(15) << left << comp << setw(15) << left << move << endl;


	return 0;
}

void fill(arrayListType<int>& list, int size) {

	list.clearList();
	int seed = 47;
	int multiplier = 2743;
	int addOn = 5923;
	while (list.listSize() < size) {
		list.insertEnd(seed);
		seed = int((seed*multiplier + addOn) % 100000);
	}
	
}