#include "CPenalty.h"

const char POUND = 156; // Constant with the char number for a Pound (£) symbol

CPenalty::CPenalty(istream& file, int type) : CSquare(file) // Constuctor that sets file and type
{
	file >> *this; // Sets the file line to this square
	mSquareType = type; // Sets the square type
}

float CPenalty::GetSquareCost() // Gets square cost
{
	return 0.0f; // Returns nothing because it is not a property square
}

int CPenalty::GetSquareType() // Gets square type
{
	return mSquareType; // Returns square type
}

float CPenalty::GetSquareRent() // Gets square cost
{
	return 0.0f; // Returns nothing because it is not a property square
}

float CPenalty::GetBonus(int diceRoll) // Gets the bonus
{
	return 0.0f; // Returns nothing because it is not a bonus square
}

float CPenalty::GetPenalty(int diceRoll) // Gets penalty
{
	float price = 0.0f; // Delcares price variable

	// Sets the penalty and price depending on dice roll
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


	return price; // Returns price
}

int CPenalty::GetColourGroup() // Get colour group
{
	return 0; // Returns nothing because it does not have a colour group
}

bool CPenalty::IsGroupOwned(int group) // Gets is owned
{
	return true; // Returns true because it is not a propery square
}

istream& operator>>(istream& inputStream, CPenalty& properties)
{
	return inputStream;
}
