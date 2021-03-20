#include "CGo.h"

CGo::CGo(istream& file, int type) : CSquare(file) // Constuctor that takes in a file and type
{
	file >> *this; // Sets file line to this square
	mSquareType = type; // Sets square type
}

float CGo::GetSquareCost() // Gets square cost
{
	return 0.0f; // Returns nothing because it is not a property square
}

int CGo::GetSquareType() // Gets square type
{
	return mSquareType; // Returns square type
}

float CGo::GetSquareRent() // Gets square rent
{
	return 0.0f; // Returns nothing because it is not a property square
}

float CGo::GetBonus(int diceRoll) // Gets bonus
{
	return 0.0f; // Returns nothing because it is not a bonus square
}

float CGo::GetPenalty(int diceRoll) // Gets penalty
{
	return 0.0f; // Returns nothing because it is not a penalty square
}

int CGo::GetColourGroup() // Gets colour group
{
	return 0; // Returns nothing because it is not a property square
}

bool CGo::IsGroupOwned(int group) // gets is colour group owned
{
	return true; // Returns true it cannot be owned by player
}

istream& operator>>(istream& inputStream, CGo& properties)
{
	return inputStream;
}
