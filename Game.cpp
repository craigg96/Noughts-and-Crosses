#include "Game.h"
#include "Board.h"
#include <iostream>
using namespace std;

Board gameboard;

void Game::StartGame()
{
	gameboard.SelectCharachters();

}

void Game::turn()
{
	
	cout << "Enter the row where you wish to play your piece" << endl;
	cin >> Game::row_played;

	
	cout << "Enter the row where you wish to play your piece" << endl;
	cin >> Game::column_played;
	


}


