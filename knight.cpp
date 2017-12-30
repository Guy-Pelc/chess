#include "knight.h"


#include <cmath>
using std::abs;
using std::cout;

Knight::Knight(PLAYER player)
:Unit(player)
{
	std::cout<<"Knight constructor\n";
	_unix = playerToString(player) + unitToString(KNIGHT);
}
bool Knight::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.x==0 || dir.y==0) return false;

	if (abs(dir.x+dir.y)>3) return false;
	if (abs(dir.x/dir.y)==2 || abs(dir.y/dir.x)==2) return  moveByStep(dir,s,e,b,_player);
	
	return false;
	
	// return moveByStep
	// return moveByStep();
	
	
}