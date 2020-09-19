#include "Observer.h"

#ifndef NODE
#define NODE

class Node {
public:
	Node(int data, Node* leftChild, Node* rightChild);
	~Node() = default;
	bool IsLeaf();
	void UpdateHeight();

	int data;
	int height;
	Node* leftChild;
	Node* rightChild;
private:
	Observer neededForUnitTest;
};
#endif // !NODE
