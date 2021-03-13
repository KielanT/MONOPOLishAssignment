#include "CProperties.h"

CProperties::CProperties(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

string CProperties::GetSquareName()
{
	string name = mSquareName + " " + mSquareStreetName;
	return name;
}

float CProperties::GetSquareCost()
{
	return mSquareCost;
}

int CProperties::GetSquareType()
{
	return mSquareType;
}

float CProperties::GetSquareRent()
{
	return mSquareRent;
}

float CProperties::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CProperties::GetPenalty(int diceRoll)
{
	return 0.0f;
}


istream& operator>>(istream& inputStream, CProperties& properties)
{
	inputStream >> properties.mSquareStreetName;
	inputStream >> properties.mSquareCost;
	inputStream >> properties.mSquareRent;
	inputStream >> properties.mSquareGroup;

	return inputStream;
}
