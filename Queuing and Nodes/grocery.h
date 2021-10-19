#include "grocerynode.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Grocery
{
public:

	Grocery(); //constructs grocery list

	~Grocery(); //destructor

	GroceryNode *getHead(); //returns head pointer

	void setHead(GroceryNode *newHead); //sets head pointer

	void enqueue(std::string newItem); //adds item to the list
	
	void printGrocery(); //prints the list

	Grocery createlist(int time); //creates a list with randomized items

private:
	GroceryNode *pHead;
};

std::ostream &operator<<(std::ostream &lhs, std::string &rhs); //prints to screen
