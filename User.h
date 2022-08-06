#pragma once
#include<iostream>
#include<ctime>
using namespace std;

#include"Card.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"

class User
{
private:
	char * Name;
	char * PhoneNumber;
	char * Address;
	char * acc_type;
	Card C;
	SavingAccount SA;
	CheckingAccount CA;
public:
	// C O N S T R U C T O R S
	User();
	User(char *, char *, char *, int, char *, char *, float, float, float, char *,long long int );
	User(User&);

	// S E T T E R S
	void setName(char *);
	void setPhoneNumber(char *);
	void setAddress(char *);
	void setAcc_Type(char *);

	void setSavingAccount(char *, char *, float, float);
	void setCheckingAccount(char *, char *, float, float);

	void setTransferedMoney_S_C(User&, float, float);
	void setTransferedMoney_C_C(User&, float, float);
	void setTransferedMoney_S_S(User&, float, float);
	void setTransferedMoney_C_S(User&, float, float);

	// G E T T E R S
	char * getName() ;
	char * getPhoneNumber() ;
	char * getAddress() ;
	char * getAcc_Type() ;

	// M E M B E R	F U N C T I O N S
	int getCardPIN();
	long long int getCardNum();
	float getBalance(char *);
	void Withdrawl(float&);
	void FAST_CASH(float&, bool&);
	void Choose_Account(char *, char *, float, float, float);

	// O P E R A T O R	O V E R L O A D I N G
	User operator=( User&);
	User operator-();
	User operator*();
	User operator%(User&);
	User operator^(User&);
	char * copyArray(const char * arr)
	{
		int size = 0;
		while (arr[size] != '\0')
		{
			size++;
		}
		char * tm = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			tm[i] = arr[i];
		}
		tm[size] = '\0';
		return tm;
	}
	friend istream& operator>>(istream&, User&);
	friend ostream& operator<<(ostream&,  User&);

	~User();
};