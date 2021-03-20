#include "CProperties.h"

CProperties::CProperties(istream& file, int type) : CSquare(file) // Constuctor that sets file and type
{
	file >> *this; // Sets the file line to this square
	mSquareType = type; // Sets the type

	// Initialises the colour groups
	mRedGroup = 0;
	mGreyGroup = 0;
	mBrownGroup = 0;
	mOrangeGroup = 0;
	mYellowGroup = 0;
	mGreenGroup = 0;
	mBlueGroup = 0;
	mPurpleGroup = 0;
}

string CProperties::GetSquareName() // Gets Square Name
{
	string name = mSquareName + " " + mSquareStreetName; // Joins the two names
	return name; // Returns the name
}

float CProperties::GetSquareCost() // Gets the square cost
{
	return mSquareCost; // Returns the square cost
}

int CProperties::GetSquareType() // Get the square type
{
	return mSquareType; // Returns the square type
}

float CProperties::GetSquareRent() // Gets the squares rent
{
	return mSquareRent; // Returns the squares rent
}

float CProperties::GetBonus(int diceRoll) // Gets bonus
{
	return 0.0f; // Returns nothing because this square is not a bonus square
}

float CProperties::GetPenalty(int diceRoll) // Gets penalty
{
	return 0.0f; // Returns nothing because this square is not a penalty square
}

int CProperties::GetColourGroup() // Gets colour Group
{
	return mSquareGroup; // Returns colour group
}

void CProperties::SetIsOwned(bool isOwned, int group) // Set is Owned 
{
	// Increments square colour group depening on the group type
	if (group == 0)
	{
		mRedGroup++;
	}
	else if (group == 1)
	{
		mGreyGroup++;
	}
	else if (group == 2)
	{
		mBrownGroup++;
	}
	else if (group == 3)
	{
		mOrangeGroup++;
	}
	else if (group == 4)
	{
		mYellowGroup++;
	}
	else if (group == 5)
	{
		mGreenGroup++;
	}
	else if (group == 6)
	{
		mBlueGroup++;
	}
	else if (group == 7)
	{
		mBlueGroup++;
	}

	mIsOwned = isOwned; // Sets is owned
}

bool CProperties::GetIsOwned() // Gets is owned
{ 
	return mIsOwned; // Returns is owned
}

void CProperties::SetOwningPlayer(shared_ptr<CPlayer> Player) // Sets owner
{
	mOwningPlayer = Player; // Sets owning variable
}

shared_ptr<CPlayer> CProperties::GetOwningPlayer() // Gets owning player
{
	return mOwningPlayer; // Returns owning player
}

bool CProperties::IsGroupOwned(int group) // Checks if the group is owned
{
	// Returns true if all squares in a group is owned 

	if (mRedGroup >= 2)
	{
		return true;
	}
	else if (mGreyGroup >= 2)
	{
		return true;
	}
	else if (mBrownGroup >= 2)
	{
		return true;
	}
	else if (mOrangeGroup >= 3)
	{
		return true;
	}
	else if (mYellowGroup >= 2)
	{
		return true;
	}
	else if (mGreenGroup >= 2)
	{
		return true;
	}
	else if (mBlueGroup >= 3)
	{
		return true;
	}
	else if (mPurpleGroup >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}


istream& operator>>(istream& inputStream, CProperties& properties) // Reads in the file and sets its properties
{
	inputStream >> properties.mSquareStreetName; // Sets the second part of the name
	inputStream >> properties.mSquareCost; // Sets the square cost
	inputStream >> properties.mSquareRent; // Sets square rent
	inputStream >> properties.mSquareGroup; // Sets the square group

	return inputStream; // Returns the file
}
