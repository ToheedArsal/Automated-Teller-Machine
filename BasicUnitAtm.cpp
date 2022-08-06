#include "BasicUnitATM.h"

BasicUnitAtm::BasicUnitAtm(User* user,int SIZE)
{
	int choice = 0, loc = 0;
	int flag = 0;

	cout << "\tWlecome to " << " A T M" << endl;
	user[loc] = TakeInputs(user, loc,SIZE);

	while (1)
	{
		Menu();
		cin >> choice;

		if (choice == 1)
		{
			flag = 0;

			-user[loc];

			SubMenu(flag);

			if (flag == 2)
			{
				cout << "\tThanks For Using Our ATM Service" << endl;
				break;
			}
		}
		else if (choice == 2)
		{
			cout << user[loc] << endl;
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			cout << "Wrong Input!!!";
		}
	}

}

void BasicUnitAtm::Menu()
{
	cout << "Press '1' to withdrawal" << endl;
	cout << "Press '2' to display information" << endl;
	cout << "Press '0' to exit" << endl;
}

void BasicUnitAtm::SubMenu(int& flag)
{
	char decide = '\0';

	while (flag == 0)
	{
		cout << "\tPress 'c' if u want to conitnue your transaction" << endl;
		cout << "\tPress 'e' if u want to end your transaction" << endl;
		cin >> decide;

		if (decide == 'c')
		{
			flag = 1;
			break;
		}
		else if (decide == 'e')
		{
			flag = 2;
		}
		else
		{
			cout << "\tWrong Input!!";
			flag = 0;
		}
	}
}

BasicUnitAtm::~BasicUnitAtm()
{

}