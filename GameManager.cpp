#include "GameManager.h"

GameManager::GameManager()
{
	
}

//Initializes 2 players
void GameManager::InitPlayers()
{
	cout << "Player 1, what is your name? ";
	cin >> playerOneName;
	cout << "\nYou are " << playerOneName << endl;

	cout << "Player 2, what is your name? ";
	cin >> playerTwoName;
	cout << "\nYou are " << playerTwoName << endl;

	cout << "\n\n********************************\n\n";

	cout << playerOneName << " VS " << playerTwoName << endl;
}

//Prints current board
void GameManager::InitBoard()
{
	for (int y = 0; y < numCol; y++)
	{
		for (int x = 0; x < numRow; x++)
		{
			cout << ticTacToe[y][x];
		}
		cout << endl;
	}
}

//Runs the game logic
void GameManager::GameLogic()
{
	while (isGameOver == false)
	{
		//If turn is odd, its player ones turn
		if ((turn - 1) % 2 == 0)
		{
			cout << playerOneName << " select a x-axis: ";
			cin >> playerNumRow;
			cout << playerOneName << " select a y-axis: ";
			cin >> playerNumCol;

			if (numRow <= playerNumRow || numCol <= playerNumCol)
			{
				cout << "ILLEGAL MOVE!\n";
			}
			else if (ticTacToe[playerNumRow][playerNumCol] == 'X' || ticTacToe[playerNumRow][playerNumCol] == 'O')
			{
				cout << "SPOT IS TAKEN OR ILLEGAL CHARACTER!\n";
			}
			else
			{
				ticTacToe[playerNumRow][playerNumCol] = 'X';
				if ((ticTacToe[0][0] == 'X' && ticTacToe[0][1] == 'X' && ticTacToe[0][2] == 'X') || (ticTacToe[1][0] == 'X' && ticTacToe[1][1] == 'X' && ticTacToe[1][2] == 'X') ||
					(ticTacToe[2][0] == 'X' && ticTacToe[2][1] == 'X' && ticTacToe[2][2] == 'X') || (ticTacToe[0][0] == 'X' && ticTacToe[1][1] == 'X' && ticTacToe[2][2] == 'X') ||
					(ticTacToe[2][0] == 'X' && ticTacToe[1][1] == 'X' && ticTacToe[0][2] == 'X'))
				{
					cout << playerOneName << " WINS!\n";
					isGameOver = true;
				}
				turn++;
			}
			InitBoard();
		}

		//If turn is even, its player twos turn
		else if ((turn - 1) % 2 != 0)
		{
			cout << playerTwoName << " select a x-axis: ";
			cin >> playerNumRow;
			cout << playerTwoName << " select a y-axis: ";
			cin >> playerNumCol;

			if (numRow <= playerNumRow || numCol <= playerNumCol)
			{
				cout << "ILLEGAL MOVE!\n";
			}

			else if (ticTacToe[playerNumRow][playerNumCol] == 'X' || ticTacToe[playerNumRow][playerNumCol] == 'O')
			{
				cout << "SPOT IS TAKEN OR ILLEGAL CHARACTER!\n";
			}
			else
			{
				ticTacToe[playerNumRow][playerNumCol] = 'O';
				if ((ticTacToe[0][0] == 'O' && ticTacToe[0][1] == 'O' && ticTacToe[0][2] == 'O') || (ticTacToe[1][0] == 'O' && ticTacToe[1][1] == 'O' && ticTacToe[1][2] == 'O') ||
					(ticTacToe[2][0] == 'O' && ticTacToe[2][1] == 'O' && ticTacToe[2][2] == 'O') || (ticTacToe[0][0] == 'O' && ticTacToe[1][1] == 'O' && ticTacToe[2][2] == 'O') ||
					(ticTacToe[2][0] == 'O' && ticTacToe[1][1] == 'O' && ticTacToe[0][2] == 'O'))
				{
					cout << playerTwoName << " WINS!\n";
					isGameOver = true;
				}
				turn++;
			}
			InitBoard();
		}
	}
}
