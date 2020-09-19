#include "HashMap.h"
#include <iostream>
using namespace std;

//size is the size of the array
HashMap::HashMap(int size){
	//creates new array with specified size
	hashArray = new Node* [size];
	//initializes everything in the array with nullptr
	for (int i = 0; i < size; i++){
		hashArray[i] = nullptr;
	}
	sizeOfArray = size;
}

HashMap::~HashMap() {
	//deletes each node in the array
	for (int i = 0; i < sizeOfArray; i++) {
		Node* current = hashArray[i];
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	//deletes the array
	delete[] hashArray;
}

// return true if key is in map
bool HashMap::IsKeyPresent(string const& key) const {
	int index = GenerateHash(key);
	Node* current = hashArray[index];
	while (current != nullptr) {
		if (current->key == key) {
			return true;
		}
		else {
			current = current->next;
		}
	}
	return false;
}

// if key is not present, add to map and then set value
// NOTE: GetKeyValue() returns a bool (true if the key was present in the map) and it ALSO "returns"
// the value of that key through the parameter "value". Notice that "value" is a "pass by reference" parameter
void HashMap::SetKeyValue(string const& key, int value) {
	int index = GenerateHash(key);
	if (IsKeyPresent(key)) {
		Node* current = hashArray[index]; 
		while (current != nullptr) {
			if (current->key == key) {
				current->value = value;
				return;
			}
			else {
				current = current->next;
			}
		}
	}
	else {
		if (hashArray[index] == nullptr) {
			hashArray[index] = new Node(key, value);
		}
		else {
			Node* current = hashArray[index];
			while (current) {
				if (current->next == nullptr) {
					current->next = new Node(key, value);
					return;
				}
				else {
					current = current->next;
				}
			}
		}
	}
}


// if key is not present, return false
bool HashMap::GetKeyValue(string const& key, int& value) {
	int index = GenerateHash(key);
	Node* current = hashArray[index];
	if (IsKeyPresent(key) == false) {
		return false;
	}
	else {
		while (current->key != key) {
			current = current->next;
		}
		value = current->value; 
		return true;
	}
}

Iterator HashMap::begin() {
	for (int i = 0; i < sizeOfArray; i++) { 
		if (hashArray[i] != nullptr) {
			return Iterator(i, hashArray, sizeOfArray);
		}
	}
}

Iterator HashMap::end() {
	return Iterator(sizeOfArray, hashArray, sizeOfArray);
}

// converts the key to an value used to index into the array
int HashMap::GenerateHash(string key) const {
	int hash = 0;
	int index;
	for (size_t i = 0; i < key.length(); ++i) {
		hash = hash + (int)key[i];
	}
	index = hash % sizeOfArray;
	return index;
}
