#pragma once
#include <fstream>
#include <vector>
#include <memory>
#include "CSquare.h"
#include "CSquareFactory.h"
#include "CPlayer.h"


class CMonopolyGame
{
private:
	typedef vector<unique_ptr<CSquare>> CSquareVector;
	const char mPOUND = 156;
	const string mFILE_SQUARES = "monopoly.txt"; // Used for storing the file that stores the square data
	CSquareVector pSquares;

public:
	CMonopolyGame();
	void Game();

private:
	void Round(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> OtherPlayer, CSquareVector& squares);
	void GameOver(shared_ptr<CPlayer> PlayerOne, shared_ptr<CPlayer> PlayerTwo);
	void ReadSquaresFile(string fileName, CSquareVector& squares);
};

