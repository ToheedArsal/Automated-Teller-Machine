#pragma once
#include"ATM.h"

class ComplexATM : public ATM
{
public:
	ComplexATM(User*, int);
	void Menu();

	~ComplexATM();
};

