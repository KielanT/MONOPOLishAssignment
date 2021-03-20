#include "CBonus.h"

const char POUND = 156;

CBonus::CBonus(istream& file, int type) : CSquare(file) // Constructor that takes in file and type
{
	file >> *this; // Sets file line to this square
	mSquareType = type; // Sets square type
}

float CBonus::GetSquareCost() // Gets square cost
{
	return 0.0f; // Returns nothing because it is not a property square
}

int CBonus::GetSquareType() // Gets square type
{
	return mSquareType; // Returns square type
}

float CBonus::GetSquareRent() // Gets square rent
{
	return 0.0f; // Returns nothing because it is not a property square
}

float CBonus::GetBonus(int diceRoll) // Gets the bonus
{
	float price = 0.0f; // Declares prices
	
	// Sets penalty and penalty price depending on dice roll
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
	
	
	return price; // Retruns price
	
}

float CBonus::GetPenalty(int diceRoll) // Get penalty
{
	return 0.0f; // Returns nothing because it is not a penalty square
}

int CBonus::GetColourGroup() // Gets colour group
{
	return 0; // Returns nothing because it is not a property square
}

bool CBonus::IsGroupOwned(int group) // Gets is grouped owned
{
	return true; // Returns truth because square cannot be owned by a player
}

istream& operator>>(istream& inputStream, CBonus& properties)
{
	return inputStream;
}
