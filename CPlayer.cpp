#include "CPlayer.h"

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
