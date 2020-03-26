
#include "Board.h"
#include "Game.h"
#include <iostream>
using namespace std;

Board board;

void Game::StartGame()
{
	board.SelectCharachters();
	Game::WhoseTurn = 1;
}


void Game::turn()
{
	cout << "Its player " << Game::WhoseTurn << "'s turn!" << endl;

	Game::InputPosition();
	
	Game::amend_state();

	board.DrawBoard(Game::state);

	 Game::scan_state(Game::state);

	if (GameOver == true) {
		return;
	}

	Game::SwitchTurn();

	Game::row_played = 0;
	Game::column_played = 0;


}



void Game::amend_state()
{

	if (Game::WhoseTurn == 1) { Game::state[Game::column_played - 1][Game::row_played - 1] = board.PlayerChar[0]; }
	
	if (Game::WhoseTurn == 2) { Game::state[Game::column_played - 1][Game::row_played - 1] = board.PlayerChar[1]; }

}

void Game::InputPosition()
{
		cout << "Enter the row where you wish to play your piece" << endl;
	while ((Game::row_played < 1) || (Game::row_played > 3))
	{
		cout << "Please enter a value between 1 and 3!";
		cin >> Game::row_played;
		if (!cin) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
		}
	}

	cout << "Enter the column where you wish to play your piece" << endl;

	while ((Game::column_played < 1) || (Game::column_played > 3))
	{
		cout << "Please enter a value between 1 and 3!";
		cin >> Game::column_played;
		if (!cin) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
		}

	}
}

void Game::SwitchTurn()
{
	bool switched = false;
	if (Game::WhoseTurn == 1) {
		Game::WhoseTurn = 2;
		Game::move_count[0]++;
		switched = true;
	}

	if ((Game::WhoseTurn == 2) && (switched == false)){
		Game::WhoseTurn = 1;
		Game::move_count[1]++;
	}	
}


void Game::scan_state(char state[3][3])
{
	cout << "Youve played " << Game::row_played << "," << Game::column_played << endl;

	
	
	if (Game::move_count[0]+Game::move_count[1] == 8) {
		Game::draw = true;
		Game::GameOver = true; }


	/*
	for (int i = 0; i < 3; i++) {
			if (state[0][i])
		return;

		//star operation
	//up

	*/


}