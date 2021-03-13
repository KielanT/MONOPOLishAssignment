#pragma once
#include <memory>
#include "CSquare.h"

using namespace std;

enum class ESquareType : int
{
	Properties = 1,
	Go = 2,
	Station = 3,
	Bonus = 4,
	Penalty = 5,
	Jail = 6,
	GoToJail = 7,
	FreeParking = 8
};

unique_ptr<CSquare> NewSquare(ESquareType square, istream& file);