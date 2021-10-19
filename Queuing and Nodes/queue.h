#include "queuenode.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>

class Queue
{
public:

	Queue(); //constructor

	Queue(Queue &copy); //copy constructor

	~Queue(); //destructor

	QueueNode *getHead(); //returns head pointer
	QueueNode *getTail(); //returns tail pointer

	void setHead(QueueNode *newHead); //sets head pointer
	void setTail(QueueNode *newTail); //sets tail pointer

	void enqueue(data newData, Grocery newList); //adds a node to the queue
	data dequeue(); //deletes a node and returns the data in the node
	
	void printQueue(); //prints entire queue

	int isEmpty(); //checks if queue is empty

	void run(); //runs the simulation
	void runtesttenminutes(); //runs simulation for 24 hours and prints every ten minutes
	void runtestshort(); //runs the simulation for 24 hours and only prints once

private:
	QueueNode *pHead;
	QueueNode *pTail;
};

std::ostream &operator<<(std::ostream &lhs, data &rhs); //prints to screen