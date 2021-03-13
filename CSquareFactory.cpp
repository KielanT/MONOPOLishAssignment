#include "CSquareFactory.h"
#include "CSquare.h"
#include "CProperties.h"
#include "CGo.h"
#include "CStations.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"

unique_ptr<CSquare> NewSquare(ESquareType square, istream& file)
{
	switch (square)
	{
	case ESquareType::Properties:
	{
		return make_unique<CProperties>(file, 1);
		break;
	}
	case ESquareType::Go:
	{
		return make_unique<CGo>(file, 2);
		break;
	}
	case ESquareType::Station:
	{
		return make_unique<CStations>(file, 3);
		break;
	}
	case ESquareType::Bonus:
	{
		return make_unique<CBonus>(file, 4);
		break;
	}
	case ESquareType::Penalty:
	{
		return make_unique<CPenalty>(file, 5);
		break;
	}
	case ESquareType::Jail:
	{
		return make_unique<CJail>(file, 6);
		break;
	}
	case ESquareType::GoToJail:
	{
		return make_unique<CGoToJail>(file, 7);
		break;
	}
	case ESquareType::FreeParking:
	{
		return make_unique<CFreeParking>(file, 8);
		break;
	}
	}
}