#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

string CGoToJail::GetSquareName()
{
	string name = mSquareName + " " + mTo + " " + mJail;
	return name;
}

float CGoToJail::GetSquareCost()
{
	return 0.0f;
}

int CGoToJail::GetSquareType()
{
	return mSquareType;
}

float CGoToJail::GetSquareRent()
{
	return 0.0f;
}

float CGoToJail::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CGoToJail::GetPenalty(int diceRoll)
{
	return 0.0f;
}

int CGoToJail::GetColourGroup()
{
	return 0;
}

bool CGoToJail::IsGroupOwned(int group)
{
	return false;
}

istream& operator>>(istream& inputStream, CGoToJail& properties)
{
	inputStream >> properties.mTo;
	inputStream >> properties.mJail;
	return inputStream;
}
