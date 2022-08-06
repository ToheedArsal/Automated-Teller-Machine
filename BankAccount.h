#pragma once
#include<iostream>
using namespace std;

class BankAccount
{
protected:
	char * BankName;
	char* Branch;
	float TotalCash;
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
public:
	BankAccount();
	BankAccount(char *, char *, float);

	void setBankName(char *);
	void setBranch(char *);
	void setTotalCash(float);

	char * getBankName() ;
	char * getBranch();
	float getTotalCash() const;


};