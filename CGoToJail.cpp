#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file, int type) : CSquare(file) // Contsructor that takes in a file and a type
{
	file >> *this; // Sets file line to this square
	mSquareType = type; // Sets square type
}

string CGoToJail::GetSquareName() // Gets Name
{
	string name = mSquareName + " " + mTo + " " + mJail; // Joins the name together
	return name; // Returns name
}

float CGoToJail::GetSquareCost() // Sets the square cost
{
	return 0.0f; // Returns nothing because it is not a property 
}

int CGoToJail::GetSquareType() // Gets the square type
{
	return mSquareType; // Returns the square type
}

float CGoToJail::GetSquareRent() // Gets square rent
{
	return 0.0f; // Returns nothing because it is not a property 
}

float CGoToJail::GetBonus(int diceRoll) // Gets Bonus
{
	return 0.0f; // Returns nothing because it is not a bouns square 
}

float CGoToJail::GetPenalty(int diceRoll) // Gets Penalty
{
	return 0.0f; // Returns nothing because it is not a penalty square 
}

int CGoToJail::GetColourGroup() // Gets colour group
{
	return 0; // Returns nothing because it is not a property 
}

bool CGoToJail::IsGroupOwned(int group) // Get is owned
{
	return true; // Returns true because it cannot be owned by a player
}

istream& operator>>(istream& inputStream, CGoToJail& properties) // Sets the properties
{
	inputStream >> properties.mTo; // Sets second part of the squares Name
	inputStream >> properties.mJail; // Sets third part of the squares Name
	return inputStream;
}
