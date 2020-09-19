#include "HashMap.h"
#include <iostream>
using namespace std;

Iterator::Iterator(int index, Node** hashArray, int sizeOfArray) {
	this->index = index;
	this->current = hashArray[index];
	this->hashArray = hashArray;
	this->sizeOfArray = sizeOfArray;
}

Iterator::Iterator() {
	this->index = 0;
	this->current = nullptr;
	this->hashArray = nullptr;
	this->sizeOfArray = 0;
}

// these next three functions are often found in an external iterator
string Iterator::operator*() {
	return current->key;
}

void Iterator::operator++() {
	if (current->next != nullptr) {
		current = current->next; 
	}
	else {
		index++;
		while (hashArray[index] == nullptr) {
			index++;
		}
		current = hashArray[index];
	}
}

bool Iterator::operator!=(Iterator& other) {
	return current != other.current;
}

bool Iterator::is_item() {
	if (current != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
