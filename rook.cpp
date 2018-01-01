#include "rook.h"
#include <cmath>
using std::abs;

Rook::Rook(PLAYER player)
:Unit(player)
{
	_unix = playerToString(player) + unitToString(ROOK);
}
bool Rook::move(Point s, Point e, Unit* b[][9])
{

	Point dir = e-s;

	if (dir.row==0 && dir.col==0) return false;
	else if (dir.row!=0 && dir.col!=0) return false;

	//normalize dir vec
	if (dir.row!=0) dir.row = dir.row/abs(dir.row);
	else dir.col= dir.col/abs(dir.col);

	return moveByStep(dir,s,e,b,_player);

}
Rook *Rook::clone()
{
	Rook *copy = new Rook(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}