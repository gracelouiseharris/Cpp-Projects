#include "queue.h"

Queue::Queue() // constructor
{
	pHead = NULL; //set pHead and pTail to NULL aka initalize new queue
	pTail = NULL;
}

Queue::Queue(Queue &copy)
{
	pHead = copy.getHead();
	pTail = copy.getTail();
}

Queue::~Queue() // deconstructor
{

}

void Queue::setHead(QueueNode *newHead) //set pHead
{
	this->pHead = newHead;
}

void Queue::setTail(QueueNode *newTail) //set pTail
{
	this->pTail = newTail;
}

QueueNode* Queue::getHead() //return pHead for use in nonmember functions
{
	return pHead;
}

QueueNode* Queue::getTail() //return pTail for use in nonmember functions
{
	return pTail;
}

void Queue::enqueue(data newData, Grocery newList)
{
	QueueNode *pMem = nullptr;
	pMem = new QueueNode(newData, newList);

	if (pMem != nullptr)
	{
		if (this->pHead == nullptr) // if queue is empty
		{
			this->setHead(pMem);
			this->setTail(pMem);
		}
		else //if queue is not empty, insert at the end
		{
			this->pTail->setpNext(pMem);
			this->setTail(pMem);
		}
	}
}

data Queue::dequeue()
{
	data temp;
	QueueNode *pTemp = nullptr;

	pTemp = this->pHead;
	temp = pTemp->getData();

	if (this->pHead == this->pTail) // if there is only one node in the list
	{
		this->pHead = this->pTail = nullptr;
	}
	else //if there is more than one node in the list
	{
		this->setHead(this->pHead->getpNext());
	}

	delete pTemp; //delete current node

	return temp; //return data in the deleted node
}

void Queue::printQueue()
{
	data temp;
	Grocery tempgro;
	QueueNode *pMem = nullptr;
	pMem = pHead;
	temp = pMem->getData();
	tempgro = pMem->getGrocery();

	while (pMem != nullptr) //while there is still something in the lit
	{
		std::cout << temp << std::endl; //print data in that node
		pMem = pMem->getpNext(); //traverse through the list
		if (pMem != nullptr) //if list is still not empty
		{
			temp = pMem->getData(); //get more data
		}
	}
}

int Queue::isEmpty()
{
	int n = 0;

	if (this->pHead == nullptr)
	{
		n = 1;
	}

	return n;
}

std::ostream &operator<<(std::ostream &lhs, data &rhs)
{
	lhs << "Customer Number: " << rhs.getCustomerNumber() << std::endl
		<< "Service Time: " << rhs.getServiceTime() << std::endl
		<< "Total Time: " << rhs.getTotalTime() << std::endl;
	return lhs;
}

void Queue::run()
{
	srand(time(NULL));   // uses clock to generate random numberss

	int length = 0, time = 0, normalarrival = 0, expressarrival = 0, timemultiply = 0;
	int expressfirst = 0, normalfirst = 0;
	int	normalnumber = 1, expressnumber = 1;
	int normalservice = 0, expressservice = 0;
	int normaltotal = 0, expresstotal = 0;
	Queue normalQueue;
	Queue expressQueue;
	data normalcustomer;
	data expresscustomer;
	int expresstimestart = 0;
	int normaltimestart = 0;
	Grocery express;
	Grocery normal;
	std::vector<int> expressdequeue;
	std::vector<int> normaldequeue;
	int ex = 0;
	int no = 0;

	std::cout << "How many minutes do you want to run your simulation? " << std::endl;
	std::cin >> length;
	std::cout << "At what multiply speed would you like to simulate your queue? (enter 2 for 30 sec = 1 minute, 8 for 7.5 sec = 1 min etc)" << std::endl;
	std::cin >> timemultiply;

	double sleepprint = 60 / timemultiply;
	int sleep = (int)(60000 / timemultiply);

	do
	{
		if (expressfirst == 0) //do for the first customer in the express line
		{
			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			express.createlist(expressservice);

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			expresscustomer.setTotalTime(expressservice); //for first customer, total time = service time

			expressnumber += 1; //increment customer number
			expressfirst = 1;
		}

		if (normalfirst == 0) //do for the first customer in the normal line
		{
			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normal.createlist(normalservice);

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			normalcustomer.setTotalTime(normalservice); //for first customer, total time = service time

			normalnumber += 1;
			normalfirst = 1;
		}

		if (expressarrival == 0) //customer's wait time is over, add them to the queue and generate new customer
		{
			expressQueue.enqueue(expresscustomer, express); //add customer that has been waiting to the queue
			expressdequeue.push_back(expressservice); //put service time of customer into vector

			expresstimestart = 1; //start to count down total time

			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			if (expresstotal >= 0) //if line is not empty then total time is service time + time for everyone else ahead
				expresstotal += expressservice;
			else //if line is empty then total time is just the service time
				expresstotal = expressservice;

			expresscustomer.setTotalTime(expresstotal); //set customer total time
			
			expressnumber += 1; //increment customer number
		}

		if (normalarrival == 0) //if new customer has arrived, generate the next customer
		{
			normalQueue.enqueue(normalcustomer, normal); //add customer to the Queue
			normaldequeue.push_back(normalservice); //put service time of customer into vector

			normaltimestart = 1; //start to count down normal time

			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			if (normaltotal >= 0)
				normaltotal += normalservice; //calculate total time
			else
				normaltotal = normalservice;
			
			normalcustomer.setTotalTime(normaltotal); //set total time

			normalnumber += 1;
		}

		if (time == 10)
		{
			std::cout << "Time is being simulated at 1 minute = " << sleepprint << " seconds." << std::endl;
		}

		if ((time % 10) == 0 && time != 0)
		{
			std::cout << "Minutes:" << time << std::endl << std::endl;
			std::cout << "Normal Lane:" << std::endl << std::endl;
			normalQueue.printQueue();
		}

		if ((time % 10) == 0 && time != 0)
		{
			std::cout << "Express Lane:" << std::endl << std::endl;
			expressQueue.printQueue();
		}
		//The commented code below will dequeue customers as they are finished in line, but the assignment says to print the entire queue every ten minutes so I
		//commented this out. It works if you wanna try it though
	/*	int expressde = 0;
		int normalde = 0;

		if (expresstimestart == 1)
		{
			if (expressdequeue[ex] <= 0)
			{
				expressde = 1;
				ex++;
			}
			else expressdequeue[ex]--;
		}

		if (normaltimestart == 1)
		{

				if (normaldequeue[no] <= 0)
				{
					normalde = 1;
					no++;
				}
				else normaldequeue[no]--;
		}

		if (expressde == 1)
		{
			expresscustomer = expressQueue.dequeue();
		}

		if (normalde == 1)
		{
			normalcustomer = expressQueue.dequeue();
		}*/

		Sleep(sleep); //delays for time specified by user
		time++; //increments time in minutes
		if (expresstimestart == 1)
		expresstotal--; //decrement total waiting time in express line
		if (normaltimestart == 1)
		normaltotal--; //decrement total waiting time in normal line
		expressarrival--; //decrement arrival time for express lane
		normalarrival--; //decrement arrival time for normal lane

	} while (time <= length);
}


void Queue::runtesttenminutes()
{
	srand(time(NULL));   // uses clock to generate random numberss

	int length = 1440, time = 0, normalarrival = 0, expressarrival = 0;
	int expressfirst = 0, normalfirst = 0;
	int	normalnumber = 1, expressnumber = 1;
	int normalservice = 0, expressservice = 0;
	int normaltotal = 0, expresstotal = 0;
	Queue normalQueue;
	Queue expressQueue;
	data normalcustomer;
	data expresscustomer;
	int expresstimestart = 0;
	int normaltimestart = 0;
	Grocery express;
	Grocery normal;

	do
	{
		if (expressfirst == 0) //do for the first customer in the express line
		{
			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			express.createlist(expressservice);

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			expresscustomer.setTotalTime(expressservice); //for first customer, total time = service time

			expressnumber += 1; //increment customer number
			expressfirst = 1;
		}

		if (normalfirst == 0) //do for the first customer in the normal line
		{
			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normal.createlist(normalservice);

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			normalcustomer.setTotalTime(normalservice); //for first customer, total time = service time

			normalnumber += 1;
			normalfirst = 1;
		}

		if (expressarrival == 0) //customer's wait time is over, add them to the queue and generate new customer
		{
			expressQueue.enqueue(expresscustomer, express); //add customer that has been waiting to the queue

			expresstimestart = 1; //start to count down total time

			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			if (expresstotal >= 0) //if line is not empty then total time is service time + time for everyone else ahead
				expresstotal += expressservice;
			else //if line is empty then total time is just the service time
				expresstotal = expressservice;

			expresscustomer.setTotalTime(expresstotal); //set customer total time

			expressnumber += 1; //increment customer number
		}

		if (normalarrival == 0) //if new customer has arrived, generate the next customer
		{
			normalQueue.enqueue(normalcustomer, normal); //add customer to the Queue

			normaltimestart = 1; //start to count down normal time

			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			if (normaltotal >= 0)
				normaltotal += normalservice; //calculate total time
			else
				normaltotal = normalservice;

			normalcustomer.setTotalTime(normaltotal); //set total time

			normalnumber += 1;
		}

		if ((time % 10) == 0 && time != 0)
		{
			std::cout << "Minutes:" << time << std::endl << std::endl;
			std::cout << "Normal Lane:" << std::endl << std::endl;
			normalQueue.printQueue();
		}

		if ((time % 10) == 0 && time != 0)
		{
			std::cout << "Express Lane:" << std::endl << std::endl;
			expressQueue.printQueue();
		}

		time++; //increments time in minutes
		if (expresstimestart == 1)
			expresstotal--; //decrement total waiting time in express line
		if (normaltimestart == 1)
			normaltotal--; //decrement total waiting time in normal line
		expressarrival--; //decrement arrival time for express lane
		normalarrival--; //decrement arrival time for normal lane

	} while (time <= length);
}

void Queue::runtestshort()
{
	srand(time(NULL));   // uses clock to generate random numberss

	int length = 1440, time = 0, normalarrival = 0, expressarrival = 0;
	int expressfirst = 0, normalfirst = 0;
	int	normalnumber = 1, expressnumber = 1;
	int normalservice = 0, expressservice = 0;
	int normaltotal = 0, expresstotal = 0;
	Queue normalQueue;
	Queue expressQueue;
	data normalcustomer;
	data expresscustomer;
	int expresstimestart = 0;
	int normaltimestart = 0;
	Grocery express;
	Grocery normal;

	do
	{
		if (expressfirst == 0) //do for the first customer in the express line
		{
			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			express.createlist(expressservice);

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			expresscustomer.setTotalTime(expressservice); //for first customer, total time = service time

			expressnumber += 1; //increment customer number
			expressfirst = 1;
		}

		if (normalfirst == 0) //do for the first customer in the normal line
		{
			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normal.createlist(normalservice);

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			normalcustomer.setTotalTime(normalservice); //for first customer, total time = service time

			normalnumber += 1;
			normalfirst = 1;
		}

		if (expressarrival == 0) //customer's wait time is over, add them to the queue and generate new customer
		{
			expressQueue.enqueue(expresscustomer, express); //add customer that has been waiting to the queue

			expresstimestart = 1; //start to count down total time

			expressarrival = (rand() % 5) + 1; //generate random arrival for express lane
			expressservice = (rand() % 5) + 1; //generate random service time for express lane

			expresscustomer.setCustomerNumber(expressnumber); //set customer number
			expresscustomer.setServiceTime(expressservice); //set service time

			if (expresstotal >= 0) //if line is not empty then total time is service time + time for everyone else ahead
				expresstotal += expressservice;
			else //if line is empty then total time is just the service time
				expresstotal = expressservice;

			expresscustomer.setTotalTime(expresstotal); //set customer total time

			expressnumber += 1; //increment customer number
		}

		if (normalarrival == 0) //if new customer has arrived, generate the next customer
		{
			normalQueue.enqueue(normalcustomer, normal); //add customer to the Queue

			normaltimestart = 1; //start to count down normal time

			normalarrival = (rand() % 5) + 3; //generate random arrival for normal lane
			normalservice = (rand() % 5) + 3; //generate random arrival for customer lane

			normalcustomer.setCustomerNumber(normalnumber); //set customer number
			normalcustomer.setServiceTime(normalservice); //set service time

			if (normaltotal >= 0)
				normaltotal += normalservice; //calculate total time
			else
				normaltotal = normalservice;

			normalcustomer.setTotalTime(normaltotal); //set total time

			normalnumber += 1;
		}

		if (time >= 1440)
		{
			std::cout << "Minutes:" << time << std::endl << std::endl;
			std::cout << "Normal Lane:" << std::endl << std::endl;
			normalQueue.printQueue();

			std::cout << "Express Lane:" << std::endl << std::endl;
			expressQueue.printQueue();
		}

		time++; //increments time in minutes
		if (expresstimestart == 1)
			expresstotal--; //decrement total waiting time in express line
		if (normaltimestart == 1)
			normaltotal--; //decrement total waiting time in normal line
		expressarrival--; //decrement arrival time for express lane
		normalarrival--; //decrement arrival time for normal lane

	} while (time <= length);
}
