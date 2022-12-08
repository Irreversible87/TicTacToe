#include <iostream>
#include "Main.h"

using namespace std;

int main()
{
	GameBoard gameBoard;
	Player playerOne('X');
	Player playerTwo('O');

	gameBoard.setTurn(playerOne.getPlayerSymbol());

	gameBoard.renderGameBoard();
	
	cout << endl;

	while (!gameBoard.gameOver())
	{
		gameBoard.makeTurn(playerOne, playerTwo);
	}

	return 0;
}

