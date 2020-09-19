#include "Node.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;

Node::Node(int data, Node* leftChild, Node* rightChild) {
	this->data = data;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
	height = 0;
}

bool Node::IsLeaf() {
	if (leftChild == nullptr && rightChild == nullptr) {
		return true;
	}

	else {
		return false;
	}
}

void Node::UpdateHeight() {
	int leftChildsHeight = leftChild ? leftChild->height : -1;
	int rightChildsHeight = rightChild ? rightChild->height : -1;
	height = max(rightChildsHeight, leftChildsHeight) + 1;
}
