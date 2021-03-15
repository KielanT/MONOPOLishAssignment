#include "CMonopolyGame.h"
#include "CRandom.h"


CMonopolyGame::CMonopolyGame()
{
	ReadSquaresFile(mFILE_SQUARES, pSquares);
	mIsGame = true;
	mPlayerWinner = "";
	mIsPlayerOneBankrupt = false;
	mIsPlayerTwoBankrupt = false;
	mIsPlayerThreeBankrupt = false;
	mIsPlayerFourBankrupt = false;
	mBankruptAmount = 0;
}

void CMonopolyGame::Game()
{
	cout << "Welcome to Monopol-ish" << endl << endl; // Title Text


	srand(SetRandomSeed()); // Used for setting the seed for the random generator so that it gives a random number everytime 

	while(mIsGame)
	{
		// Runs the round code, keeps the code neat
		if (!mIsPlayerOneBankrupt)
		{
			Round(mPlayerOne, pSquares);
		}
		if (!mIsPlayerTwoBankrupt)
		{
			Round(mPlayerTwo, pSquares);
		}
		if (!mIsPlayerThreeBankrupt)
		{
			Round(mPlayerThree, pSquares);
		}
		if (!mIsPlayerFourBankrupt)
		{
			Round(mPlayerFour, pSquares);
		}
	}

	GameOver();
}

void CMonopolyGame::Round(shared_ptr<CPlayer> CurrentPlayer, CSquareVector& squares)
{
	shared_ptr<CPlayer> OtherPlayer;

	//cout << " " << Player->GetName() << " Turn " << endl << endl; // Outputs the players turn

	int dice = Random(); // Sets dice to a random number between 1 and 6
	cout << " " << CurrentPlayer->GetName() << " rolls " << dice << endl << endl; // Output the player and what the player has rolled

	int PreviousPosition = CurrentPlayer->GetPosition(); // Sets the previous position the player was on

	// if statement that sets the position, if the player goes passed the last square then it resets the position of the index
	if (PreviousPosition >= 20) // Checks if the Player is on square 20 or higher
	{
		int temp = PreviousPosition + dice; // A temp variable used for checking if the index has gone to high
		if (temp > 25) // If the temp variable is bigger than 25 then set the correct position and index
		{
			CurrentPlayer->SetPosition(temp - 26); // Sets the position correctly by calculating how much the index has gone over
		}
	}
	else
	{
		CurrentPlayer->SetPosition(CurrentPlayer->GetPosition() + dice); // Sets position if there is no need to check if the index has gone over the correct index count
	}

	cout << " " << CurrentPlayer->GetName() << " lands on " << squares[CurrentPlayer->GetPosition()]->GetSquareName() << endl << endl; // Outputs the square the player has landed on

	// If unowned player who lands on it buys it but only if they have a positive amount of money
	// player becomes property owner
	/*output <player> buys <square name> for <costs> */
	if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 1 || squares[CurrentPlayer->GetPosition()]->GetSquareType() == 3)
	{
		if (!squares[CurrentPlayer->GetPosition()]->GetIsOwned() && CurrentPlayer->GetMoney() > 0)
		{
			squares[CurrentPlayer->GetPosition()]->SetIsOwned(true, squares[CurrentPlayer->GetPosition()]->GetColourGroup());
			squares[CurrentPlayer->GetPosition()]->SetOwningPlayer(CurrentPlayer);

			if (CurrentPlayer == mPlayerOne)
			{
				mPOneOwned.push_back(squares[CurrentPlayer->GetPosition()]);
			}
			else if (CurrentPlayer == mPlayerTwo)
			{
				mPTwoOwned.push_back(squares[CurrentPlayer->GetPosition()]);
			}
			else if (CurrentPlayer == mPlayerThree)
			{
				mPThreeOwned.push_back(squares[CurrentPlayer->GetPosition()]);
			}
			else if (CurrentPlayer == mPlayerFour)
			{
				mPFourOwned.push_back(squares[CurrentPlayer->GetPosition()]);
			}
			CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - squares[CurrentPlayer->GetPosition()]->GetSquareCost());
			cout << CurrentPlayer->GetName() + " buys " + squares[CurrentPlayer->GetPosition()]->GetSquareName() + " for " << mPOUND << squares[CurrentPlayer->GetPosition()]->GetSquareCost() << endl;
			cout << CurrentPlayer->GetName() << " pays " << mPOUND << squares[CurrentPlayer->GetPosition()]->GetSquareCost() << endl;
		}
		else if (squares[CurrentPlayer->GetPosition()]->GetIsOwned() && squares[CurrentPlayer->GetPosition()]->GetOwningPlayer() != CurrentPlayer)
		{
			OtherPlayer = squares[CurrentPlayer->GetPosition()]->GetOwningPlayer();
			// If owned but the owner player lands on it nothing happens
			// If owned but by another player then pay rent to the owner player (rent is deducted from the player who landed on it then added to the owners balance)
			/*output <player> pays <rent> */
			if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 3) // If landed on square then brought ticket
			{
				OtherPlayer->SetMoney(OtherPlayer->GetMoney() + 10.0f); 
				CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - 10.0f);
				cout << CurrentPlayer->GetName() << " pays " << mPOUND << "10 for ticket" << endl;
			}
			else
			{
				if (squares[CurrentPlayer->GetPosition()]->IsGroupOwned(squares[CurrentPlayer->GetPosition()]->GetColourGroup())) // Doubles the rent
				{
					OtherPlayer->SetMoney(OtherPlayer->GetMoney() + (squares[CurrentPlayer->GetPosition()]->GetSquareRent() * 2)); // Pay rent to other player
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - (squares[CurrentPlayer->GetPosition()]->GetSquareRent() * 2)); // Minus rent from this player
				}
				else
				{
					OtherPlayer->SetMoney(OtherPlayer->GetMoney() + squares[CurrentPlayer->GetPosition()]->GetSquareRent()); // Pay rent to other player
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - squares[CurrentPlayer->GetPosition()]->GetSquareRent()); // Minus rent from this player
				}
				cout << CurrentPlayer->GetName() << " pays " << mPOUND << squares[CurrentPlayer->GetPosition()]->GetSquareRent() << endl; // Output
			}
		}
	}
	else if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 6) // If player lands on jail, nothing happens but output
	{
		cout << CurrentPlayer->GetName() << " lands on Jail" << endl;
	}
	else if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 7) // If player lands on go to jail then move to jail, pay 50 and output
	{
		CurrentPlayer->SetPosition(7); // Move to jail
		CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - 50); // Pay 50

		// Output
		cout << CurrentPlayer->GetName() << " lands on Go to Jail" << endl;
		cout << CurrentPlayer->GetName() << " goes to Jail" << endl;
		cout << CurrentPlayer->GetName() << " pays " << mPOUND << "50" << endl;
	}
	else if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 8) // If player lands on Free parking then nothing happens, output
	{
		cout << CurrentPlayer->GetName() << " is resting" << endl;
	}
	else if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 4) // If lands on bonus roll again and make the player take a bonus
	{
		int rollDiceAgain = Random(); // Sets dice to a random number between 1 and 6

		float BonusPrice = squares[CurrentPlayer->GetPosition()]->GetBonus(rollDiceAgain);
		CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + BonusPrice);
	}
	else if (squares[CurrentPlayer->GetPosition()]->GetSquareType() == 5) // If lands on penalty roll again and make the player take a penalty
	{
		int rollDiceAgain = Random(); // Sets dice to a random number between 1 and 6

		float penaltyPrice = squares[CurrentPlayer->GetPosition()]->GetPenalty(rollDiceAgain);
		CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() - penaltyPrice);
	}


	// Mortgage one or more properties until their balance rises above zero
	// Properties should be in value order starting with the lowest valued property first
	// When a property is mortgaged the player is lent the original value of the property
	if (CurrentPlayer == mPlayerOne)
	{
		sort(mPOneOwned.begin(), mPOneOwned.end()); // Sorts lowest to highest
		if (CurrentPlayer->GetMoney() <= 0.0f)
		{
			for (auto i = 0; i < mPOneOwned.size(); ++i)
			{
				if (mPOneOwned[i]->GetOwningPlayer() == CurrentPlayer)
				{
					//owned[i]->SetIsOwned(false, owned[i]->GetColourGroup());
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + mPOneOwned[i]->GetSquareCost());
					//owned[i]->RemoveOwnedList(owned[i]);

					cout << CurrentPlayer->GetName() << " Mortgages " << mPOneOwned[i]->GetSquareName() << " for " << mPOUND << mPOneOwned[i]->GetSquareCost() << endl;
				}
				if (CurrentPlayer->GetMoney() > 0)
				{
					break;
				}
			}
		}
	}
	else if (CurrentPlayer == mPlayerTwo)
	{
		sort(mPTwoOwned.begin(), mPTwoOwned.end()); // Sorts lowest to highest
		if (CurrentPlayer->GetMoney() <= 0.0f)
		{
			for (auto i = 0; i < mPTwoOwned.size(); ++i)
			{
				if (mPTwoOwned[i]->GetOwningPlayer() == CurrentPlayer)
				{
					//owned[i]->SetIsOwned(false, owned[i]->GetColourGroup());
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + mPTwoOwned[i]->GetSquareCost());
					//owned[i]->RemoveOwnedList(owned[i]);

					cout << CurrentPlayer->GetName() << " Mortgages " << mPTwoOwned[i]->GetSquareName() << " for " << mPOUND << mPTwoOwned[i]->GetSquareCost() << endl;
				}
				if (CurrentPlayer->GetMoney() > 0)
				{
					break;
				}
			}
		}
	}
	else if (CurrentPlayer == mPlayerThree)
	{
		sort(mPThreeOwned.begin(), mPThreeOwned.end()); // Sorts lowest to highest
		if (CurrentPlayer->GetMoney() <= 0.0f)
		{
			for (auto i = 0; i < mPThreeOwned.size(); ++i)
			{
				if (mPThreeOwned[i]->GetOwningPlayer() == CurrentPlayer)
				{
					//owned[i]->SetIsOwned(false, owned[i]->GetColourGroup());
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + mPThreeOwned[i]->GetSquareCost());
					//owned[i]->RemoveOwnedList(owned[i]);

					cout << CurrentPlayer->GetName() << " Mortgages " << mPThreeOwned[i]->GetSquareName() << " for " << mPOUND << mPThreeOwned[i]->GetSquareCost() << endl;
				}
				if (CurrentPlayer->GetMoney() > 0)
				{
					break;
				}
			}
		}
	}
	else if (CurrentPlayer == mPlayerFour)
	{
		sort(mPFourOwned.begin(), mPFourOwned.end()); // Sorts lowest to highest
		if (CurrentPlayer->GetMoney() <= 0.0f)
		{
			for (auto i = 0; i < mPFourOwned.size(); ++i)
			{
				if (mPFourOwned[i]->GetOwningPlayer() == CurrentPlayer)
				{
					//owned[i]->SetIsOwned(false, owned[i]->GetColourGroup());
					CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + mPFourOwned[i]->GetSquareCost());
					//owned[i]->RemoveOwnedList(owned[i]);

					cout << CurrentPlayer->GetName() << " Mortgages " << mPFourOwned[i]->GetSquareName() << " for " << mPOUND << mPFourOwned[i]->GetSquareCost() << endl;
				}
				if (CurrentPlayer->GetMoney() > 0)
				{
					break;
				}
			}
		}
	}


	if (CurrentPlayer->GetMoney() <= 0.0f)
	{
		// Bankrupt lose game
		if (CurrentPlayer == mPlayerOne)
		{
			mIsPlayerOneBankrupt = true;
		}
		else if (CurrentPlayer == mPlayerTwo)
		{
			mIsPlayerTwoBankrupt = true;
		}
		else if (CurrentPlayer == mPlayerThree)
		{
			mIsPlayerThreeBankrupt = true;
		}
		else if (CurrentPlayer == mPlayerFour)
		{
			mIsPlayerFourBankrupt = true;
		}
		mBankruptAmount++;
	}

	if (mBankruptAmount == 3)
	{
		mIsGame = false;
	}

	if (PreviousPosition >= 20 && CurrentPlayer->GetPosition() <= 6) // Checks if the player has gone passed index 0 
	{
		cout << " " << CurrentPlayer->GetName() << " passes GO and collects " << mPOUND << "200" << endl << endl; // Outputs the player has passed go and collected 200
		CurrentPlayer->SetMoney(CurrentPlayer->GetMoney() + 200); // Adds £200 to the players money
	}

	

	cout << CurrentPlayer->GetName() << " has " << mPOUND << CurrentPlayer->GetMoney() << endl << endl;

	cout << " ------------------------------------------------------------ " << endl << endl; // Round divider
}

void CMonopolyGame::GameOver()
{
	cout << "Game Over" << endl; // Game Over Text
		// Outputs the players name and the amount of money they have after the game
	cout << mPlayerOne->GetName() << " has " << mPOUND << mPlayerOne->GetMoney() << endl;
	cout << mPlayerTwo->GetName() << " has " << mPOUND << mPlayerTwo->GetMoney() << endl;
	cout << mPlayerThree->GetName() << " has " << mPOUND << mPlayerTwo->GetMoney() << endl;
	cout << mPlayerFour->GetName() << " has " << mPOUND << mPlayerTwo->GetMoney() << endl;

	//if (PlayerOne->GetMoney() > PlayerTwo->GetMoney()) // If player one has more money than player two, player one wins
	//{
	//	cout << PlayerOne->GetName() << " wins." << endl;
	//}
	//else if (PlayerOne->GetMoney() < PlayerTwo->GetMoney()) // If player two has more money than player one, player two wins
	//{
	//	cout << PlayerTwo->GetName() << " wins." << endl;
	//}
	//else
	//{
	//	cout << "draw." << endl; // If players have the same amount of money then there is a draw
	//}

	if (!mIsPlayerOneBankrupt)
	{
		cout << mPlayerOne << " wins." << endl;
	}
	else if (!mIsPlayerTwoBankrupt)
	{
		cout << mPlayerTwo << " wins." << endl;
	}
	else if (!mIsPlayerThreeBankrupt)
	{
		cout << mPlayerThree << " wins." << endl;
	}
	else if (!mIsPlayerFourBankrupt)
	{
		cout << mPlayerFour << " wins." << endl;
	}
}

void CMonopolyGame::ReadSquaresFile(string fileName, CSquareVector& squares)
{
	ifstream file; // Creates if stream object, used for storing file and using the file

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