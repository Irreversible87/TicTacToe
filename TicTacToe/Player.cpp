#include <iostream>
#include "Player.h"

Player::Player(char symbol)
{
	playerChoice = NULL;
	playerSymbol = symbol;
}

char Player::getPlayerSymbol()
{
	return playerSymbol;
}

int Player::playerTurn()
{
	std::cout << "Choose your field (1-9): ";
	std::cin >> playerChoice;
	return playerChoice;
}


