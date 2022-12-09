#include <iostream>
#include "Player.h"

int main()
{
	GameBoard gameBoard;
	Player playerOne('X');
	Player playerTwo('O');

	gameBoard.setTurn(playerOne.getPlayerSymbol());
	
	std::cout << std::endl;
	std::cout << "\t\t***********TicTacToe***********\n" << std::endl;
	std::cout << "\t\tPlayer 1: X | Player 2: O\n" << std::endl;

	gameBoard.renderGameBoard();

	while (!gameBoard.gameOver())
	{
		gameBoard.play(playerOne, playerTwo);
	}

	if (gameBoard.getTurn() == 'O' && gameBoard.getDraw() == false)
		std::cout << "\n\n Congrats. Player 1 has won!";
	else if (gameBoard.getTurn() == 'X' && gameBoard.getDraw() == false)
		std::cout << "\n\n Congrats. Player 2 has won!";
	else
		std::cout << "\n\n That is a Draw!";

	return 0;
}

