#include "queue.h"
#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Tests
{
public:

	void emptyinsert(); //inserts a node into an empty queue
	void oneinsert(); //inserts a node into a queue with one node
	void onedequeue(); //deletes a node in a queue with only one node
	void twodequeue(); //deletes a node in a queue with two nodes
	void twentyfourhours(); //runs the program for 24 hours

	void runtest(); //runs all the test functions

private:
	Queue test;
};