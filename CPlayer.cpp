#include "CPlayer.h"
#include "CSquare.h"
#include <algorithm>

CPlayer::CPlayer()
{
	{
		mName = "";
		mMoney = 0;
		mPosition = 0;
	}
}

CPlayer::CPlayer(string name, float money, int position)
{
	mName = name;
	mMoney = money;
	mPosition = position;
}

CPlayer::~CPlayer()
{

}

void CPlayer::SetName(string name)
{
	mName = name;
}

string CPlayer::GetName()
{
	return mName;
}

void CPlayer::SetMoney(float money)
{
	mMoney = money;
}

float CPlayer::GetMoney()
{
	return mMoney;
}

void CPlayer::SetPosition(int position)
{
	mPosition = position;
}

int CPlayer::GetPosition()
{
	return mPosition;
}

void CPlayer::AddOwnedList(shared_ptr<CSquare> owned)
{
	mOwnedList.push_back(owned);
	SortList(mOwnedList);
}

void CPlayer::RemoveOwnedList(shared_ptr<CSquare> owned)
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

vector<shared_ptr<CSquare>> CPlayer::GetOwnedList()
{
	return mOwnedList;
}

void CPlayer::SortList(vector<shared_ptr<CSquare>> list)
{
	sort(list.begin(), list.end()); // Sorts lowest to highest
}
