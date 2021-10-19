
#include <iostream>
#include <string>
#include <vector>

class data
{
public:

	void setCustomerNumber(int newNumber);
	void setServiceTime(int newTime);
	void setTotalTime(int newTotal);

	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
};