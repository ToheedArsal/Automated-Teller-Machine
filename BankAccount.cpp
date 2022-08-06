#include "BankAccount.h"

BankAccount::BankAccount()
{
	BankName = nullptr;
	Branch = nullptr;
	TotalCash = 0.0;
}

BankAccount::BankAccount(char * Bname, char * branch, float cash)
{
	BankName = copyArray(Bname);
	Branch = copyArray(branch);
	TotalCash = cash;
}

void BankAccount::setBankName(char * Bname)
{
	BankName = copyArray(Bname);
}

void BankAccount::setBranch(char * bran)
{
	Branch = copyArray(Branch);
}

void BankAccount::setTotalCash(float Cash)
{
	TotalCash = Cash;
}

char * BankAccount::getBankName() 
{
	return copyArray(BankName);
}

char * BankAccount::getBranch() 
{
	return copyArray(Branch);
}

float BankAccount::getTotalCash() const
{
	return TotalCash;
}
