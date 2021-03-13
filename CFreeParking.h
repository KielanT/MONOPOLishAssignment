#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CFreeParking : public CSquare
{
private:
	string mSquareParking;
	int mSquareType;

public:
	CFreeParking(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CFreeParking& properties);
};

