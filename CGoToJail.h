#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CGoToJail : public CSquare
{
private:
	string mTo;
	string mJail;
	int mSquareType;

public:
	CGoToJail(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CGoToJail& properties);  // Friend class operator overload function
};

