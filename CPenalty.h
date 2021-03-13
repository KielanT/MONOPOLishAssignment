#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CPenalty : public CSquare
{
private:
	int mSquareType;
public:
	CPenalty(istream& file, int type);
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CPenalty& properties);
};

