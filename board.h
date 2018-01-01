#ifndef _BOARD
#define _BOARD

#include <string>
#include "units.h"
#include "point.h"


using std::string;

class Board
{
	Unit* _board[9][9];  // [ROW][COL]

	Point whiteKingLoc;
	Point blackKingLoc;
public:
	Board();
	Board(Point wKing, Point bKing, Unit* b[9][9]);
	~Board();

	bool existsPossibleMove(PLAYER player);
	void printBoard();
	bool moveUnit(Point s,Point e,bool whiteTurn);
	bool moveUnitHelper(Point s,Point e, bool whiteTurn);
	bool moveUnit(std::string str, bool whiteTurn);
	bool isKingExposed(PLAYER player);
	void eatAt(Point e);
};
#endif