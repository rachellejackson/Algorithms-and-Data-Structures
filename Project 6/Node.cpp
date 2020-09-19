#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(Node* next, int data) {
	this->next = next;
	this->data = data;
}
