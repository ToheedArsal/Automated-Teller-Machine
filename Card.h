#pragma once
class Card
{
private:
	long long int CardNumber;
	int PIN;
public:
	Card();
	Card(long long int, int);

	void setPIN(int);
	void setCardNumber(long long int );

	int getPIN() const;
	long long int getCardNumber() const;

	long long int NumberGenerator();

	~Card();
};