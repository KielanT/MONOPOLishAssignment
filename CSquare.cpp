#include "CSquare.h"


CSquare::CSquare(istream& file) // Constuctor that reads in a file
{
	file >> *this; // Sets the file line to this square
	mIsOwned = false; // Sets is Owned to false
	mOwningPlayer = nullptr; // Sets owner player to nullptr
}

CSquare::~CSquare() // Deconstructor
{
}

string CSquare::GetSquareName() // Gets square name
{
	return mSquareName; // Returns the square name
}

void CSquare::SetIsOwned(bool isOwned, int group) // Sets is owned member variable
{
	mIsOwned = isOwned;
}

bool CSquare::GetIsOwned() // Gets is owned
{
	return mIsOwned; // Returns get owned
}

void CSquare::SetOwningPlayer(shared_ptr<CPlayer> player) // Sets Owning player
{
	mOwningPlayer = player; // Set owning player variable
}

shared_ptr<CPlayer> CSquare::GetOwningPlayer() // Gets owning player
{
	return mOwningPlayer; // Returns owning player
}

istream& operator >> (istream& inputStream, CSquare& square) // Reads in the file and sets the properties
{
	inputStream >> square.mSquareName; // Sets the square name or first part of the name if the square as multi word name
	return inputStream; // Returns file
}

ostream& operator<<(ostream& outputStream, const CSquare& square)
{
	outputStream << square.mSquareName;

	return outputStream;
}
