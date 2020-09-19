#ifndef __SEARCH__
#define __SEARCH__
#include "RecursionCounter.h"

class Search
{
public:
	Search(int size);
	~Search(); 
	bool SequentialSearch(int target);
	bool RecursiveBinarySearch(int target);
	bool IterativeBinarySearch(int target);
	void InitSortedArray();
	int* GetDataArray();

private:
	bool RecursiveBinarySearchHelper(int lowIndex, int highIndex, int target) const;
	int* arraytobesearched; 
	int size; 
};
#endif
