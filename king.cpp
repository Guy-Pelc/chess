#include "king.h"


#include <cmath>
using std::abs;
using std::cout;

King::King(PLAYER player)
:Unit(player)
{
	// std::cout<<"King constructor\n";
	_unix = playerToString(player) + unitToString(KING);
}
bool King::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.row==0 && dir.col==0) return false;

	if (abs(dir.row)>1 || abs(dir.col)>1) return false;

	return  moveByStep(dir,s,e,b,_player);
	
	
	// return moveByStep
	// return moveByStep();	
}
King *King::clone()
{
	King *copy = new King(_player);
		copy->_hasMoved = _hasMoved;
			return copy;

}