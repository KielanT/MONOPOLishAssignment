#include "CPenalty.h"

const char POUND = 156;

CPenalty::CPenalty(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

float CPenalty::GetSquareCost()
{
	return 0.0f;
}

int CPenalty::GetSquareType()
{
	return mSquareType;
}

float CPenalty::GetSquareRent()
{
	return 0.0f;
}

float CPenalty::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CPenalty::GetPenalty(int diceRoll)
{
	float price = 0.0f;

	if (diceRoll == 1)
	{
		cout << "Buy a coffee in Starbucks.  	Lose " << POUND << "20" << endl;
		price = 20.0f;
	}
	if (diceRoll == 2)
	{
		cout << "Pay your broadband bill.  	Lose " << POUND << "50" << endl;
		price = 50.0f;
	}
	if (diceRoll == 3)
	{
		cout << "Visit the SU shop for food.  	Lose " << POUND << "100 " << endl;
		price = 100.0f;
	}
	if (diceRoll == 4)
	{
		cout << "Buy an assignment solution. 	Lose " << POUND << "150" << endl;
		price = 150.0f;
	}
	if (diceRoll == 5)
	{
		cout << "Go for a romantic meal.  	Lose " << POUND << "200" << endl;
		price = 200.0f;
	}
	if (diceRoll == 6)
	{
		cout << "Pay some university fees. 	Lose " << POUND << "300" << endl;
		price = 300.0f;
	}


	return price;
}

int CPenalty::GetColourGroup()
{
	return 0;
}

bool CPenalty::IsGroupOwned(int group)
{
	return false;
}

void CPenalty::AddOwnedList(shared_ptr<CSquare> owned)
{
}

void CPenalty::RemoveOwnedList(shared_ptr<CSquare> owned)
{
}

vector<shared_ptr<CSquare>> CPenalty::GetOwnedList()
{
	return vector<shared_ptr<CSquare>>();
}

istream& operator>>(istream& inputStream, CPenalty& properties)
{
	return inputStream;
}
