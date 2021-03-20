#include "CJail.h"

CJail::CJail(istream& file, int type) : CSquare(file) // Constructor sets file and type
{
	file >> *this; // Sets the file line to this square
	mSquareType = type; // Sets the square type
}

float CJail::GetSquareCost() // Gets square costs 
{
	return 0.0f; // Returns nothing because it is not a property
}

int CJail::GetSquareType() // Gets square type 
{
	return mSquareType; // Returns square type
}

float CJail::GetSquareRent() // Gets square Rent 
{
	return 0.0f; // Returns nothing because it is not a property
}

float CJail::GetBonus(int diceRoll) // Gets square Bonus 
{
	return 0.0f; // Returns nothing because it is not a bonus square
}

float CJail::GetPenalty(int diceRoll) // Gets square penalty 
{
	return 0.0f; // Returns nothing because it is not a penalty square
}

int CJail::GetColourGroup() // Gets square colour group 
{
	return 0;  // Returns nothing because it is not a property
}

bool CJail::IsGroupOwned(int group) // Gets is group owned
{
	return true; // Returns is true because it is not a group
}

istream& operator>>(istream& inputStream, CJail& properties)
{
	return inputStream;
}
