#pragma once

#include "GameBoard.h"

class Player
{
public:
	Player(char symbol);

	char getPlayerSymbol();
	int playerTurn();

private:
	int playerChoice;
	char playerSymbol;
};

