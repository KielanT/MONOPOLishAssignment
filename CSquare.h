#pragma once
#include <iostream>
#include "CPlayer.h"

using namespace std;

class CSquare
{
protected: // Protected member variables (protected so they can be set in derived classes
	// Member Variables
	string mSquareName;
	bool mIsOwned;
	shared_ptr<CPlayer> mOwningPlayer;

public: // Public functions
	CSquare(istream& file); // Contructor
	virtual ~CSquare(); // Deconstructor
	virtual string GetSquareName();// Used for getting the square name 
	virtual void SetIsOwned(bool isOwned, int group);
	virtual bool GetIsOwned();
	virtual void SetOwningPlayer(shared_ptr<CPlayer> Player);
	virtual shared_ptr<CPlayer> GetOwningPlayer();

	// Virtual function set to 0 so that it doesn't need to be created in this class but the derived classes
	virtual float GetSquareCost() = 0;
	virtual int GetSquareType() = 0;
	virtual float GetSquareRent() = 0;
	virtual float GetPenalty(int diceRoll) = 0;
	virtual float GetBonus(int diceRoll) = 0;
	virtual int GetColourGroup() = 0;
	virtual bool IsGroupOwned(int group) = 0;

	friend istream& operator >> (istream& inputStream, CSquare& square);  // Friend class operator overload function
	friend ostream& operator << (ostream& outputStream, const CSquare& square);  // Friend class operator overload function
};

