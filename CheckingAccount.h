#pragma once
#include"BankAccount.h"

class CheckingAccount : public BankAccount
{
private:
	float fee_per_transaction;
public:
	CheckingAccount();

	void setFee(float);
	float getFee() const;

	~CheckingAccount();
};