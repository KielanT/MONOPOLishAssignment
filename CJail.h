#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CJail : public CSquare
{
private: // Private member variables
	int mSquareType;

public: // Public functions
	CJail(istream& file, int type);
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CJail& properties);  // Friend class operator overload function
};

