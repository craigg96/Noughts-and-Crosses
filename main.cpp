#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

// Declare Objects
Board board;
Game Game1;

int main() {
	cout << "Welcome to naughts and crosses!" << endl;
	
	Game1.StartGame();

	board.DrawBoard(board.BoardInit);


	cout << "press enter to continue" << endl;
	cin.get();


}