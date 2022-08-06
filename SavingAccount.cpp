#include "SavingAccount.h"

SavingAccount::SavingAccount()
{
	interestRate = 0.0;
}

void SavingAccount::setInterestRate(float rate)
{
	interestRate = rate;
}

float SavingAccount::getInterestRate() const
{
	return interestRate;
}

float SavingAccount::Calculate_InterestRate() const
{
	float rate = 0.0;
	// Interest (per week) = Totalbalance * Rate of interest * (No.of days / 365)
	rate = this->getTotalCash() * interestRate * (7 / 365);
	return rate;
}

SavingAccount::~SavingAccount()
{

}