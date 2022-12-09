#include <iostream>
#include "Player.h"

int main()
{
	GameBoard gameBoard;
	Player playerX('X');
	Player playerO('O');

	gameBoard.setTurn(playerX.getPlayerSymbol());
	
	std::cout << std::endl;
	std::cout << "\t\t***********TicTacToe***********\n\n\n" << std::endl;

	gameBoard.renderGameBoard();

	while (!gameBoard.gameOver())
	{
		gameBoard.play(playerX, playerO);
	}

	if (gameBoard.getTurn() == 'O' && gameBoard.getDraw() == false)
		std::cout << "\n\n Congrats. Player X has won!";
	else if (gameBoard.getTurn() == 'X' && gameBoard.getDraw() == false)
		std::cout << "\n\n Congrats. Player O has won!";
	else
		std::cout << "\n\n That is a Draw!";

	return 0;
}