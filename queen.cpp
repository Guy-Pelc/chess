#include "queen.h"
#include <cmath>
using std::abs;

Queen *Queen::clone()
{
	Queen *copy = new Queen(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}
Queen::Queen(PLAYER player)
:Unit(player)
{
	_unix = playerToString(player) + unitToString(QUEEN);
}
bool Queen::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.row==0 && dir.col==0) return false;

	//normalize dir vec
	if (dir.row!=0)
		dir.row = dir.row/abs(dir.row);
	if (dir.col!=0)
		dir.col = dir.col/abs(dir.col);

	if (abs(dir.row*dir.col)==1 || abs(dir.row*dir.col)==0) 
		return  moveByStep(dir,s,e,b,_player);
	else
		return false;
}