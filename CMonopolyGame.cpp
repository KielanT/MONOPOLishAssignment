#include "CMonopolyGame.h"

CMonopolyGame::CMonopolyGame()
{
	ReadSquaresFile(mFILE_SQUARES, pSquares);
}

void CMonopolyGame::Game()
{
	cout << "Welcome to Monopol-ish" << endl << endl; // Title Text

	// Creates player sets the name, money and board position
	shared_ptr<CPlayer> pPlayerOne = make_shared<CPlayer>("dog", 1500, 0);
	shared_ptr<CPlayer> pPlayerTwo = make_shared<CPlayer>("car", 1500, 0);

	srand((unsigned)time(0)); // Used for setting the seed for the random generator so that it gives a random number everytime 

	for (int i = 1; i <= 20; ++i) // Runs the game for 20 rounds
	{
		//cout << " Round " << i << endl; // Outputs the round
		// Runs the round code, keeps the code neat
		Round(pPlayerOne, pPlayerTwo, pSquares);
		Round(pPlayerTwo, pPlayerOne, pSquares);
	}

	GameOver(pPlayerOne, pPlayerTwo);
}

void CMonopolyGame::Round(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> OtherPlayer, CSquareVector& squares)
{
	//cout << " " << Player->GetName() << " Turn " << endl << endl; // Outputs the players turn

	int dice = rand() % 6 + 1; // Sets dice to a random number between 1 and 6
	cout << " " << Player->GetName() << " rolls " << dice << endl << endl; // Output the player and what the player has rolled

	int PreviousPosition = Player->GetPosition(); // Sets the previous position the player was on

	// if statement that sets the position, if the player goes passed the last square then it resets the position of the index
	if (PreviousPosition >= 20) // Checks if the Player is on square 20 or higher
	{
		int temp = PreviousPosition + dice; // A temp variable used for checking if the index has gone to high
		if (temp > 25) // If the temp variable is bigger than 25 then set the correct position and index
		{
			Player->SetPosition(temp - 26); // Sets the position correctly by calculating how much the index has gone over
		}
	}
	else
	{
		Player->SetPosition(Player->GetPosition() + dice); // Sets position if there is no need to check if the index has gone over the correct index count
	}

	cout << " " << Player->GetName() << " lands on " << squares[Player->GetPosition()]->GetSquareName() << endl << endl; // Outputs the square the player has landed on

	// If unowned player who lands on it buys it but only if they have a positive amount of money
	// player becomes property owner
	/*output <player> buys <square name> for <costs> */
	if (squares[Player->GetPosition()]->GetSquareType() == 1 || squares[Player->GetPosition()]->GetSquareType() == 3)
	{
		if (!squares[Player->GetPosition()]->GetIsOwned() && Player->GetMoney() > 0)
		{
			squares[Player->GetPosition()]->SetIsOwned(true);
			squares[Player->GetPosition()]->SetOwningPlayer(Player);

			Player->SetMoney(Player->GetMoney() - squares[Player->GetPosition()]->GetSquareCost());
			cout << Player->GetName() + " buys " + squares[Player->GetPosition()]->GetSquareName() + " for " << squares[Player->GetPosition()]->GetSquareCost() << endl;
		}

		// If owned but the owner player lands on it nothing happens
		// If owned but by another player then pay rent to the owner player (rent is deducted from the player who landed on it then added to the owners balance)
		/*output <player> pays <rent> */
		if (squares[Player->GetPosition()]->GetIsOwned() && squares[Player->GetPosition()]->GetOwningPlayer() != Player)
		{
			OtherPlayer->SetMoney(OtherPlayer->GetMoney() + squares[Player->GetPosition()]->GetSquareRent()); // Pay rent to other player
			Player->SetMoney(Player->GetMoney() - squares[Player->GetPosition()]->GetSquareRent()); // Minus rent from this player

			if (squares[Player->GetPosition()]->GetSquareType() == 3) // If landed on square then brought ticket
			{
				cout << Player->GetName() << " pays " << mPOUND << "10 for ticket" << endl;
			}
			else
			{
				cout << Player->GetName() << " pays " << mPOUND << squares[Player->GetPosition()]->GetSquareRent() << endl; // Output
			}
		}
	}
	else if (squares[Player->GetPosition()]->GetSquareType() == 6) // If player lands on jail, nothing happens but output
	{
		cout << Player->GetName() << " lands on Jail" << endl;
	}
	else if (squares[Player->GetPosition()]->GetSquareType() == 7) // If player lands on go to jail then move to jail, pay 50 and output
	{
		Player->SetPosition(7); // Move to jail
		Player->SetMoney(Player->GetMoney() - 50); // Pay 50

		// Output
		cout << Player->GetName() << " lands on Go to Jail" << endl;
		cout << Player->GetName() << " goes to Jail" << endl;
		cout << Player->GetName() << " pays " << mPOUND << "50" << endl;
	}
	else if (squares[Player->GetPosition()]->GetSquareType() == 8) // If player lands on Free parking then nothing happens, output
	{
		cout << Player->GetName() << " is resting" << endl;
	}
	else if (squares[Player->GetPosition()]->GetSquareType() == 4) // If lands on bonus roll again and make the player take a bonus
	{
		int rollDiceAgain = rand() % 6 + 1; // Sets dice to a random number between 1 and 6

		float BonusPrice = squares[Player->GetPosition()]->GetBonus(rollDiceAgain);
		Player->SetMoney(Player->GetMoney() + BonusPrice);
	}
	else if (squares[Player->GetPosition()]->GetSquareType() == 5) // If lands on penalty roll again and make the player take a penalty
	{
		int rollDiceAgain = rand() % 6 + 1; // Sets dice to a random number between 1 and 6

		float penaltyPrice = squares[Player->GetPosition()]->GetPenalty(rollDiceAgain);
		Player->SetMoney(Player->GetMoney() - penaltyPrice);
	}

	if (PreviousPosition >= 20 && Player->GetPosition() <= 6) // Checks if the player has gone passed index 0 
	{
		cout << " " << Player->GetName() << " passes GO and collects " << mPOUND << "200" << endl << endl; // Outputs the player has passed go and collected 200
		Player->SetMoney(Player->GetMoney() + 200); // Adds £200 to the players money
	}

	cout << Player->GetName() << " has " << mPOUND << Player->GetMoney() << endl << endl;

	cout << " ------------------------------------------------------------ " << endl << endl; // Round divider
}

void CMonopolyGame::GameOver(shared_ptr<CPlayer> PlayerOne, shared_ptr<CPlayer> PlayerTwo)
{
	cout << "Game Over" << endl; // Game Over Text
		// Outputs the players name and the amount of money they have after the game
	cout << PlayerOne->GetName() << " has " << mPOUND << PlayerOne->GetMoney() << endl;
	cout << PlayerTwo->GetName() << " has " << mPOUND << PlayerTwo->GetMoney() << endl;

	if (PlayerOne->GetMoney() > PlayerTwo->GetMoney()) // If player one has more money than player two, player one wins
	{
		cout << PlayerOne->GetName() << " wins." << endl;
	}
	else if (PlayerOne->GetMoney() < PlayerTwo->GetMoney()) // If player two has more money than player one, player two wins
	{
		cout << PlayerTwo->GetName() << " wins." << endl;
	}
	else
	{
		cout << "draw." << endl; // If players have the same amount of money then there is a draw
	}
}

void CMonopolyGame::ReadSquaresFile(string fileName, CSquareVector& squares)
{
	ifstream file; // Creates if stream object, used for storing file and using the file
	string line; // Used for storing each line of the file

	file.open(fileName); // Opens file to be read 
	if (!file) // Throws an error if the file isn't found
	{
		cout << "ERROR: Can't open input file." << endl;
	}

	if (file.is_open()) // If the file is open then read in the file
	{
		while (!file.eof()) // Reads file until it reaches end of file
		{
			int type = 0;
			file >> type;

			if (type != 0)
			{
				//cout << type << endl;
				squares.push_back(NewSquare(ESquareType(type), file));
			}
		}

		file.close(); // Closes the file
	}


}