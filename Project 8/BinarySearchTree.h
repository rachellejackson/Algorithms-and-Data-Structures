#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "Node.h"
#include <iostream>

using namespace std;

class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Insert(int data);
	Node* Search(int data);
	void Remove(int data);
	void InorderTraversal();
	void Print();
	int Size();

private:
	void DestructorHelper(Node* cursor);
	Node* InsertHelper(Node* current, int data);
	Node* SearchHelper(Node* current, int data);
	Node* RemoveHelper(Node* current, int data);
	void InorderHelper(Node* current);
	void PrintHelper(string offset, Node* current);
	int SizeHelper(Node* current);

	Node* root;
};
#endif 
