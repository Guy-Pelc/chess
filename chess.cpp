#include <iostream>
#include "board.h"
#include <cmath>

using std::cout;
using std::string;
using std::abs;

int main()
{
	string CHECK_MSG = "\33[37;41mCheck!\33[0m\n";
	string ILLEGAL_MOVE_MSG = "\33[37;41millegal move\33[0m\n";
	Board b;

	std::string whiteName;
	std::string blackName;

	std::cout<<"Enter white player name:\n";
	std::cin>>whiteName;
	std::cout<<"Enter black player name:\n";
	std::cin>> blackName;

	bool whiteTurn = true;
	std::string input;
	std::cout<<"\33[2J";
	while (true) {

		PLAYER curPlayer = (whiteTurn) ? WHITE : BLACK;
		bool isCheck = b.isKingExposed(curPlayer);
		bool existsPossibleMove = b.existsPossibleMove(curPlayer);

		b.printBoard();
		if (isCheck && existsPossibleMove) std::cout << CHECK_MSG;
		else if (isCheck && !existsPossibleMove) {
			std::string winner = (whiteTurn) ? blackName : whiteName;
			std::cout << winner << " won!\n";
			return 0;
		} else if (!isCheck && !existsPossibleMove) {
			std::cout << "Tie, no winners!\n";
			return 0;
		}

		while (true) {
			std::string curName = (whiteTurn) ? whiteName : blackName;
			std::cout << curName << ": please enter your move:\n";
			std::cin >> input;
			if (b.moveUnit(input, whiteTurn)) break;
			else cout << ILLEGAL_MOVE_MSG;
			b.printBoard();
		}

		whiteTurn = !whiteTurn;
	}
}
