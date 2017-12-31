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
	~Board();
	// {
	// 	for (int row=0; row<9;row++)
	// 	{
	// 		for (int col=0;col<9;col++)
	// 		{
	// 			if (_board[row][col]!=nullptr)
	// 				delete _board[row][col];
	// 		}
	// 	}
	// };
	Board(Point wKing, Point bKing, Unit* b[9][9]);
	void resetBoard();
	void printBoard();
	bool moveUnit(Point s,Point e, bool whiteTurn);
	bool moveUnit(std::string str, bool whiteTurn);
	Unit* getUnitAt(Point p) {return _board[p.row][p.col];};
	bool isKingExposed(PLAYER player);
	void eatAt(Point e);
};
#endif