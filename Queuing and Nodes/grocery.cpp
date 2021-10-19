#include "grocery.h"

Grocery::Grocery() // constructor
{
	pHead = NULL; //set pHead and pTail to NULL aka initalize new queue
}

Grocery::~Grocery() // deconstructor
{

}

void Grocery::setHead(GroceryNode *newHead) //set pHead
{
	this->pHead = newHead;
}

GroceryNode* Grocery::getHead() //return pHead for use in nonmember functions
{
	return pHead;
}

void Grocery::enqueue(std::string newItem)
{
	GroceryNode *pMem = nullptr;
	pMem = new GroceryNode(newItem, this->getHead());

	if (pMem != nullptr)
	{
		this->setHead(pMem);
	}
}

void Grocery::printGrocery()
{
	std::string temp;
	GroceryNode *pMem = nullptr;
	pMem = pHead;
	temp = pMem->getItem();

	while (pMem != nullptr) //while there is still something in the lit
	{
		std::cout << temp << std::endl; //print data in that node
		pMem = pMem->getpNext(); //traverse through the list
		if (pMem != NULL) //if list is still not empty
		{
			temp = pMem->getItem(); //get more data
		}
	}
}

std::ostream &operator<<(std::ostream &lhs, std::string &rhs)
{
	lhs << rhs << std::endl;
	return lhs;
}

Grocery Grocery::createlist(int servicetime)
{
	srand(time(NULL));

	std::vector<std::string> items;
	items.push_back("bananas");
	items.push_back("soy milk");
	items.push_back("potatoes");
	items.push_back("watermelon");
	items.push_back("sugar");
	items.push_back("chocolate");
	items.push_back("tofu");
	items.push_back("coffee");
	items.push_back("splenda");
	items.push_back("bread");
	items.push_back("tortillas");
	items.push_back("tea");
	items.push_back("apples");
	items.push_back("lentils");
	items.push_back("rice");
	items.push_back("pasta");

	Grocery nodelist;

	int n = 0;
	int itemsinused = 15;

	while (servicetime != 0)
	{
		int i = 0;
		n = (rand() % itemsinused); //choose a random item

		nodelist.enqueue(items[n]);
		items[n].clear(); //delete used item from possiblities
		servicetime--;
	}

	return nodelist;
}