#include "knight.h"


#include <cmath>
using std::abs;
//using std::cout;

Knight *Knight::clone()
{
	Knight *copy = new Knight(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}
Knight::Knight(PLAYER player)
:Unit(player)
{
	// std::cout<<"Knight constructor\n";
	_unix = playerToString(player) + unitToString(KNIGHT);
}
bool Knight::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.row==0 || dir.col==0) return false;

	if (abs(dir.row+dir.col)>3) return false;
	if (abs(dir.row/dir.col)==2 || abs(dir.col/dir.row)==2) return  moveByStep(dir,s,e,b,_player);
	
	return false;
	
	// return moveByStep
	// return moveByStep();
	
	
}