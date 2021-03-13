#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include "CMonopolyGame.h";

using namespace std;


int main() // Runs the main program code
{
	{
		unique_ptr<CMonopolyGame> Game = make_unique<CMonopolyGame>();
		Game->Game();
	}
	_CrtDumpMemoryLeaks();
}