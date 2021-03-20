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

unique_ptr<CSquare> NewSquare(ESquareType square, istream& file) // Function for setting for squares deping on type
{
	switch (square)
	{
	case ESquareType::Properties: // If square is Property square
	{
		return make_unique<CProperties>(file, 1);  // Create a new Property square
		break;
	}
	case ESquareType::Go: // If square is Go square
	{
		return make_unique<CGo>(file, 2); // Create a new Go square
		break;
	}
	case ESquareType::Station: // If square is Station square
	{
		return make_unique<CStations>(file, 3); // Create a new Station square
		break;
	}
	case ESquareType::Bonus: // If square is Bonus square
	{
		return make_unique<CBonus>(file, 4); // Create a new Bonus square
		break;
	}
	case ESquareType::Penalty: // If square is Penalty square
	{
		return make_unique<CPenalty>(file, 5); // Create a new Penalty square
		break;
	}
	case ESquareType::Jail: // If square is Jail square
	{
		return make_unique<CJail>(file, 6); // Create a new Jail square
		break;
	}
	case ESquareType::GoToJail: // If square is GoToJail square
	{
		return make_unique<CGoToJail>(file, 7); // Create a new GoToJail square
		break;
	}
	case ESquareType::FreeParking: // If square is FreeParking square
	{ 
		return make_unique<CFreeParking>(file, 8); // Create a new FreeParking square
		break;
	}
	}
}