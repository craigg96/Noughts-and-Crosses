#pragma once

#include "Board.h"

class Game

{
public:
	void StartGame();
	char state[3][3];
	void turn();
	int row_played = 0;
	int column_played = 0;
	void amend_state();
	int WhoseTurn;
	void SwitchTurn();
	void InputPosition();
	bool GameOver = false;


private:

};
