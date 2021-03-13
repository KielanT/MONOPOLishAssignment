#include "CJail.h"

CJail::CJail(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

float CJail::GetSquareCost()
{
	return 0.0f;
}

int CJail::GetSquareType()
{
	return mSquareType;
}

float CJail::GetSquareRent()
{
	return 0.0f;
}

float CJail::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CJail::GetPenalty(int diceRoll)
{
	return 0.0f;
}

istream& operator>>(istream& inputStream, CJail& properties)
{
	return inputStream;
}
