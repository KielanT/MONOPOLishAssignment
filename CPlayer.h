#pragma once
#include <iostream>

using namespace std;

class CPlayer
{
private: // Private member varibales
	string mName;
	float mMoney;
	int mPosition;

public: // Public functions
	CPlayer();
	CPlayer(string name, float money, int position);
	~CPlayer();
	void SetName(string name);
	string GetName();
	void SetMoney(float money);
	float GetMoney();
	void SetPosition(int position);
	int GetPosition();
};

