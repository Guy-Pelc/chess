#ifndef _BOARD
#define _BOARD

#include <string>
#include "units.h"
#include "point.h"


using std::string;

class Board
{
	Unit* _board[9][9];
public:
	Board();
	void resetBoard();
	void printBoard();
	bool moveUnit(Point s,Point e, bool whiteTurn);
	bool moveUnit(std::string str, bool whiteTurn);
	Unit* getUnitAt(Point p) {return _board[p.x][p.y];};

	void eatAt(Point e);
};
#endif