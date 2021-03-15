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

int CStations::GetColourGroup()
{
	return 0;
}

bool CStations::IsGroupOwned(int group)
{
	return false;
}

void CStations::AddOwnedList(shared_ptr<CSquare> owned)
{
}

void CStations::RemoveOwnedList(shared_ptr<CSquare> owned)
{
}

vector<shared_ptr<CSquare>> CStations::GetOwnedList()
{
	return vector<shared_ptr<CSquare>>();
}

istream& operator>>(istream& inputStream, CStations& properties)
{
	inputStream >> properties.mSquareStation;

	return inputStream;
}
