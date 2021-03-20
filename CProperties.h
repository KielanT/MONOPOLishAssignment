#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"

class CProperties : public CSquare
{
private: // Private member variables
	string mSquareStreetName;
	int mSquareType; 
	float mSquareCost;
	float mSquareRent;
	int mSquareGroup;

	int mRedGroup;
	int mGreyGroup;
	int mBrownGroup;
	int mOrangeGroup;
	int mYellowGroup;
	int mGreenGroup;
	int mBlueGroup;
	int mPurpleGroup;

public: // Public functions
	CProperties(istream& file, int type);
	virtual string GetSquareName() override;
	float GetSquareCost() override;
	int GetSquareType() override;
	float GetSquareRent() override;
	float GetBonus(int diceRoll) override;
	float GetPenalty(int diceRoll) override;
	int GetColourGroup() override;

	void SetIsOwned(bool isOwned, int group) override;
	bool GetIsOwned() override;
	void SetOwningPlayer(shared_ptr<CPlayer> Player) override;
	shared_ptr<CPlayer> GetOwningPlayer() override;
	bool IsGroupOwned(int group) override;

	friend istream& operator >> (istream& inputStream, CProperties& properties);  // Friend class operator overload function
};

