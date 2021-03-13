#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CGo : public CSquare
{
private:
	int mSquareType;

public:
	CGo(istream& file, int type);
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;

	friend istream& operator >> (istream& inputStream, CGo& properties);
};

