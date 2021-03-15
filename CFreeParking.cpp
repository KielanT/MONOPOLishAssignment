#include "CFreeParking.h"

CFreeParking::CFreeParking(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;
}

string CFreeParking::GetSquareName()
{
	string name = mSquareName + " " + mSquareParking;
	return name;
}

float CFreeParking::GetSquareCost()
{
	return 0.0f;
}

int CFreeParking::GetSquareType()
{
	return mSquareType;
}

float CFreeParking::GetSquareRent()
{
	return 0.0f;
}

float CFreeParking::GetBonus(int diceRoll)
{
	return 0.0f;
}

float CFreeParking::GetPenalty(int diceRoll)
{
	return 0.0f;
}

int CFreeParking::GetColourGroup()
{
	return 0;
}

bool CFreeParking::IsGroupOwned(int group)
{
	return false;
}

void CFreeParking::AddOwnedList(shared_ptr<CSquare> owned)
{
}

void CFreeParking::RemoveOwnedList(shared_ptr<CSquare> owned)
{
}

vector<shared_ptr<CSquare>> CFreeParking::GetOwnedList()
{
	return vector<shared_ptr<CSquare>>();
}

istream& operator>>(istream& inputStream, CFreeParking& properties)
{
	inputStream >> properties.mSquareParking;
	return inputStream;
}
