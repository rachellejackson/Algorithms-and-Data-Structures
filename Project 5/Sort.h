#ifndef __SORT__
#define __SORT__

#include "RecursionCounter.h"
class Sort
{
public:
	// add code here
	Sort(int arraysize);
	~Sort();
	void InitArray();
	void SelectionSort();
	void InsertionSort();
	void AlgorithmSort();
	void MergeSort();
	void Merge(int i, int j, int k);
	void QuickSort();
	int Partition(int initialLowIndex, int initialHighIndex);
	int GetSize() const;
	int* GetDataArray() const;
private:
	// add code here

	void MergeSortRecursionHelper(int indexI, int indexK);
	void QuickSortRecursionHelper(int initialLowIndex, int initialHighIndex);

	int* arraytobesorted;
	int arraysize; 
};
#endif
