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
	int GetColourGroup() override;
	bool IsGroupOwned(int group) override;
	void AddOwnedList(shared_ptr<CSquare> owned) override;
	void RemoveOwnedList(shared_ptr<CSquare> owned) override;
	vector<shared_ptr<CSquare>> GetOwnedList() override;

	friend istream& operator >> (istream& inputStream, CStations& properties);
};

