#ifndef _BOARD
#define _BOARD

#include <string>
#include "units.h"
#include "point.h"


using std::string;

class Board
{
	Unit* _board[9][9];  // [ROW][COL]
public:
	Board();
	void resetBoard();
	void printBoard();
	bool moveUnit(Point s,Point e, bool whiteTurn);
	bool moveUnit(std::string str, bool whiteTurn);
	Unit* getUnitAt(Point p) {return _board[p.row][p.col];};
	bool isKingExposed(PLAYER player);
	void eatAt(Point e);
};
#endif