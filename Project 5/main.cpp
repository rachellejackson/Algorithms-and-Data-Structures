#include <iostream>
#include "Sort.h"
#include "Timer.h"

using namespace std;

// used for Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main() {
	const int size = 20;
	Sort SortObject(size);

	Timer timer;

	//Selection Sort
	cout << "starting SelectionSort" << endl;
	timer.Start();
	SortObject.SelectionSort();
	timer.End(); 
	cout << "Selection Sort duration: " << timer.DurationInMicroSeconds() << "ms." << endl << endl;

	//Insertion Sort
	cout << "starting InsertionSort" << endl;
	timer.Start();
	SortObject.InsertionSort();
	timer.End();
	cout << "Insertion Sort duration: " << timer.DurationInMicroSeconds() << "ms." << endl << endl;

	//Merge Sort
	cout << "starting MergeSort" << endl;
	timer.Start();
	SortObject.MergeSort();
	timer.End();
	cout << "Merge Sort duration: " << timer.DurationInMicroSeconds() << "ms." << endl << endl;

	//Quick Sort
	cout << "starting QuickSort" << endl;
	timer.Start();
	SortObject.QuickSort();
	timer.End();
	cout << "Quick Sort duration: " << timer.DurationInMicroSeconds() << "ms." << endl << endl;

	//std::sort()
	cout << "starting std::sort()" << endl;
	timer.Start();
	SortObject.SelectionSort();
	timer.End();
	cout << "std::sort() duration: " << timer.DurationInMicroSeconds() << "ms." << endl << endl;

	return 0;
}
