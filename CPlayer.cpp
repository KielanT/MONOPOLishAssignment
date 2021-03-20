#include "CPlayer.h"

CPlayer::CPlayer() // Constructor
{
	mName = ""; // Sets the name 
	mMoney = 0; // Set the money
	mPosition = 0; // Sets the position
}

CPlayer::CPlayer(string name, float money, int position) // Constructor that sets the name, money and start position
{
	mName = name; // Sets name
	mMoney = money; // Sets money
	mPosition = position; // Sets position
}

CPlayer::~CPlayer() // Deconstructor
{

}

void CPlayer::SetName(string name) // Sets the name
{
	mName = name; // Sets the name variable
}

string CPlayer::GetName() // Gets the name
{
	return mName; // Returns the name variable
}

void CPlayer::SetMoney(float money) // Sets the money
{
	mMoney = money; // Sets the money variable
}

float CPlayer::GetMoney() // Gets the money
{
	return mMoney; // Returns the money
}

void CPlayer::SetPosition(int position) // Sets positions
{
	mPosition = position; // Sets position variable
}

int CPlayer::GetPosition() // Gets the position
{
	return mPosition; // Returns the positions
}
