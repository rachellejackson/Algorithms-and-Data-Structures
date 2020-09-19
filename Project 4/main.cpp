#include <iostream>
#include <random>
#include "Timer.h"
#include "Search.h"

using namespace std;

// used for Recursion Unit Testing. DO NOT REMOVE
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

// add code here

int main() {
	int arraysize = 1'000'000;
	Search SearchObject(arraysize); 
	Timer ti; 
	int result = 0;
	
	cout << "Creating a sorted array of " << arraysize << endl;
	cout << "Finished creating a sorted array of " << arraysize << endl << endl;

	cout << "Searching for a number at the start of the array" << endl;

	//Sequential search beginning number
	ti.Start(); 
	SearchObject.SequentialSearch(SearchObject.GetDataArray()[0]);
	ti.End();
	if (SearchObject.SequentialSearch(SearchObject.GetDataArray()[0]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Iterative Binary search beginning number
	ti.Start();
	SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[0]);
	ti.End();
	if (SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[0]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Recursive Binary search beginning number
	ti.Start();
	SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[0]);
	ti.End();
	if (SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[0]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "Searching for a number in the middle of the array" << endl;

	//Sequential search middle number
	int middle = (arraysize / 2) - 1;
	ti.Start();
	SearchObject.SequentialSearch(SearchObject.GetDataArray()[middle]);
	ti.End();
	if (SearchObject.SequentialSearch(SearchObject.GetDataArray()[middle]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Iterative Binary search middle number
	ti.Start();
	SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[middle]);
	ti.End();
	if (SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[middle]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Recursive Binary search middle number
	ti.Start();
	SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[middle]);
	ti.End();
	if (SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[middle]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;


	cout << "Searching for a number at the end of the array" << endl;
	//Sequential search end number
	int end = arraysize - 1;
	ti.Start();
	SearchObject.SequentialSearch(SearchObject.GetDataArray()[end]);
	ti.End();
	if (SearchObject.SequentialSearch(SearchObject.GetDataArray()[end]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Iterative Binary search end number
	ti.Start();
	SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[end]);
	ti.End();
	if (SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[end]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Recursive Binary search end number
	ti.Start();
	SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[end]);
	ti.End();
	if (SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[end]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "Searching for a number NOT in the array" << endl;
	//Sequential search notinthearray
	int notinthearray = -1;
	ti.Start();
	SearchObject.SequentialSearch(SearchObject.GetDataArray()[notinthearray]);
	ti.End();
	if (SearchObject.SequentialSearch(SearchObject.GetDataArray()[notinthearray]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.SequentialSearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Iterative Binary search notinthearray
	ti.Start();
	SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[notinthearray]);
	ti.End();
	if (SearchObject.IterativeBinarySearch(SearchObject.GetDataArray()[notinthearray]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.IterativeBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	//Recursive Binary search notinthearray number
	ti.Start();
	SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[notinthearray]);
	ti.End();
	if (SearchObject.RecursiveBinarySearch(SearchObject.GetDataArray()[notinthearray]) == true) {
		result = 1;
	}
	else result = 0;

	cout << '\t' << "s.RecursiveBinarySearch() returned " << result << " in " << ti.DurationInNanoSeconds() << "ns" << endl;
}
