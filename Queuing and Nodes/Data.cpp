#include "Data.h"

void data::setCustomerNumber(int newNumber)
{
	customerNumber = newNumber;
}

void data::setServiceTime(int newTime)
{
	serviceTime = newTime;
}

void data::setTotalTime(int newTotal)
{
	totalTime = newTotal;
}

int data::getCustomerNumber()
{
	return customerNumber;
}

int data::getServiceTime()
{
	return serviceTime;
}

int data::getTotalTime()
{
	return totalTime;
}