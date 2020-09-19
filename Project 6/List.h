#ifndef __LIST
#define __LIST__
#include "Node.h"
#include "Iterator.h"

class List
{
public:
	//default constructor
	List();
	//deconstructor
	~List();
	// add new node to front of the list
	void push_front(const int& value);
	// add new node to back of the list
	void push_back(const int& value);
	// removes ALL nodes in list with this value
	void remove(const int& value);
	// iterator to the beginning of the list
	Iterator begin();
	// iterator to the end of the list
	Iterator end();
	// number of elements currently in list
	int size();
	// mainly for debugging
	void PrintList();
private:
	//start node
	Node* head;
	int many_nodes;
};
#endif
