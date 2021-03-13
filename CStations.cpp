#include "CStations.h"

CStations::CStations(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

string CStations::GetSquareName()
{
	string name = mSquareName + " " + mSquareStation;
	return name;
}

float CStations::GetSquareCost()
{
	return 0.0f;
}

int CStations::GetSquareType()
{
	return mSquareType;
}

float CStations::GetSquareRent()
{
	return 0.0f;
}

float CStations::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CStations::GetPenalty(int diceRoll)
{
	return 0.0f;
}

istream& operator>>(istream& inputStream, CStations& properties)
{
	inputStream >> properties.mSquareStation;
	return inputStream;
}
