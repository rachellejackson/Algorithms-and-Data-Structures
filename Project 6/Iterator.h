#ifndef __ITERATOR__
#define __ITERATOR__
#include "Node.h"

using namespace std;

class Iterator
{
public:
	// The iterator initially points to "start".
	Iterator(Node* start);
	// dereference the iterator
	int operator*();
	// advance the iterator
	Iterator operator++();
	// returns true if and only if other iterator does not equal this iterator
	bool operator!=(const Iterator& other);
	// returns true if Iterator points to a valid Node (if nullptr return false…)
	bool is_item();
private:
	Node* current;
};
#endif
