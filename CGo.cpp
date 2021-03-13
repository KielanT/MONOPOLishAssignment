#include "CGo.h"

CGo::CGo(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

float CGo::GetSquareCost()
{
	return 0.0f;
}

int CGo::GetSquareType()
{
	return mSquareType;
}

float CGo::GetSquareRent()
{
	return 0.0f;
}

float CGo::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CGo::GetPenalty(int diceRoll)
{
	return 0.0f;
}

istream& operator>>(istream& inputStream, CGo& properties)
{
	return inputStream;
}