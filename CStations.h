#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CStations :public CSquare
{
private: // Private member types
	string mSquareStation;
	int mSquareType;

public: // Public functions
	CStations(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CStations& properties); // Friend class operator overload function
};

