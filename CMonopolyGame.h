#pragma once
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include "CSquare.h"
#include "CSquareFactory.h"
#include "CPlayer.h"


class CMonopolyGame
{
private:
	typedef vector<shared_ptr<CSquare>> CSquareVector;
	const char mPOUND = 156;
	const string mFILE_SQUARES = "monopoly.txt"; // Used for storing the file that stores the square data
	CSquareVector pSquares;
	bool mIsGame;
	bool mIsPlayerOneBankrupt;
	bool mIsPlayerTwoBankrupt;
	bool mIsPlayerThreeBankrupt;
	bool mIsPlayerFourBankrupt;
	string mPlayerWinner;
	int mBankruptAmount = 0;
	vector<shared_ptr<CSquare>> mPOneOwned;
	vector<shared_ptr<CSquare>> mPTwoOwned;
	vector<shared_ptr<CSquare>> mPThreeOwned;
	vector<shared_ptr<CSquare>> mPFourOwned;

	// Creates player sets the name, money and board position
	shared_ptr<CPlayer> mPlayerOne = make_shared<CPlayer>("dog", 1500, 0);
	shared_ptr<CPlayer> mPlayerTwo = make_shared<CPlayer>("car", 1500, 0);
	shared_ptr<CPlayer> mPlayerThree = make_shared<CPlayer>("shoe", 1500, 0);
	shared_ptr<CPlayer> mPlayerFour = make_shared<CPlayer>("hat", 1500, 0);

public:
	CMonopolyGame();
	void Game();

private:
	void Round(shared_ptr<CPlayer> CurrentPlayer, CSquareVector& squares);
	void GameOver();
	void ReadSquaresFile(string fileName, CSquareVector& squares);
};