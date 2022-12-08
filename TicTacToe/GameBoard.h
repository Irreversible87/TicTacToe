#pragma once

#include "Player.h"

class Player;

class GameBoard
{
public:
	GameBoard();
	void setTurn(char symbol);
	void renderGameBoard();
	void makeTurn(Player playerOne, Player playerTwo);
	bool gameOver();

private:
	char gameBoard[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	char turn;
	int row, column, choice;
	
	void updateGameBoard(Player playerOne, Player playerTwo);
};

