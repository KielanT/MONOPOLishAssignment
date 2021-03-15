#pragma once
#include "CSquare.h"
#include "CSquareFactory.h"


class CProperties : public CSquare
{
private:
	string mSquareStreetName;
	int mSquareType; 
	float mSquareCost;
	float mSquareRent;
	int mSquareGroup;
	shared_ptr<CPlayer> mPlayer;
	vector<shared_ptr<CSquare>> mOwnedList;

	int mRedGroup;
	int mGreyGroup;
	int mBrownGroup;
	int mOrangeGroup;
	int mYellowGroup;
	int mGreenGroup;
	int mBlueGroup;
	int mPurpleGroup;

public: 
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
	void AddOwnedList(shared_ptr<CSquare> owned) override;
	void RemoveOwnedList(shared_ptr<CSquare> owned) override;
	vector<shared_ptr<CSquare>> GetOwnedList() override;

	void SortList(vector<shared_ptr<CSquare>> list);

	friend istream& operator >> (istream& inputStream, CProperties& properties);
};

