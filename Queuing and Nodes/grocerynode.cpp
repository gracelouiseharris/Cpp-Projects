#include "grocerynode.h"

GroceryNode::GroceryNode(std::string newItem, GroceryNode *newNext) // constructor
{
	Item = newItem;
	pNext = newNext;
}

GroceryNode::GroceryNode(GroceryNode &newNode)
{
	pNext = newNode.getpNext();
}

GroceryNode::~GroceryNode() //destructor
{

}

std::string GroceryNode::getItem()
{
	return Item;
}

GroceryNode * GroceryNode::getpNext()
{
	return pNext;
}

void GroceryNode::setItem(std::string newItem)
{
	Item = newItem;
}

void GroceryNode::setpNext(GroceryNode *newpNext)
{
	pNext = newpNext;
}