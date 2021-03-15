#include "CSquare.h"


CSquare::CSquare(istream& file)
{
	file >> *this;
	mIsOwned = false;
	mOwningPlayer = nullptr;
}

CSquare::~CSquare()
{
}

string CSquare::GetSquareName()
{
	return mSquareName; // Returns the square name
}

void CSquare::SetIsOwned(bool isOwned, int group)
{
	mIsOwned = isOwned;
}

bool CSquare::GetIsOwned()
{
	return mIsOwned;
}

void CSquare::SetOwningPlayer(shared_ptr<CPlayer> player)
{
	mOwningPlayer = player;
}

shared_ptr<CPlayer> CSquare::GetOwningPlayer()
{
	return mOwningPlayer;
}



istream& operator >> (istream& inputStream, CSquare& square)
{
	inputStream >> square.mSquareName;
	return inputStream;
}

ostream& operator<<(ostream& outputStream, const CSquare& square)
{
	outputStream << square.mSquareName;

	return outputStream;
}
