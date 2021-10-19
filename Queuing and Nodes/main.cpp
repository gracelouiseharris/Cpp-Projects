#include "test.h"

int main(void)
{
	Queue a;
	Tests b;
	int select = 0;

	while (select != 3) //while exit is not selected
	{
		std::cout << "Line Simulator Menu" << std::endl << std::endl;
		std::cout << "(1) Run Tests" << std::endl;
		std::cout << "(2) Run Simulator" << std::endl;
		std::cout << "(3) Exit" << std::endl;

		std::cin >> select;

		if (select == 1) //while run tests is selected
		{
			b.runtest();
			system("pause");
			system("cls");
		}

		if (select == 2) //while run simulator is selected
		{
			a.run();
			system("pause");
			system("cls");
		}
	}

	return 0;
}