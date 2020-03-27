
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
	cout << "Player " << Game::WhoseTurn << "'s turn." << endl;

	Game::InputPosition();
	
	Game::amend_state();

	board.DrawBoard(Game::state);

	cout << "Youve played " << Game::row_played << "," << Game::column_played << endl << endl;

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

	if (Game::WhoseTurn == 1) { Game::state[Game::row_played - 1][Game::column_played - 1] = board.PlayerChar[0]; }
	
	if (Game::WhoseTurn == 2) { Game::state[Game::row_played - 1][Game::column_played - 1] = board.PlayerChar[1]; }

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

	if ((Game::state[Game::row_played - 1][Game::column_played - 1] == board.PlayerChar[0])||(Game::state[Game::row_played - 1][Game::column_played - 1] == board.PlayerChar[1])) {
		cout << endl << "Sorry that space is taken." << endl << endl;
		Game::row_played = Game::column_played = 0;
		Game::InputPosition();
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

	int col = 0;
	int row = 0;
	int diag = 0;
	int rdiag = 0;

	for (int i = 0; i < 3; i++) {

		if (state[Game::row_played-1][i] == board.PlayerChar[Game::WhoseTurn - 1]) {
			col++;
			//cout << "col = " << col << endl;
		}

		if (state[i][Game::column_played-1] == board.PlayerChar[Game::WhoseTurn - 1]) {
			row++;
			//cout << "row = " << row << endl;

		}

		if (state[i][i] == board.PlayerChar[Game::WhoseTurn - 1]) {
			diag++;
			//cout << "diag = " << diag << endl;

		}

		if (state[i][2 - i] == board.PlayerChar[Game::WhoseTurn - 1]) {
			rdiag++;
			//cout << "rdiag = " << rdiag << endl;

		}

		if ((row == 3) || (col == 3) || (diag == 3) || (rdiag == 3)) {
			Game::GameOver = true;
			return;
		}

	}
	
	col = 0;
	row = 0;
	diag = 0;
	rdiag = 0;

	if ((Game::move_count[0]+Game::move_count[1] == 8)&&(Game::GameOver == false)) {
		Game::draw = true;
		Game::GameOver = true; }




}