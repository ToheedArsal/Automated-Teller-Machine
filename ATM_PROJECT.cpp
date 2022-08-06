#pragma once
#include<iostream>
using namespace std;

#include"User.h"
#include"BasicUnitAtm.h"
#include"ComplexATM.h"

int main()
{
	// Creating Hard Coded Users

	const int SIZE = 2;

	User U[SIZE] = { {"M Ali","0305 4239003","Gujranwala",6657,"HBL","Sattelite Town Branch",100000,2.5,20,"S",123},

		{"Khuzama", "0316 4511593", "Lahore", 1122,"HBL","Johar Town Branch",500000,2.5,20,"C",234} };

	int choice = 0;
	bool flag = false;

	cout << "  Welcome To Automated Teller Machine(ATM)" << endl;
	cout << "\tIn which ATM you swant to log in!" << endl;

	while (!flag)
	{
		cout << "1. Basic Unit ATM		2. Complex ATM" << endl;
		cin >> choice;

		if (choice == 1)
		{
			BasicUnitAtm A(U, SIZE);
			flag = true;
		}
		else if (choice == 2)
		{
			ComplexATM C(U, SIZE);
			flag = true;
		}
		else
		{
			system("cls");
			cout << "\tWrong Input!!" << endl;
		}
	}

	return 0;
}