#include <iostream>
#include "Player.h"

Player::Player(char playerSymbol)
{
	choosenField = NULL;
	this->playerSymbol = playerSymbol;
}

char Player::getPlayerSymbol()
{
	return playerSymbol;
}

int Player::playerTurn()
{
	std::cout << "Your Turn Player " << getPlayerSymbol() << std::endl;
	std::cout << "Choose your field (1-9): ";
	std::cin >> choosenField;

	return 	choosenField;
}