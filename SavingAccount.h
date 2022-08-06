#pragma once
#include"BankAccount.h"

class SavingAccount : public BankAccount
{
private:
	float interestRate;
public:
	SavingAccount();

	void setInterestRate(float rate);
	float getInterestRate() const;
	float Calculate_InterestRate() const;

	~SavingAccount();
};

