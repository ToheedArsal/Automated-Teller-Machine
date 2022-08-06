#include "ATM.h"

ATM::ATM()
{

}

ATM::ATM(User* user)
{

}

bool ATM::Validate(User& SavedUser, int PIN, long long int CardNum)
{
	bool flag = false;
	if (SavedUser.getCardNum() == CardNum)
	{
		flag = true;
		if (SavedUser.getCardPIN() == PIN)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}

	return flag;
}

User ATM::TakeInputs(User* SavedUser, int& loc, int SIZE)
{
	int Input_PIN = 0;
	long long int Input_AccNum = 0;
	bool flag = false, flag1 = false;

	while (!flag)
	{
		cout << "Enter Acc Num : ";
		cin >> Input_AccNum;

		for (int i = 0; i < SIZE; i++)
		{
			if (SavedUser[i].getCardNum() == Input_AccNum)
			{
				loc = i;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			while (!flag1)
			{
				cout << "Enter PIN : ";
				cin >> Input_PIN;

				if (SavedUser[loc].getCardPIN() == Input_PIN)
				{
					flag1 = true;
				}
				else
				{
					flag1 = false;
					cout << "\tWrong Pin Number!!" << endl;
				}
			}

			if (flag1)
			{
				cout << "\tWelcome( " << SavedUser[loc].getName() << " )" << endl << endl;
			}
		}
		else
		{
			cout << "\tAccount Number did not Found" << endl;
		}
	}

	return SavedUser[loc];
}