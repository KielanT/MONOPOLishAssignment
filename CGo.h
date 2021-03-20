#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CGo : public CSquare
{
private: // Private member variables
	int mSquareType;

public: // Public functions
	CGo(istream& file, int type);
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CGo& properties);  // Friend class operator overload function
};

