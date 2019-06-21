#include <iostream>
#include <string>

#include "GameManager.h"

using namespace std;

int main()
{
	//NOTE: dimenisons of the board are 0-2 on both axis
	GameManager game;
	game.InitPlayers();
	game.GameLogic();

	system("PAUSE");
	return 0;
}