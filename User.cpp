#pragma once
#include "User.h"
#include<iostream>
using namespace std;
User::User()
{
	Name = nullptr;
	Address = nullptr;
	PhoneNumber = nullptr;
	C.setCardNumber(0);
	C.setPIN(0);
}

User::User(char * name, char * phnum, char * address, int pin, char * bankName,
	char * branch, float Cash, float rate, float fee, char * acctype,long long int cn)
{
	Name = copyArray(name);
	PhoneNumber = copyArray(phnum);
	Address = copyArray(address);
	acc_type = copyArray(acctype);
	C.setCardNumber(cn);
	C.setPIN(pin);
	Choose_Account(bankName, branch, Cash, rate, fee);
}

User::User( User& obj)
{
	this->Name = copyArray(obj.Name);
	this->PhoneNumber = copyArray( obj.PhoneNumber);
	this->Address = copyArray(obj.Address);
	this->acc_type = copyArray(obj.acc_type);
	this->C = obj.C;
	this->CA = obj.CA;
	this->SA = obj.SA;

	if (obj.acc_type == "S" || obj.acc_type == "s")
	{
		SA.setBranch(obj.SA.getBranch());
		SA.setBankName(obj.SA.getBankName());
		SA.setTotalCash(obj.SA.getTotalCash());
	}
	else if (obj.acc_type == "C" || obj.acc_type == "c")
	{
		CA.setBranch(obj.CA.getBranch());
		CA.setBankName(obj.CA.getBankName());
		CA.setTotalCash(obj.CA.getTotalCash());
	}
}

void User::setName(char * name)
{
	Name = copyArray(name);
}

void User::setPhoneNumber(char * PhNum)
{
	PhoneNumber = copyArray(PhNum);
}

void User::setAddress(char * address)
{
	Address = copyArray(address);
}

void User::setAcc_Type(char * acctype)
{
	acc_type = copyArray(acctype);
}

void User::Choose_Account(char * bank_name, char * branch, float total_cash, float rate, float fee)
{
	if (acc_type == "S" || acc_type == "s")
	{
		setSavingAccount(bank_name, branch, total_cash, rate);
	}
	else if (acc_type == "C" || acc_type == "c")
	{
		setCheckingAccount(bank_name, branch, total_cash, fee);
	}
}

void User::setSavingAccount(char * bank_name, char * branch, float total_cash, float rate)
{
	this->SA.setBankName(bank_name);
	this->SA.setBranch(branch);
	this->SA.setTotalCash(total_cash);
	this->SA.setInterestRate(rate);
}

void User::setCheckingAccount(char * bank_name, char * branch, float total_cash, float fee)
{
	this->CA.setBankName(bank_name);
	this->CA.setBranch(branch);
	this->CA.setTotalCash(total_cash);
	this->CA.setFee(fee);
}

void User::setTransferedMoney_S_C(User& user2, float moneyTrans, float Cash)
{
	float Cash_user2 = user2.CA.getTotalCash();

	cout << "\t" << user2.Name << " 's Cash : " << Cash_user2 << endl;

	if (moneyTrans <= Cash)
	{
		user2.CA.setTotalCash(Cash_user2 + moneyTrans);
		this->SA.setTotalCash(Cash - moneyTrans);

		cout << "\t\tAfter Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->SA.getTotalCash() << endl;
		cout << "\t" << user2.Name << " 's Cash : " << user2.CA.getTotalCash() << endl;
		cout << endl;
	}
	else
	{
		cout << "You have exceed the range of your account !!";
	}
}

void User::setTransferedMoney_C_C(User& user2, float moneyTrans, float Cash)
{
	float Cash_user2 = user2.CA.getTotalCash();

	cout << "\t" << user2.Name << " 's Cash : " << Cash_user2 << endl;

	if (moneyTrans <= Cash)
	{
		user2.CA.setTotalCash(Cash_user2 + moneyTrans);
		this->CA.setTotalCash(Cash - moneyTrans);

		cout << "\t\tAfter Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->CA.getTotalCash() << endl;
		cout << "\t" << user2.Name << " 's Cash : " << user2.CA.getTotalCash() << endl;
		cout << endl;
	}
	else
	{
		cout << "You have exceed the range of your account !!";
	}
}

void User::setTransferedMoney_S_S(User& user2, float moneyTrans, float Cash)
{
	float Cash_user2 = user2.SA.getTotalCash();

	cout << "\t" << user2.Name << " 's Cash : " << Cash_user2 << endl;

	if (moneyTrans <= Cash)
	{
		user2.SA.setTotalCash(Cash_user2 + moneyTrans);
		this->SA.setTotalCash(Cash - moneyTrans);

		cout << "\t\tAfter Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->SA.getTotalCash() << endl;
		cout << "\t" << user2.Name << " 's Cash : " << user2.SA.getTotalCash() << endl;
		cout << endl;
	}
	else
	{
		cout << "You have exceed the range of your account !!";
	}
}

void User::setTransferedMoney_C_S(User& user2, float moneyTrans, float Cash)
{
	float Cash_user2 = user2.SA.getTotalCash();

	cout << "\t" << user2.Name << " 's Cash : " << Cash_user2 << endl;

	if (moneyTrans <= Cash)
	{
		user2.SA.setTotalCash(Cash_user2 + moneyTrans);
		this->CA.setTotalCash(Cash - moneyTrans);

		cout << "\t\tAfter Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->CA.getTotalCash() << endl;
		cout << "\t" << user2.Name << " 's Cash : " << user2.SA.getTotalCash() << endl;
		cout << endl;
	}
	else
	{
		cout << "You have exceed the range of your account !!";
	}
}

char * User::getName() 
{
	return copyArray(Name);
}

char * User::getPhoneNumber() 
{
	return copyArray(PhoneNumber);
}

char * User::getAddress() 
{
	return copyArray(Address);
}

char * User::getAcc_Type()
{
	return copyArray(acc_type);
}

int User::getCardPIN()
{
	return C.getPIN();
}

long long int User::getCardNum()
{
	return C.getCardNumber();
}

float User::getBalance(char * a)
{
	float cash = 0.0;
	if (a == "S" || a == "s")
	{
		cash = SA.getTotalCash();
	}
	else if (a == "C" || a == "c")
	{
		cash = CA.getTotalCash();
	}
	return cash;
}

void User::Withdrawl(float& withdrawl_amount)
{
	int choice = 0;
	bool flag = false;

	while (1)
	{
		cout << "\tPress '1' for Fast Cash" << endl;
		cout << "\tPress '2' for Manual Withdrawl" << endl;
		cin >> choice;

		if (choice == 1)
		{
			FAST_CASH(withdrawl_amount, flag);

			if (flag == false)
			{
				break;
			}
		}
		else if (choice == 2)
		{
			cout << "\tEnter amount : ";
			cin >> withdrawl_amount;
			break;
		}
		else
		{
			cout << "\tWrong Input!!" << endl;
		}
	}
}

void User::FAST_CASH(float& withdrawl_amount, bool& flag)
{
	int choice1 = 0;
	bool flag1 = false;

	while (1)
	{
		cout << "\t\tF A S T	C A S H\n";
		cout << "\n\t1. 1000		2. 2000";
		cout << "\n\t3. 5000		4. 10000";
		cout << "\n\t0 to go Back\n" << endl;
		cin >> choice1;

		if (choice1 == 1)
		{
			withdrawl_amount = 1000;
		}
		else if (choice1 == 2)
		{
			withdrawl_amount = 2000;
		}
		else if (choice1 == 3)
		{
			withdrawl_amount = 5000;
		}
		else if (choice1 == 4)
		{
			withdrawl_amount = 10000;
		}
		else if (choice1 == 0)
		{
			flag = true;
		}
		else
		{
			cout << "\tWrong Input!!" << endl;
			flag1 = true;
		}

		if (flag1 == false)
		{
			break;
		}
	}
}

User User::operator=(User& obj)
{
	Name = copyArray(obj.Name);
	PhoneNumber = copyArray(obj.PhoneNumber);
	Address = copyArray(obj.Address);
	acc_type = copyArray(obj.acc_type);
	C = obj.C;
	CA = obj.CA;
	SA = obj.SA;

	if (obj.acc_type == "S" || obj.acc_type == "s")
	{
		SA.setBranch(obj.SA.getBranch());
		SA.setBankName(obj.SA.getBankName());
		SA.setTotalCash(obj.SA.getTotalCash());
	}
	else if (obj.acc_type == "C" || obj.acc_type == "c")
	{
		CA.setBranch(obj.CA.getBranch());
		CA.setBankName(obj.CA.getBankName());
		CA.setTotalCash(obj.CA.getTotalCash());
	}

	return *this;
}

User User::operator-()
{
	float withdrawl_amount = 0, newCash = 0;

	Withdrawl(withdrawl_amount);


	if (acc_type == "S" || acc_type == "s")
	{
		cout << "\tCash before Withdrawl : " << SA.getTotalCash() << endl;

		if (withdrawl_amount <= SA.getTotalCash())
		{
			newCash = SA.getTotalCash() - withdrawl_amount;
			SA.setTotalCash(newCash);
			cout << "\tCash after Withdrawl : " << SA.getTotalCash() << endl << endl;
		}
		else
		{
			cout << "\tYou have not enough money in your account !!!\n";
		}
	}
	else if (acc_type == "C" || acc_type == "c")
	{
		cout << "\tCash before Withdrawl : " << CA.getTotalCash() << endl;

		if (withdrawl_amount <= CA.getTotalCash())
		{
			newCash = CA.getTotalCash() - withdrawl_amount - CA.getFee();
			CA.setTotalCash(newCash);

			cout << "\tCash after Withdrawl : " << CA.getTotalCash() << endl;
			cout << "\tWith " << CA.getFee() << " fee per transaction" << endl << endl;
		}
		else
		{
			cout << "\tYou have not enough money in your account !!!\n";
		}
	}

	return *this;
}

User User::operator*()
{
	if (this->getAcc_Type() == "S" || this->getAcc_Type() == "s")
	{
		cout << "\n\tYour Current Balance is : " << this->getBalance("S") << endl << endl;
	}
	else if (this->getAcc_Type() == "C" || this->getAcc_Type() == "c")
	{
		cout << "\n\tYour Current Balance is : " << this->getBalance("C") << endl << endl;
	}

	return *this;
}

User User::operator%(User& user2)
{
	float moneyTrans = 0;
	cout << "Enter money : ";
	cin >> moneyTrans;

	if (this->acc_type == "S" || this->acc_type == "s")
	{
		float Cash = this->SA.getTotalCash();

		cout << "\n\t\tBefore Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->SA.getTotalCash() << endl;

		if (user2.acc_type == "C" || user2.acc_type == "c")
		{
			setTransferedMoney_S_C(user2, moneyTrans, Cash);
		}
		else if (user2.acc_type == "S" || user2.acc_type == "s")
		{
			setTransferedMoney_S_S(user2, moneyTrans, Cash);
		}
	}
	else if (this->acc_type == "C" || this->acc_type == "c")
	{
		float Cash = this->CA.getTotalCash();

		cout << "\t\tBefore Transfer\n";
		cout << "\t" << this->Name << " 's Cash : " << this->CA.getTotalCash() << endl;

		if (user2.acc_type == "C" || user2.acc_type == "c")
		{
			setTransferedMoney_C_C(user2, moneyTrans, Cash);
		}
		else if (user2.acc_type == "S" || user2.acc_type == "s")
		{
			setTransferedMoney_C_S(user2, moneyTrans, Cash);
		}
	}

	return *this;
}

User User::operator^(User&)
{
	int NewPin1 = 0, NewPin2;
	bool flag = false, flag1 = false;

	cout << "Enter Current PIN : ";
	cin >> NewPin1;

	if (NewPin1 == this->getCardPIN())
	{
		while (!flag1)
		{
			cout << "Enter New PIN : ";
			cin >> NewPin1;
			cout << "Confirm New PIN : ";
			cin >> NewPin2;

			if (NewPin1 == NewPin2)
			{
				this->C.setPIN(NewPin1);
				cout << "\tYour PIN got succefully Changed." << endl;
				cout << "\tYour PIN CODE is " << this->C.getPIN() << endl;
				flag1 = true;
				break;
			}
			else
			{
				cout << "\tBoth are not Same" << endl << endl;
				flag1 = false;
			}
		}
	}
	else
	{
		cout << "\tWrong Input!!" << endl;
	}

	return *this;
}

istream& operator>>(istream& input, User& obj)
{
	int user_pin = 0;
	char * type = nullptr;
	char *bankName = nullptr;
	char * branch=nullptr;
	float Cash = 0.0, rate = 0.0, fee = 0.0;


	type = new char[100];
	bankName = new char[100];
	branch = new char[100];
	obj.Name = new char[100];
	obj.PhoneNumber = new char[100];
	obj.Address = new char[100];
	cout << "Enter User Name : ";
	input.getline(obj.Name,99);
	cout << "Enter Phone Number : ";
	input.getline(obj.PhoneNumber,99);
	cout << "Enter User Address : ";
	input.getline(obj.Address,99);
	cout << "Create PIN : ";
	input >> user_pin;
	obj.C.setPIN(user_pin);
	cout << "Your Card Number Generated Succefuly\n";
	obj.C.setCardNumber(obj.getCardNum());
	cout << "Card Number : " << obj.C.getCardNumber() << endl;
	cout << "Enter Account Type : ";
	input >> type;
	obj.setAcc_Type(type);

	cout << "Enter Bank Name : ";
	input.getline(obj.Name,99);
	cout << "Enter Branch Name : ";
	input.getline(obj.PhoneNumber,99);
	cout << "Enter Total Cash : ";
	cin >> Cash;
	cout << "Enter InterestRate : ";
	cin >> rate;
	cout << "Enter fee per transaction : ";
	cin >> fee;

	obj.Choose_Account(bankName, branch, Cash, rate, fee);

	return input;
}

ostream& operator<<(ostream& output, User& obj)
{
	cout << "----------------------------------------------\n";
	output << "User Name \t\t: " << obj.Name << endl;
	output << "Phone Number \t\t: " << obj.PhoneNumber << endl;
	output << "Address \t\t: " << obj.Address << endl;
	output << "Acc Num \t\t: " << obj.C.getCardNumber() << endl;
	output << "PIN CODE \t\t: " << obj.C.getPIN() << endl;

	if (obj.acc_type == "S" || obj.acc_type == "s")
	{
		output << "Bank Name \t\t: " << obj.SA.getBankName() << endl;
		output << "Branch \t\t\t: " << obj.SA.getBranch() << endl;
		output << "Total Cash \t\t: " << obj.SA.getTotalCash() << endl;
		output << "Interest Rate \t: " << obj.SA.Calculate_InterestRate() << endl;
	}
	else if (obj.acc_type == "C" || obj.acc_type == "c")
	{
		output << "Bank Name \t\t: " << obj.CA.getBankName() << endl;
		output << "Branch \t\t\t: " << obj.CA.getBranch() << endl;
		output << "Total Cash \t\t: " << obj.CA.getTotalCash() << endl;
		output << "Fee per Transaction \t: " << obj.CA.getFee() << endl;
	}
	cout << "----------------------------------------------\n";
	return output;
}

User::~User()
{

}
