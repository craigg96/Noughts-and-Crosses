#pragma once


class Game

{
public:
	void StartGame();

	char state[3][3];
	void scan_state(char state[3][3]);
	void amend_state();


	int row_played = 0;
	int column_played = 0;

	void turn();
	int WhoseTurn;

	void SwitchTurn();
	void InputPosition();

	bool GameOver = false;
	int move_count[2] = {1};
	bool draw = false;

private:

};
