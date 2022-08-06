#pragma once
#include"ATM.h"

class BasicUnitAtm : public ATM
{
public:
	BasicUnitAtm(User*,int);

	void Menu();
	void SubMenu(int&);

	~BasicUnitAtm();
};