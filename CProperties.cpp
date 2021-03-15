#include "CProperties.h"
#include <algorithm>

CProperties::CProperties(istream& file, int type) : CSquare(file)
{
	file >> *this;
	mSquareType = type;

	mRedGroup = 0;
	mGreyGroup = 0;
	mBrownGroup = 0;
	mOrangeGroup = 0;
	mYellowGroup = 0;
	mGreenGroup = 0;
	mBlueGroup = 0;
	mPurpleGroup = 0;
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

int CProperties::GetColourGroup()
{
	return mSquareGroup;
}

void CProperties::SetIsOwned(bool isOwned, int group)
{
	if (isOwned)
	{
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
	}
	else
	{
		if (group == 0)
		{
			mRedGroup--;
		}
		else if (group == 1)
		{
			mGreyGroup++;
		}
		else if (group == 2)
		{
			mBrownGroup--;
		}
		else if (group == 3)
		{
			mOrangeGroup--;
		}
		else if (group == 4)
		{
			mYellowGroup--;
		}
		else if (group == 5)
		{
			mGreenGroup--;
		}
		else if (group == 6)
		{
			mBlueGroup--;
		}
		else if (group == 7)
		{
			mBlueGroup--;
		}
	}

	mIsOwned = isOwned;
}

bool CProperties::GetIsOwned()
{
	return mIsOwned;
}

void CProperties::SetOwningPlayer(shared_ptr<CPlayer> player)
{
	mPlayer = player;
}

shared_ptr<CPlayer> CProperties::GetOwningPlayer()
{
	return mPlayer;
}


bool CProperties::IsGroupOwned(int group)
{
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

void CProperties::AddOwnedList(shared_ptr<CSquare> owned)
{
	mOwnedList.push_back(owned);
	SortList(mOwnedList);
}

void CProperties::RemoveOwnedList(shared_ptr<CSquare> owned)
{
	for (auto i = 0; i < mOwnedList.size(); ++i)
	{
		if (mOwnedList[i]->GetSquareName() == owned->GetSquareName())
		{
			mOwnedList.erase(mOwnedList.begin() + i);
		}
	}
	SortList(mOwnedList);
}

vector<shared_ptr<CSquare>> CProperties::GetOwnedList()
{
	return mOwnedList;
}

void CProperties::SortList(vector<shared_ptr<CSquare>> list)
{
	sort(list.begin(), list.end()); // Sorts lowest to highest
}



istream& operator>>(istream& inputStream, CProperties& properties)
{
	inputStream >> properties.mSquareStreetName;
	inputStream >> properties.mSquareCost;
	inputStream >> properties.mSquareRent;
	inputStream >> properties.mSquareGroup;

	return inputStream;
}
