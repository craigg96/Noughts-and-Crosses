#include <iostream>
#include "Board.h"
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

void Board::DrawBoard(char state[9])
{
	cout << endl;
	cout << "| " << state[0] << " | " << state[1] << " | " << state[2] << " |" << endl;
	cout << "| " << state[3] << " | " << state[4] << " | " << state[5] << " |" << endl;
	cout << "| " << state[6] << " | " << state[7] << " | " << state[7] << " |" << endl;

}

char Board::InputChar()
{
	char character;
	
	cout << " please press the charachter you wish to play as!" << endl;

	cin >> character;

	return character;
}
