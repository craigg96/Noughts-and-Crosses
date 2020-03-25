#pragma once

class Board
{
public:
	
	char PlayerChar[2];
	char BoardInit[9] =  {' '};
	void SelectCharachters();
	
	void DrawBoard(char state[9]);
	char InputChar();

private:

};



