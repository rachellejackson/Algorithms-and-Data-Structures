#include <cassert>
#include "Iterator.h"

using namespace std;

// The iterator initially points to "start".
Iterator::Iterator(Node* start) {
	current = start;
}
// dereference the iterator
int Iterator::operator*() {
	return current->data;
}
// advance the iterator
Iterator Iterator::operator++() {
	current = current->next;
	return *this;
}
// returns true if and only if other iterator does not equal this iterator
bool Iterator::operator!=(const Iterator& other) {
	return current != other.current;
}
// returns true if Iterator points to a valid Node (if nullptr return false…)
bool Iterator::is_item() {
	if (current != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
