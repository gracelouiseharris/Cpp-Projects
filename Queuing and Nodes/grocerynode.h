
#include <iostream>
#include <string>
#include <vector>

class GroceryNode
{
public:

	GroceryNode(std::string newItem = "", GroceryNode *newNext = NULL); //constructor

	~GroceryNode(); //destructor

	GroceryNode(GroceryNode &newItem); //copy constructor

	std::string getItem(); //returns item
	GroceryNode *getpNext(); //returns next pointer

	void setItem(std::string pItem); //sets item
	void setpNext(GroceryNode *pNext); //sets next pointer


private:
	std::string Item;
	GroceryNode *pNext;
};