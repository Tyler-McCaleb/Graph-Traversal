

#include <vector>

#ifndef NODE_H
#define NODE_H


class node
{
public:
	// data and pointers
	int data;
	node* one;
	node* two;
	node* three;
	node* four;

	// constructor
	node(int value);

	// Copy Constuctor
	node(node* copyFrom);

	// Vector to hold the path to this node
	std::vector<int> path;
};
#endif
