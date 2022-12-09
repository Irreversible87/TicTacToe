#include <iostream>
#include "GameBoard.h"

GameBoard::GameBoard()
{
	playerChoosenField = NULL;
	boardColumn = NULL;
	boardRow = NULL;
	turn = NULL;
	bIsDraw = false;
}

void GameBoard::setTurn(char symbol)
{
	turn = symbol;
}

char GameBoard::getTurn()
{
	return turn;
}

bool GameBoard::getDraw()
{
	return bIsDraw;
}

void GameBoard::renderGameBoard()
{
	for (int i = 0; i <= 2; i++)
	{
		std::cout << "\t\t     |     |     \n\t\t  ";
		for (int j = 0; j <= 2; j++)
		{
			if (j < 2)
				std::cout << gameBoard[i][j] << "  |  ";
			else
				std::cout << gameBoard[i][j];
		}
		std::cout << " \n";
		if (i < 2)
			std::cout << "\t\t_____|_____|_____\n";
		else
			std::cout << "\t\t     |     |     \n";
	}
}

void GameBoard::play(Player playerOne, Player playerTwo)
{
	if (turn == playerOne.getPlayerSymbol())
		playerChoosenField = playerOne.playerTurn();
	else
		playerChoosenField = playerTwo.playerTurn();

	switch (playerChoosenField)
	{
	case 1: boardRow = 0; boardColumn = 0; break;
	case 2: boardRow = 0; boardColumn = 1; break;
	case 3: boardRow = 0; boardColumn = 2; break;
	case 4: boardRow = 1; boardColumn = 0; break;
	case 5: boardRow = 1; boardColumn = 1; break;
	case 6: boardRow = 1; boardColumn = 2; break;
	case 7: boardRow = 2; boardColumn = 0; break;
	case 8: boardRow = 2; boardColumn = 1; break;
	case 9: boardRow = 2; boardColumn = 2; break;
	default:
		std::cout << "Please choose only between 1 and 9! \n";
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

	// Checking if game is a draw.
	bIsDraw = true;
	return true;
}

void GameBoard::updateGameBoard(Player playerOne, Player playerTwo)
{
	if (turn == playerOne.getPlayerSymbol() && gameBoard[boardRow][boardColumn] != 'X' && gameBoard[boardRow][boardColumn] != 'O')
	{
		gameBoard[boardRow][boardColumn] = playerOne.getPlayerSymbol();
		turn = playerTwo.getPlayerSymbol();
		renderGameBoard();
	}
	else if (turn == playerTwo.getPlayerSymbol() && gameBoard[boardRow][boardColumn] != 'X' && gameBoard[boardRow][boardColumn] != 'O')
	{
		gameBoard[boardRow][boardColumn] = playerTwo.getPlayerSymbol();
		turn = playerOne.getPlayerSymbol();
		renderGameBoard();
	}
	else
	{
		std::cout << "Box is already taken. Choose another one!" << std::endl;
		play(playerOne, playerTwo);
	}
}
