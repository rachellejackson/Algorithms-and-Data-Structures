#include <random>
#include <iostream>
#include <algorithm>
#include "Sort.h"

using namespace std;

//constructor
Sort::Sort(int arraysize) {
	this->arraysize = arraysize; 
	arraytobesorted = new int[arraysize];
}

//Destructor
Sort::~Sort() {
	delete[] arraytobesorted;
}

//Function that initializes array with random integers
void Sort::InitArray() {
	srand(0);

	for (int i = 0; i < arraysize; ++i) {
		arraytobesorted[i] = rand() % 20;
	}
}

void Sort::SelectionSort() {
	if (arraysize == 0) {
		return; 
	}

	for (int i = 0; i < arraysize - 1; ++i) { //arraysize - 1 because you compare the second to last element to the last one in the second for loop. 
		int indexofsmallest = i;
		for (int j = i + 1; j < arraysize; ++j) { //j + 1 because you want to start comparing at the element in the second index. 
			if (arraytobesorted[j] < arraytobesorted[indexofsmallest]) {
				indexofsmallest = j;
			}
		}
		int temp = arraytobesorted[i];
		arraytobesorted[i] = arraytobesorted[indexofsmallest];
		arraytobesorted[indexofsmallest] = temp; 
	}
}

void Sort::InsertionSort() {
	for (int i = 0; i < arraysize; ++i) {
		int j = i;
		while (j > 0 && arraytobesorted[j] < arraytobesorted[j - 1]) {
			int temp = arraytobesorted[j];
			arraytobesorted[j] = arraytobesorted[j - 1];
			arraytobesorted[j - 1] = temp;
			j--;
		}
	}
}

void Sort::AlgorithmSort() {
	std::sort(arraytobesorted, arraytobesorted + arraysize);
}

void Sort::MergeSort() {
	MergeSortRecursionHelper(0, arraysize - 1);
}

void Sort::QuickSort() {
	QuickSortRecursionHelper(0, arraysize - 1);
}

int Sort::GetSize() const {
	return arraysize;
}
int* Sort::GetDataArray() const {
	return arraytobesorted;
}

void Sort::Merge(int i, int j, int k) {
	int mergedSize = k - i + 1;
	int mergePos = 0;
	int leftPos = 0;
	int rightPos = j + 1;
	int* mergedNumbers = new int[mergedSize];

	leftPos = i;
	rightPos = j + 1;

	while (leftPos <= j && rightPos <= k) {
		if (arraytobesorted[leftPos] < arraytobesorted[rightPos]) {
			mergedNumbers[mergePos] = arraytobesorted[leftPos];
			++leftPos;
		}
		else {
			mergedNumbers[mergePos] = arraytobesorted[rightPos];
			++rightPos;
		}
		++mergePos;
	}

	while (leftPos <= j) {
		mergedNumbers[mergePos] = arraytobesorted[leftPos];
		++leftPos;
		++mergePos;
	}

	while (rightPos <= k) {
		mergedNumbers[mergePos] = arraytobesorted[rightPos];
		++rightPos;
		++mergePos;
	}

	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		arraytobesorted[i + mergePos] = mergedNumbers[mergePos];
	}
	delete mergedNumbers;
}

void Sort::MergeSortRecursionHelper(int indexi, int indexk)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE
   // add more code here
	int indexcut = 0;
	if (indexi < indexk) {
		//midpoint of the cut
		indexcut = (indexi + indexk) / 2;

		//Recursively sort left and right partitions
		MergeSortRecursionHelper(indexi, indexcut);
		MergeSortRecursionHelper(indexcut + 1, indexk);

		//Merge left and right partition in sorted order
		Merge(indexi, indexcut, indexk);
	}
}

int Sort::Partition(int initialLowIndex, int initialHighIndex) {
	int low = initialLowIndex;
	int high = initialHighIndex;
	int pivotIndex = initialLowIndex + ((initialHighIndex - initialLowIndex) / 2);
	int pivotValue = arraytobesorted[pivotIndex];

	while (!(low >= high)) {
		//Increment low while arraytobesorted[low] < pivotValue
		while (arraytobesorted[low] < pivotValue) {
			low++;
		}

		//decrement high while pivotValue < arraytobesorted[high]
		while (pivotValue < arraytobesorted[high]) {
			high--;
		}
		//If there are zero or one items remaining, all numbers are partitioned.
		//Return high;
		if (low < high) {
			//Swap
			int temp = arraytobesorted[low];
			arraytobesorted[low] = arraytobesorted[high];
			arraytobesorted[high] = temp;

			low++;
			high--;
		}
	}
	return high;
}

void Sort::QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex)
{
	RecursionCounter rcTmp;	// used for Unit Testing. DO NOT REMOVE

   //base case
	if (initialLowIndex >= initialHighIndex) {
		return;
	}

	//Partition the array. Value j is the location of the last element in low partition
	int j = Partition(initialLowIndex, initialHighIndex);

	//Recursively sort low and high partitions
	QuickSortRecursionHelper(initialLowIndex, j);
	QuickSortRecursionHelper(j + 1, initialHighIndex);
}
