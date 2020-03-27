#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

// Declare Objects
Board board_;
Game game;

int main() {
	cout << "Welcome to naughts and crosses!" << endl;

	board_.DrawBoard(board_.BoardInit);

	game.StartGame();	
	
	while (game.GameOver == false) {
		game.turn();
	}
	
	cout << "Game Over" << endl;

	if (game.draw == true) {
		cout << "It's a draw!" << endl;
	}
	else
	{
		cout << "Player " << game.WhoseTurn << " won in " << game.move_count[game.WhoseTurn -1] << " moves." <<  endl;

	}

	cout << "press enter to quit" << endl;
	cin.get();


}