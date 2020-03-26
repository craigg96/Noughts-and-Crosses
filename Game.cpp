#include "Game.h"
#include "Board.h"
#include <iostream>
using namespace std;

Board gameboard;

void Game::StartGame()
{
	gameboard.SelectCharachters();
	Game::WhoseTurn = 1;
}


void Game::turn()
{
	cout << "Its player " << Game::WhoseTurn << "'s turn!" << endl;

	Game::InputPosition();
	
	Game::amend_state();

	gameboard.DrawBoard(Game::state);

	Game::SwitchTurn();

	Game::row_played = 0;
	Game::column_played = 0;

}



void Game::amend_state()
{


	if (Game::WhoseTurn == 1) { Game::state[Game::column_played - 1][Game::row_played - 1] = gameboard.PlayerChar[0]; }
	
	if (Game::WhoseTurn == 2) { Game::state[Game::column_played - 1][Game::row_played - 1] = gameboard.PlayerChar[1]; }

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
		cout << "Switch Turn" << endl;
		switched = true;
	}

	if ((Game::WhoseTurn == 2) && (switched == false)){
		Game::WhoseTurn = 1;
		cout << "Switch Turn" << endl;

	}
}


