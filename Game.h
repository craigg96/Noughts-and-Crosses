#pragma once

#include "Board.h"

class Game

{
public:
	void StartGame();
	char state[9];
	void turn();
	int row_played;
	int column_played;
//	void amend_state();

private:

};
