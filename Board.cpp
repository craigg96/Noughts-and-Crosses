#include <iostream>

#include "Board.h"
#include "Game.h"
using namespace std;


void Board::SelectCharachters()
{
	cout << "Player 1";
	Board::PlayerChar[0] = Board::InputChar();
	cout << "Youve chosen " << PlayerChar[0] << endl;
	
	cout << "Player 2";
	Board::PlayerChar[1] = Board::InputChar();
	cout << "Youve chosen " << PlayerChar[1] << endl;

}

void Board::DrawBoard(char state[3][3])
{
	cout << "-------------" << endl;
	cout << "| " << state[0][0] << " | " << state[1][0] << " | " << state[2][0] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << state[0][1] << " | " << state[1][1] << " | " << state[2][1] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << state[0][2] << " | " << state[1][2] << " | " << state[2][2] << " |" << endl;
	cout << "-------------" << endl;

}

char Board::InputChar()
{
	char character;
	
	cout << " please press the charachter you wish to play as!" << endl;

	cin >> character;

	return character;
}


