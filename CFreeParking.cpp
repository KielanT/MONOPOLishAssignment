#include "CFreeParking.h"

CFreeParking::CFreeParking(istream& file, int type) : CSquare(file) // Constructor that takes in a file and type
{
	file >> *this; // Sets file line to this square
	mSquareType = type; // Sets square type
}

string CFreeParking::GetSquareName() // Gets the square name
{
	string name = mSquareName + " " + mSquareParking; // Joins square name
	return name; // Returns name
}

float CFreeParking::GetSquareCost() // Gets the square cost
{
	return 0.0f; // Returns nothing because it is not a property square
}

int CFreeParking::GetSquareType() // Gets the square type
{
	return mSquareType; // Returns the square type
}

float CFreeParking::GetSquareRent() // Gets the squares rent
{
	return 0.0f; // Returns nothing because it is not a property square
}

float CFreeParking::GetBonus(int diceRoll) // Gets bonus
{
	return 0.0f; // Returns nothing because it is not a bouns square
}

float CFreeParking::GetPenalty(int diceRoll) // Gets Penalty
{
	return 0.0f; // Returns nothing because it is not a Penalty square
}

int CFreeParking::GetColourGroup() // Gets square group
{
	return 0; // Returns nothing because it is not a property square
}

bool CFreeParking::IsGroupOwned(int group) // IsGroupOwned
{
	return true; // Returns true cannot be owned by player 
}

istream& operator>>(istream& inputStream, CFreeParking& properties) // Sets properties from file
{
	inputStream >> properties.mSquareParking; // Sets second part of the name
	return inputStream;
}
