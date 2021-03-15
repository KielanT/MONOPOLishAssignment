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

int CGo::GetColourGroup()
{
	return 0;
}

bool CGo::IsGroupOwned(int group)
{
	return false;
}

void CGo::AddOwnedList(shared_ptr<CSquare> owned)
{
}

void CGo::RemoveOwnedList(shared_ptr<CSquare> owned)
{
}

vector<shared_ptr<CSquare>> CGo::GetOwnedList()
{
	return vector<shared_ptr<CSquare>>();
}

istream& operator>>(istream& inputStream, CGo& properties)
{
	return inputStream;
}
