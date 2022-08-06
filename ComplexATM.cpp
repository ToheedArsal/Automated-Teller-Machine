#include "ComplexATM.h"


ComplexATM::ComplexATM(User* user, int SIZE)
{
	int choice = 0, loc = 0, loc2 = 0;

	cout << "\tWlecome to " << " A T M" << endl;
	user[loc] = TakeInputs(user, loc, SIZE);

	while (1)
	{
		Menu();
		cin >> choice;

		if (choice == 1) // Withrawl
		{
			-user[loc];
		}
		else if (choice == 2) // Balance Inquiry
		{
			*user[loc];
		}
		else if (choice == 3) // Transfer Money
		{
			long long int AccNum_Trans = 0;
			bool flag = false;
			int flag1 = 0;

			cout << "\tEnter Acc Num to which u want to transfer money\n";
			cout << "\tEnter Acc Num : ";
			cin >> AccNum_Trans;

			for (int i = 0; i < SIZE; i++)
			{
				if (i != loc)
				{
					if (user[i].getCardNum() == AccNum_Trans)
					{
						loc2 = i;
						flag = true;
						break;
					}
					else
					{
						flag = false;
					}
				}
			}


			if (AccNum_Trans == user[loc].getCardNum())
			{
				cout << "\n\tYou Have Entered Your Own Acc Number\n\n";
			}
			else
			{
				if (flag == true)
				{
					user[loc] % user[loc2];
				}
				else
				{
					cout << "\tDoes Not Found Match from the records!!" << endl;
					cout << "\tT R A N S A C T I O N	F A I L E D !!" << endl;
				}
			}
		}
		else if (choice == 4) // CHange you PIN
		{
			User temp2;
			user[loc] ^ temp2;
		}
		else if (choice == 5)
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

void ComplexATM::Menu()
{
	cout << "Press '1' to withdrawl" << endl;
	cout << "Press '2' for balance inquiry" << endl;
	cout << "Press '3' to transfer money" << endl;
	cout << "Press '4' to change your PIN" << endl;
	cout << "Press '5' to display information" << endl;
	cout << "Press '0' to exit" << endl;
}

ComplexATM::~ComplexATM()
{

}
