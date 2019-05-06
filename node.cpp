// Implementation file for the node class

#include "node.h"

// constructor
node::node(int value)
{
	data = value;

	one = nullptr;
	two = nullptr;
	three = nullptr;
	four = nullptr;
}

// Copy constructor
node::node(node* copyFrom)
{
	data = copyFrom->data;

	one = copyFrom->one;
	two = copyFrom->two;
	three = copyFrom->three;
	four = copyFrom->four;
}