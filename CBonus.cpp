#include "CBonus.h"

const char POUND = 156;

CBonus::CBonus(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

float CBonus::GetSquareCost()
{
	return 0.0f;
}

int CBonus::GetSquareType()
{

	return mSquareType;
}

float CBonus::GetSquareRent()
{
	return 0.0f;
}

float CBonus::GetBonus(int diceRoll)
{
	
	float price = 0.0f;
	
	if (diceRoll == 1)
	{
		cout << "Find some money.  	Gain " << POUND << "20" << endl;
		price = 20.0f;
	}
	if (diceRoll == 2)
	{
		cout << "Win a coding competition. 	Gain " << POUND << "50" << endl;
		price = 50.0f;
	}
	if (diceRoll == 3)
	{
		cout << "Receive a rent rebate.  	Gain " << POUND << "100 " << endl;
		price = 100.0f;
	}
	if (diceRoll == 4)
	{
		cout << "Win the lottery.  	Gain " << POUND << "150" << endl;
		price = 150.0f;
	}
	if (diceRoll == 5)
	{
		cout << "Receive a bequest.  	Gain " << char(156) << "200" << endl;
		price = 200.0f;
	}
	if (diceRoll == 6)
	{
		cout << "It’s your birthday.  	Gain " << char(156) << "300" << endl;
		price = 300.0f;
	}
	
	
	return price;
	
}

float CBonus::GetPenalty(int diceRoll)
{
	return 0.0f;
}

istream& operator>>(istream& inputStream, CBonus& properties)
{
	return inputStream;
}
