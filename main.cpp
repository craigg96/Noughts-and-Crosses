#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

// Declare Objects
Board board;
Game Game1;

int main() {
	cout << "Welcome to naughts and crosses!" << endl;

	board.DrawBoard(board.BoardInit);


	Game1.StartGame();	
	
	while (Game1.GameOver == false) {
		Game1.turn();
	}


	cout << "press enter to quit" << endl;
	cin.get();


}