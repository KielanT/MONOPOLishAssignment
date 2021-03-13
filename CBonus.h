#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CBonus : public CSquare
{
private:
	int mSquareType;

public:
	CBonus(istream& file, int type);
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CBonus& properties);
};

