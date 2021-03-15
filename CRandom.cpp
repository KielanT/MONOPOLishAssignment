#include "CRandom.h"
#include <iostream>
#include <ctime>


using namespace std;

// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another

const string gSEED_FILE = "seed.txt";

int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

unsigned int SetRandomSeed()
{
	ifstream file; // Creates if stream object, used for storing file and using the file
	int seed = 0;

	file.open(gSEED_FILE); // Opens file to be read 
	if (!file) // Throws an error if the file isn't found
	{
		cout << "ERROR: Can't open input file." << endl;
	}

	if (file.is_open()) // If the file is open then read in the file
	{
		while (!file.eof()) // Reads file until it reaches end of file
		{
			
			file >> seed;
		}

		file.close(); // Closes the file
	}
	return seed;
}
