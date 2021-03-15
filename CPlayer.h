#pragma once
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class CSquare; // Forward Delcaration

class CPlayer
{
private:
	string mName;
	float mMoney;
	int mPosition;
	vector<shared_ptr<CSquare>> mOwnedList;

public:
	CPlayer();
	CPlayer(string name, float money, int position);
	~CPlayer();
	void SetName(string name);
	string GetName();
	void SetMoney(float money);
	float GetMoney();
	void SetPosition(int position);
	int GetPosition();
	void AddOwnedList(shared_ptr<CSquare> owned);
	void RemoveOwnedList(shared_ptr<CSquare> owned);
	vector<shared_ptr<CSquare>> GetOwnedList();

private:
	void SortList(vector<shared_ptr<CSquare>> list);
};

