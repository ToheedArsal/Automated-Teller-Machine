#include "CheckingAccount.h"

CheckingAccount::CheckingAccount()
{
	fee_per_transaction = 0.0;
}

void CheckingAccount::setFee(float fee)
{
	fee_per_transaction = fee;
}

float CheckingAccount::getFee() const
{
	return fee_per_transaction;
}

CheckingAccount::~CheckingAccount()
{

}