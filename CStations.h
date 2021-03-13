#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CStations :public CSquare
{
private:
	string mSquareStation;
	int mSquareType;

public:
	CStations(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;

	friend istream& operator >> (istream& inputStream, CStations& properties);
};

