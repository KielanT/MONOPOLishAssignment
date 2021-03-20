#include "CStations.h"

CStations::CStations(istream& file, int type) : CSquare(file) // Constructor that reads a file and the square type
{
	file >> *this; // Sets the file line to this square
	mSquareType = type; // Sets the square type
}

string CStations::GetSquareName() // Gets the Square Name
{
	string name = mSquareName + " " + mSquareStation; // Joins the names read in from the file
	return name; // Returns the name
}

float CStations::GetSquareCost() // Gets the square cost
{
	return 0.0f; // Returns nothing because it isn't a property square
}

int CStations::GetSquareType() // Gets the square type
{
	return mSquareType; // Returns Square Type
}

float CStations::GetSquareRent() // Gets the square rent
{
	return 0.0f; // Returns nothing because it doesn't have rent cost
}

float CStations::GetBonus(int diceRoll) // Returns Get Bonus
{
	return 0.0f; // Returns nothing because it is not a bonus square
}

float CStations::GetPenalty(int diceRoll) // Returns Get Penalty
{ 
	return 0.0f; // Returns nothing because it is not a Penalty square
}

int CStations::GetColourGroup() // Returns the colour group
{
	return 0; // Returns nothing because it is not apart of a colour group
}

bool CStations::IsGroupOwned(int group) // Gets is group owned
{
	return true; // Returns true because it is not a property square
}

istream& operator>>(istream& inputStream, CStations& properties) // Reads in from the file then sets the properties 
{
	inputStream >> properties.mSquareStation; // Reads in the name of the station and sets the member variable

	return inputStream; // Returns the file
}
