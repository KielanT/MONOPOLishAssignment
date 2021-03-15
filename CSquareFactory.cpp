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

shared_ptr<CSquare> NewSquare(ESquareType square, istream& file)
{
	switch (square)
	{
	case ESquareType::Properties:
	{
		return make_shared<CProperties>(file, 1);
		break;
	}
	case ESquareType::Go:
	{
		return make_shared<CGo>(file, 2);
		break;
	}
	case ESquareType::Station:
	{
		return make_shared<CStations>(file, 3);
		break;
	}
	case ESquareType::Bonus:
	{
		return make_shared<CBonus>(file, 4);
		break;
	}
	case ESquareType::Penalty:
	{
		return make_shared<CPenalty>(file, 5);
		break;
	}
	case ESquareType::Jail:
	{
		return make_shared<CJail>(file, 6);
		break;
	}
	case ESquareType::GoToJail:
	{
		return make_shared<CGoToJail>(file, 7);
		break;
	}
	case ESquareType::FreeParking:
	{
		return make_shared<CFreeParking>(file, 8);
		break;
	}
	}
}