#include "DynamicArray.h"
#include <stdexcept>
using namespace std;

//constructor
DynamicArray::DynamicArray(){
	//transactions is the pointer to the actual array
	transactions = new Transaction[INITIAL_CAPACITY];

	// capacity of the array in its current state
	capacity = INITIAL_CAPACITY;

	// number of entries already used in the array
	used = 0; 
}

//destructor
DynamicArray::~DynamicArray() {
	delete[] transactions;
}

// adds newTransaction to the end of the dynamic array
void DynamicArray::push_back(const Transaction& newTransaction) {
	if (used == capacity) {
		Realloc();
	}
	transactions[used++] = newTransaction;
}

// returns the number of Transactions currently stored in the dynamic array
int DynamicArray::size() const {
	return used;
}

// returns the current capacity of the array
int DynamicArray::currentCapacity() const {
	return capacity; 
}

// returns a reference to the Transaction stored at the specified index
Transaction& DynamicArray::at(int index) {
	if (index >= used || index < 0) {
		throw runtime_error("invalid index");
	}
	return transactions[index];
}

// make the current array bigger when the current array is full and push_back() is called
void DynamicArray::Realloc() {
	capacity *= 2; 
	Transaction* temparray = new Transaction[capacity];
	for (int i = 0; i < used; ++i) {
		temparray[i] = transactions[i];
	}
	delete[] transactions;
	transactions = temparray;
}
