#include "Card.h"
#include<iostream>
#include<ctime>
using namespace std;

Card::Card()
{
	PIN = 0;
	CardNumber = 0;
}


Card::Card(long long int CA, int pin)
{
	CardNumber = CA;
	PIN = pin;
}

void Card::setPIN(int pin)
{
	PIN = pin;
}

void Card::setCardNumber(long long int cn)
{
	CardNumber = cn;
}

int Card::getPIN() const
{
	return PIN;
}

long long int Card::getCardNumber() const
{
	return CardNumber;
}

long long int Card::NumberGenerator()
{
	long long int randnum = (rand() % 2147483645) + 4200011111;
	return randnum;
}

Card::~Card()
{

}
