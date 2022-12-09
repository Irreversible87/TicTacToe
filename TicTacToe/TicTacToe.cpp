#include <iostream>
#include "Player.h"

int main()
{
	GameBoard gameBoard;
	Player playerOne('X');
	Player playerTwo('O');

	gameBoard.setTurn(playerOne.getPlayerSymbol());

	gameBoard.renderGameBoard();
	
	std::cout << std::endl;

	while (!gameBoard.gameOver())
	{
		gameBoard.makeMove(playerOne, playerTwo);
	}

	return 0;
}

