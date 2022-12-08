#include <iostream>
#include "Player.h"

using namespace std;

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
	cout << "Choose your field (1-9): ";
	cin >> playerChoice;
	return playerChoice;
}


