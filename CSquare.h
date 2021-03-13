#pragma once
#include <iostream>
#include "CPlayer.h"

using namespace std;

class CSquare
{
protected: 
	// Member Variables
	string mSquareName;
	bool mIsOwned;
	shared_ptr<CPlayer> mOwningPlayer;

public:
	CSquare(istream& file); // Contructor
	virtual ~CSquare(); // Deconstructor
	virtual string GetSquareName();// Used for getting the square name 
	virtual float GetSquareCost() = 0;
	virtual int GetSquareType() = 0;
	virtual float GetSquareRent() = 0;
	virtual float GetPenalty(int diceRoll) = 0;
	virtual float GetBonus(int diceRoll) = 0;
	void SetIsOwned(bool isOwned);
	bool GetIsOwned();
	void SetOwningPlayer(shared_ptr<CPlayer> Player);
	shared_ptr<CPlayer> GetOwningPlayer();


	friend istream& operator >> (istream& inputStream, CSquare& square);
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
};

