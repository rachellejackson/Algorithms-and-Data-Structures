#include "BinarySearchTree.h"
#include "RecursionCounter.h"
#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree(){
	DestructorHelper(root);
}

void BinarySearchTree::DestructorHelper(Node* cursor) {
	// base case
	if (cursor == nullptr)
		return;

	// delete cursor node, once it's children have been deleted
	DestructorHelper(cursor->leftChild);
	DestructorHelper(cursor->rightChild);

	delete cursor;
}

void BinarySearchTree::Insert(int data) {

	root = InsertHelper(root, data);
}

Node* BinarySearchTree::InsertHelper(Node* current, int data) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE

	//Case 1 - Empty tree. Becomes the root node.
	if (current == nullptr) {
		Node* newNode = new Node(data, nullptr, nullptr);
		return newNode;
	}
	//Case 2 - Smaller value. Recursively add to left
	if (data < current->data) {
		current->leftChild = InsertHelper(current->leftChild, data);
	}

	//case 3 - Larger or equal value. Recursively add to right.
	else {
		current->rightChild = InsertHelper(current->rightChild, data);
	}

	current->UpdateHeight();
	return current;
}

Node* BinarySearchTree::Search(int data) {
	Node* newNode = SearchHelper(root, data);
	return newNode;
}

Node* BinarySearchTree::SearchHelper(Node* current, int data) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE
	if (current == nullptr) {
		return nullptr;
	}

	if (current->data == data) {
		return current;
	}

	else if (data < current->data) {
		return SearchHelper(current->leftChild, data);
	}

	else /*(data >= current->data)*/ {
		return SearchHelper(current->rightChild, data);
	}
}

void BinarySearchTree::Remove(int data) {
	root = RemoveHelper(root, data);
}

Node* BinarySearchTree::RemoveHelper(Node* current, int data) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE

	if (current == nullptr) {
		return nullptr;
	}

	else if (current->data == data) {
		//Node has no children
		if (current->leftChild == nullptr && current->rightChild == nullptr) {
			delete current;
			current = nullptr;
			return nullptr;
		}

		//Node has one child (left)
		else if (current->rightChild == nullptr) {
			Node* temp = current;
			current = current->leftChild;
			delete temp;
		}

		//Node has one child (right)
		else if (current->leftChild == nullptr) {
			Node* temp = current;
			current = current->rightChild;
			delete temp;
		}

		//Node has two children
		else {
			Node* smallest = current->rightChild;
			while (smallest->leftChild != nullptr) {
				smallest = smallest->leftChild;
			}
			current->data = smallest->data;
			current->rightChild = RemoveHelper(current->rightChild, smallest->data);
		}
	}

	else if (current->data > data) {
		current->leftChild = RemoveHelper(current->leftChild, data);
	}

	else {
		current->rightChild = RemoveHelper(current->rightChild, data);
	}

	current->UpdateHeight();
	return current;
}

void BinarySearchTree::InorderTraversal() {
	InorderHelper(root);
	cout << endl;
}

void BinarySearchTree::InorderHelper(Node* current) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE
	if (current == nullptr) {
		return;
	}

	InorderHelper(current->leftChild);
	cout << current->data << ", ";
	InorderHelper(current->rightChild);
}

void BinarySearchTree::Print() {
	PrintHelper("", root);
	cout << endl;
}

void BinarySearchTree::PrintHelper(string offset, Node* current) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE

	if (current == nullptr) {
		cout << offset << "[Empty]" << endl;
	}

	else {

		cout << offset << current->data << " (" << current->height << ") " << (current->IsLeaf() ? "" : "\n");

		if (current->IsLeaf()) {
			cout << "[leaf]" << endl;
		}
		else {
			// left
			PrintHelper(offset + "   ", current->leftChild);

			// right
			PrintHelper(offset + "   ", current->rightChild);
		}
	}
}

int BinarySearchTree::Size() {
	return SizeHelper(root);
}

int BinarySearchTree::SizeHelper(Node* current) {
	RecursionCounter neededForUnitTest;        // MUST BE HERE

	if (current == nullptr) {
		return 0;
	}

	else {
		return (SizeHelper(current->leftChild) + SizeHelper(current->rightChild) + 1);
	}
}
