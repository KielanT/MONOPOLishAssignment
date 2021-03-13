#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CProperties : public CSquare
{
private:
	string mSquareStreetName;
	float mSquareCost;
	float mSquareRent;
	int mSquareGroup;
	int mSquareType;

public: 
	CProperties(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;


	friend istream& operator >> (istream& inputStream, CProperties& properties);
};

