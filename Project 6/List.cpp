#include "List.h"
#include <iostream>

using namespace std;

//default constructor
List::List() {
	head = nullptr;
	many_nodes = 0; 
}
//deconstructor
List::~List() {
	while (head != nullptr) {
		Node* next = head->next;
		delete head;
		head = next;
		many_nodes--;
	}
}
// add new node to front of the list
void List::push_front(const int& value) {
	head = new Node(head, value);
	many_nodes++;
}
// add new node to back of the list
void List::push_back(const int& value) {
	Node* newNode = new Node(nullptr, value);
	//if list is empty
	if (head == nullptr) {
		head = newNode;
	}

	//otherwise, add to end
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	many_nodes++;
}
// removes ALL nodes in list with this value
void List::remove(const int& value) {
	Node* previous = nullptr;
	Node* current = head;

	while (current != nullptr) {
		//removing node at the beginning of the list
		if (current->data == value && previous == nullptr){
			Node* temp = current;
			current = current->next;
			head = current;
			delete temp;
			many_nodes--;
		}
		else if (current->data == value) {
			previous->next = current->next;
			delete current;
			current = previous->next;
			many_nodes--;
		}
		else {
			previous = current;
			current = current->next;
		}
	}
}
// iterator to the beginning of the list
Iterator List::begin() {
	return Iterator(head);
}
// iterator to the end of the list
Iterator List::end() {
	return Iterator(nullptr);
}
// number of elements currently in list
int List::size() {
	return many_nodes;
}
// mainly for debugging
void List::PrintList() {
	for (Node* current = head; current != nullptr; current = current->next) {
		cout << current->data << ' ';
	}
}
