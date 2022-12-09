#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard()
{
	choice = NULL;
	column = NULL;
	row = NULL;
	turn = NULL;
}

void GameBoard::setTurn(char symbol)
{
	turn = symbol;
}

void GameBoard::renderGameBoard()
{
	for (int i = 0; i <= 2; i++)
	{
		cout << "\t\t     |     |     \n\t\t  ";
		for (int j = 0; j <= 2; j++)
		{
			if (j < 2)
				cout << gameBoard[i][j] << "  |  ";
			else
				cout << gameBoard[i][j];
		}
		cout << " \n";
		if (i < 2)
			cout << "\t\t_____|_____|_____\n";
		else
			cout << "\t\t     |     |     \n";
	}
}

void GameBoard::makeMove(Player playerOne, Player playerTwo)
{
	if (turn == playerOne.getPlayerSymbol())
		choice = playerOne.playerTurn();
	else
		choice = playerTwo.playerTurn();

	switch (choice)
	{
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "Please choose only between 1 and 9!";
	}
	updateGameBoard(playerOne, playerTwo);
}

bool GameBoard::gameOver()
{
	for (int i = 0; i < 3; i++)
	{
		// checking for row or column win.
		if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2] 
			|| gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
		{
			return true;
		}
	}
	// checking for win in the diagonal.
	if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] 
		|| gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
	{
		return true;
	}

	// checking if the game is still in progress.
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
				return false;
}

// Der hier macht nicht was er soll
void GameBoard::updateGameBoard(Player playerOne, Player playerTwo)
{
	if (turn == playerOne.getPlayerSymbol() && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
	{
		gameBoard[row][column] = playerOne.getPlayerSymbol();
		turn = playerTwo.getPlayerSymbol();
	}
	else if (turn == playerTwo.getPlayerSymbol() && gameBoard[row][column] != 'X' && gameBoard[row][column] != 'O')
	{
		gameBoard[row][column] = playerTwo.getPlayerSymbol();
		turn = playerOne.getPlayerSymbol();
	}
	else
	{
		cout << "Box is already taken. Choose another one!" << endl;
		if (turn == playerOne.getPlayerSymbol())
			playerOne.playerTurn();
		else if (turn == playerTwo.getPlayerSymbol())
			playerTwo.playerTurn();
	}
	renderGameBoard();
}
