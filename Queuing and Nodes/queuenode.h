
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Data.h"
#include "grocery.h"

class QueueNode
{
public: 

	QueueNode(); //constructs a node

	QueueNode(data newData, Grocery newList); //constructs a new node

	~QueueNode(); //destructor

	QueueNode::QueueNode(QueueNode &newData, Grocery &newList); //copy constructor

	data getData(); //returns data
	Grocery getGrocery(); //returns grocery list
	QueueNode *getpNext(); //returns next pointer

	void setData(data pData); //sets data
	void setpNext(QueueNode *pNext); //sets next pointer

private:
	data pData;
	QueueNode *pNext;
	Grocery list;
};