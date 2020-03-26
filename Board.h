#pragma once


class Board
{
public:
	
	char PlayerChar[2];
	char BoardInit[3][3] =  {' '};
	void SelectCharachters();
	
	void DrawBoard(char state[3][3]);
	char InputChar();


private:

};



