#include "Search.h"
#include <random>

//Constructor. Initializes a Search Object with an internal integer array of the specified size
Search::Search(int size) {
	this->size = size;
	arraytobesearched = new int[size];
}

//Destructor. Destroys all data allocated by the constructor
Search::~Search() {
	delete [] arraytobesearched;
}

// returns true if target is found in the object's data array
bool Search::SequentialSearch(int target) {
	for (int i = 0; i < size; i++) {
		if (arraytobesearched[i] == target) {
			return true;
		}
	}
	return false;
}

// returns true if target is found in the object's data array (recursive)
bool Search::RecursiveBinarySearch(int target) {

	return RecursiveBinarySearchHelper(0, size - 1, target);
}

//called by RecursiveBinarySearch(). This is what searches, /2, searches, /2...recursively until target is found.
bool Search::RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const {
	RecursionCounter rcTmp;	// used for unit testing DO NOT REMOVE

	int midIndex = (highIndex + lowIndex) / 2;

	//base case
	if (lowIndex > highIndex) {
		return false;
	}

	//base case
	if (arraytobesearched[midIndex] == target) {
		return true;
	}

	if (arraytobesearched[midIndex] < 0) {
		return false;
	}

	if (target > arraytobesearched[midIndex]) {
		return RecursiveBinarySearchHelper(midIndex + 1, highIndex, target);
	}

	else {
		return RecursiveBinarySearchHelper(lowIndex, midIndex - 1, target);
	}
}

// returns true if target is found in the object's data array. This is what searches, /2, searches, /2... NOT recursively until target is found.
bool Search::IterativeBinarySearch(int target) {
	int lowIndex = 0;
	int highIndex = size - 1;
	int midIndex;

	while (lowIndex <= highIndex) {
		midIndex = (lowIndex + highIndex) / 2; //automatically truncates because int/int

		if (arraytobesearched[midIndex] == target) {
			return true;
		}

		else if (arraytobesearched[midIndex] < target) {
			lowIndex = midIndex + 1;
		}

		else { //if arraytobesearched[midIndex] > target
			highIndex = midIndex - 1;
		}
	}
	return false;
}

/*Function to initialize the array with sorted random numbers
call srand(0) before initializing to get the same numbers each time
Don't use a sort() function here. Rather, when initializing, insert a number a bit larger than the previous number.
Array[0] = rand() % 5
Array[i + 1] = Array[i] + rand() % 5 etc.*/
void Search::InitSortedArray() {
	srand(0);
	arraytobesearched[0] = rand() % 20;
	for (int j = 0; j < size; ++j) {
		arraytobesearched[j + 1] = arraytobesearched[j] + rand() % 20;
	}
}

// returns a pointer to the array of integers
int* Search::GetDataArray() {
	return arraytobesearched;
}
