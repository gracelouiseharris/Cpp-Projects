#include "test.h"

void Tests::emptyinsert() //inserts node into empty list
{
	data testdata;
	testdata.setCustomerNumber(10);
	testdata.setServiceTime(4);
	testdata.setTotalTime(8);
	Grocery list;

	test.enqueue(testdata, list);

	std::cout << "This test will insert a node into an empty queue:" << std::endl;

	if (test.getHead() == NULL) //if list is empty
	{
		std::cout << "Node was not saved into empty queue" << std::endl << std::endl;
	}

	else //if list is not empty
	{
		std::cout << "Node was saved into empty queue" << std::endl << std::endl;
	}
}

void Tests::oneinsert() //insert node into list with one node
{
	data testdata1;
	testdata1.setCustomerNumber(10);
	testdata1.setServiceTime(4);
	testdata1.setTotalTime(8);

	Grocery list;

	test.enqueue(testdata1, list);

	std::cout << "This test will try to insert a node into a list with one node:" << std::endl;

	if (test.getHead()->getpNext() == NULL) //if there is only one node
	{
		std::cout << "Node not successfully inserted" << std::endl << std::endl;
	}
	else //if there is more than one node
	{
		std::cout << "Second node was successfully inserted" << std::endl << std::endl;
	}
}

void Tests::onedequeue() //deletes the only node in the list
{
	test.dequeue();

	std::cout << "This test will delete the last node in the queue:" << std::endl;

	if (test.getHead() == NULL) //if list is empty
	{
		std::cout << "Node successfully deleted" << std::endl << std::endl;
	}
	else //if list is not empty
	{
		std::cout << "Node not successfully deleted" << std::endl << std::endl;
	}
}

void Tests::twodequeue() //deletes one of two nodes in the list
{
	test.dequeue();

	std::cout << "This test will delete one of two nodes in the queue:" << std::endl;

	if (test.getHead()->getpNext() == NULL) //if one node is left
	{
		std::cout << "Node successfully deleted, there is still one node in the queue" << std::endl << std::endl;
	}
	else //if two nodes are left
	{
		std::cout << "Node not deleted, two nodes remain in the queue" << std::endl << std::endl;
	}
}

void Tests::twentyfourhours() //runs program for 24 hours
{
	Queue test;

	//test.runtesttenminutes();
	test.runtestshort();
}

void Tests::runtest() //runs all tests
{
	emptyinsert();
	oneinsert();
	twodequeue();
	onedequeue();
	twentyfourhours();
}