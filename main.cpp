/*
	Tyler McCaleb
	Algorithms Project 4
	4/20/2019

	Implements both BFS and DFS on a grapth
	The program will start start the seach from "1" and search for each value in the graph.
	The program will save the path and number of nodes expanded and output the results.
	The path is only recorded for the breadth first search.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "node.h"

using namespace std;

// Global Variables
vector<int> visitedNodes;

// result variables from the searches
int depthExpanded;
bool depthFound;
vector<int> breadthFirstPath;
bool breadthFound;
int breadthExpanded;

// Pointers to each of the nodes to enable starting from any point in the graph
node* nodeOne;
node* nodeTwo;
node* nodeThree;
node* nodeFour;
node* nodeFive;
node* nodeSix;

// Function Prototypes

// Function to check if a node has been visited or not.
bool visited(int checkValue);

// Function to create the graph
void createGraph(node* &root);

// Function to perform a depth first search
void depthFirstSearch(node* graph, int searchValue);

// Fnction to perform a breadth first search
void breadthFirstSearch(node* graph, int searchValue);

// Function to perform all the search trials
void runSearches();

// Display DFS results
void displayDepthResults(int value, int start);

// Display BFS results
void displayBreadthResults(int value, int start);

int main()
{
	// Create the graph
	node* graph = nullptr;
	createGraph(graph);

	// Run the Searches
	runSearches();
	

	cout << "\n\tPress any key to exit..." << endl;
	cout << "\t";
	cin.get();

	return 0;
}

// Function Definitions

// Function to create the graph
void createGraph(node* &root)
{	
	// Pointers to a node containing each number
	nodeOne = new node(1);
	nodeTwo = new node(2);
	nodeThree = new node(3);
	nodeFour = new node(4);
	nodeFive = new node(5);
	nodeSix = new node(6);

	// Connect the nodes via their pointers
	root = nodeOne;
	nodeOne->one = nodeTwo;
	nodeOne->two = nodeThree;
	nodeTwo->one = nodeFour;
	nodeTwo->two = nodeOne;
	nodeTwo->three = nodeFive;
	nodeThree->one = nodeFive;
	nodeThree->two = nodeOne;
	nodeFour->one = nodeTwo;
	nodeFour->two = nodeFive;
	nodeFive->one = nodeSix;
	nodeFive->two = nodeFour;
	nodeFive->three = nodeTwo;
	nodeFive->four = nodeThree;
	nodeSix->one = nodeFour;
	nodeSix->two = nodeFive;

	return;
}

// Function to check if a node has been visited or not.
bool visited(int checkValue)
{
	// Search throug the visitedNodes vector to see if the node has already been visited
	for (int i = 0; i < visitedNodes.size(); i++)
	{
		// Return true if the value is present inside of the vector
		if (visitedNodes[i] == checkValue)
		{
			return true;
		}
	}

	// Return false if the loop finished
	return false;
}

// Function to perform a depth first search
void depthFirstSearch(node* graph, int searchValue)
{
	// Reset the global values
	depthExpanded = 0;
	depthFound = false;

	// Boolean to hold if the value has been found
	bool found = false;

	// Node to hold the top of the stack
	node* topValue;

	// Create the stack
	stack<node> searchStack;

	// Create the first state to be checked in the stack
	node firstState(graph);

	// Create the path with the first data
	firstState.path.push_back(graph->data);

	// Add the first value to the stack
	searchStack.push(firstState);

	// loop through the graph to find the value
	while (found == false)
	{
		// Make sure the stack is not empty
		if (searchStack.empty())
		{
			depthFound = false;
			visitedNodes.clear();
			return;
		}

		// Check the top of the stack and see if it is the search value
		if (searchStack.top().data == searchValue)
		{
			depthFound = true;
			found = true;
			visitedNodes.clear();
			return;
		}

		// Save the top of the stack
		topValue = &searchStack.top();

		// Pop the stack
		searchStack.pop();

		// Search each of the children from the top of the stack
		if (found != true)
		{
			// Increment nodes expanded
			depthExpanded++;

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->one != nullptr && !visited(topValue->one->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->one->data);

				// Create a new node for the stack
				node nextValue(topValue->one);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchStack.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->two != nullptr && !visited(topValue->two->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->two->data);

				// Create a new node for the stack
				node nextValue(topValue->two);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchStack.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->three != nullptr && !visited(topValue->three->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->three->data);

				// Create a new node for the stack
				node nextValue(topValue->three);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchStack.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->four != nullptr && !visited(topValue->four->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->four->data);

				// Create a new node for the stack
				node nextValue(topValue->four);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchStack.push(nextValue);
			}
		}
	}
}

// Fnction to perform a breadth first search
void breadthFirstSearch(node* graph, int searchValue)
{
	// Create the queue
	queue<node> searchQueue;

	// Reset the global BFS variables
	breadthExpanded = 0;
	breadthFound = false;
	breadthFirstPath.clear();

	// Boolean to hold if the value has been found
	bool found = false;

	// pointer to the first node in the stack
	node* topValue = nullptr;

	// Create the initial node
	node firstValue(graph);

	// Create the path with the first data
	firstValue.path.push_back(graph->data);

	// Add the first value to the node
	searchQueue.push(firstValue);

	// Loop through the graph to search for the value
	while (!found)
	{
		// Make sure the queue is not empty
		if (searchQueue.empty())
		{
			breadthFound = false;
			visitedNodes.clear();
			return;
		}

		// Evaluate thte first node in teh queue to see if it the value
		if (searchQueue.front().data == searchValue)
		{
			breadthFound = true;
			for (int i = 0; i < searchQueue.front().path.size(); i++)
			{
				breadthFirstPath.push_back(searchQueue.front().path[i]);
			}
			visitedNodes.clear();
			return;
		}

		// Save the top of the stack
		topValue = &searchQueue.front();

		// Inspect each of the connected nodes to the front and if they haven't been visited yet add them to the queue
		if (found != true)
		{
			// Increment nodes expanded
			breadthExpanded++;

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->one != nullptr && !visited(topValue->one->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->one->data);

				// Create a new node for the stack
				node nextValue(topValue->one);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchQueue.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->two != nullptr && !visited(topValue->two->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->two->data);

				// Create a new node for the stack
				node nextValue(topValue->two);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchQueue.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->three != nullptr && !visited(topValue->three->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->three->data);

				// Create a new node for the stack
				node nextValue(topValue->three);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchQueue.push(nextValue);
			}

			// Check each of the children from the top and if they are not already checked add them to the stack
			if (topValue->four != nullptr && !visited(topValue->four->data))
			{
				// Add the new value to the visited vector
				visitedNodes.push_back(topValue->four->data);

				// Create a new node for the stack
				node nextValue(topValue->four);

				// Add the path from the previous node to the current and add this step
				for (int i = 0; i < topValue->path.size(); i++)
				{
					nextValue.path.push_back(topValue->path[i]);
				}
				nextValue.path.push_back(nextValue.data);

				// Add the new node to the stack
				searchQueue.push(nextValue);
			}
			searchQueue.pop();
		}
	}
}

// Function to perform all the search trials
void runSearches()
{
	cout << "\n\t************************ Depth First Searches **********************\n" << endl;
	cout << "\tStart Point\t" << "Search Value\t" << "Nodes Expanded to Reach Search Value\n" << endl;

	// Run the depth first searches
	for (int i = 1; i < 7; i++)
	{
		depthFirstSearch(nodeOne, i);
		displayDepthResults(i, 1);
		depthFirstSearch(nodeTwo, i);
		displayDepthResults(i, 2);
		depthFirstSearch(nodeThree, i);
		displayDepthResults(i, 3);
		depthFirstSearch(nodeFour, i);
		displayDepthResults(i, 4);
		depthFirstSearch(nodeFive, i);
		displayDepthResults(i, 5);
		depthFirstSearch(nodeSix, i);
		displayDepthResults(i, 6);
		cout << endl;
	}

	cout << "\n\tPress Enter to view Breadth First Search Results" << endl;
	cin.get();
	system("CLS");


	cout << "\n\t************************ Breadth First Searches **********************\n" << endl;
	cout << "\tStart Point\t" << "Search Value\t" << "Nodes Expanded\t" << "Path to Target Value\n" << endl;

	// Run the depth first searches
	for (int i = 1; i < 7; i++)
	{
		breadthFirstSearch(nodeOne, i);
		displayBreadthResults(i, 1);
		breadthFirstSearch(nodeTwo, i);
		displayBreadthResults(i, 2);
		breadthFirstSearch(nodeThree, i);
		displayBreadthResults(i, 3);
		breadthFirstSearch(nodeFour, i);
		displayBreadthResults(i, 4);	
		breadthFirstSearch(nodeFive, i);
		displayBreadthResults(i, 5);
		breadthFirstSearch(nodeSix, i);
		displayBreadthResults(i, 6);
		cout << endl;
	}
	return;
}

// Display DFS results
void displayDepthResults(int value, int start)
{
	cout << "\t";
	cout << start << "\t\t";
	cout << value << "\t\t";
	cout << depthExpanded << endl;
	return;
}

// Display BFS results
void displayBreadthResults(int value, int start)
{
	cout << "\t";
	cout << start << "\t\t";
	cout << value << "\t\t";
	cout << breadthExpanded <<"\t\t";
	if (breadthFirstPath.size() > 0)
	{
		for (int i = 0; i < breadthFirstPath.size(); i++)
		{
			if (i != breadthFirstPath.size() - 1)
			{
				cout << breadthFirstPath[i] << " -> ";
			}
			else
			{
				cout << breadthFirstPath[i];
			}
		}
	}
	cout << endl;
	return;
}

