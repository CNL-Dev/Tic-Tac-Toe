#pragma once
#include <iostream>
#include <string>

using namespace std;

const int numRow = 3;
const int numCol = 3;

class GameManager
{
public:
	GameManager();
	void InitPlayers();
	void InitBoard();
	void GameLogic();

private:
	char ticTacToe[numRow][numCol] = {'.','.','.','.','.','.','.','.','.'};

	string playerOneName;
	string playerTwoName;

	int turn = 1;

	int playerNumRow;
	int playerNumCol;

	bool isGameOver = false;
};

