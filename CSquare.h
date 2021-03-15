#pragma once
#include <iostream>
#include <vector>
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
	virtual void SetIsOwned(bool isOwned, int group);
	virtual bool GetIsOwned();
	virtual void SetOwningPlayer(shared_ptr<CPlayer> player);
	virtual shared_ptr<CPlayer> GetOwningPlayer();
	virtual float GetSquareCost() = 0;
	virtual int GetSquareType() = 0;
	virtual float GetSquareRent() = 0;
	virtual float GetPenalty(int diceRoll) = 0;
	virtual float GetBonus(int diceRoll) = 0;
	virtual int GetColourGroup() = 0;
	virtual bool IsGroupOwned(int group) = 0;
	virtual void AddOwnedList(shared_ptr<CSquare> owned) = 0;
	virtual void RemoveOwnedList(shared_ptr<CSquare> owned) = 0;
	virtual vector<shared_ptr<CSquare>> GetOwnedList() = 0;

	friend istream& operator >> (istream& inputStream, CSquare& square);
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
};

