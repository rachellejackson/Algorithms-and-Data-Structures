#ifndef __NODE__
#define __NODE__
#include "Observer.h"

class Node{

public:
	Node(Node* next, int data);
	Node* next;
	int data;

private:
	Observer tmp;  // for testing purposes only. DO NOT REMOVE
};
#endif
