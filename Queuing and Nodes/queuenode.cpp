#include "queuenode.h"

QueueNode::QueueNode() // constructor
{
	pData;
	pNext = NULL;
}

QueueNode::QueueNode(data newData, Grocery newList)
{
	pData.setCustomerNumber(newData.getCustomerNumber());
	pData.setServiceTime(newData.getServiceTime());
	pData.setTotalTime(newData.getTotalTime());
	list = newList;
	pNext = NULL;
}

QueueNode::QueueNode(QueueNode &newData, Grocery &newList)
{
	pNext = newData.getpNext();
	list = newList;
}

QueueNode::~QueueNode() //destructor
{

}

data QueueNode::getData()
{
	data temp;
	temp.setCustomerNumber(this->pData.getCustomerNumber());
	temp.setServiceTime(this->pData.getServiceTime());
	temp.setTotalTime(this->pData.getTotalTime());

	return temp;
}

QueueNode * QueueNode::getpNext()
{
	return pNext;
}

void QueueNode::setData(data newData)
{
	pData = newData;
}

void QueueNode::setpNext(QueueNode *newpNext)
{
	pNext = newpNext;
}

Grocery QueueNode::getGrocery()
{
	return list;
}