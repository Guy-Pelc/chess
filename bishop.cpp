#include "bishop.h"
#include <cmath>
using std::abs;

Bishop *Bishop::clone()
{
	Bishop *copy = new Bishop(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}

Bishop::Bishop(PLAYER player)
:Unit(player)
{
	_unix = playerToString(player) + unitToString(BISHOP);
}

bool Bishop::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	if (dir.row==0 || dir.col==0) return false;
	dir.row = dir.row/abs(dir.row);
	dir.col = dir.col/abs(dir.col);
	if (abs(dir.row*dir.col)!=1) return false;
	return moveByStep(dir,s,e,b,_player);
}