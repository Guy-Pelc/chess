#include "queen.h"


#include <cmath>
using std::abs;
using std::cout;

Queen::Queen(PLAYER player)
:Unit(player)
{
	std::cout<<"Queen constructor\n";
	_unix = playerToString(player) + unitToString(QUEEN);
}
bool Queen::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.x==0 && dir.y==0) return false;

	if (dir.x!=0)
	dir.x = dir.x/abs(dir.x);
	if (dir.y!=0)
	dir.y = dir.y/abs(dir.y);

	if (abs(dir.x*dir.y)==1 || abs(dir.x*dir.y)==0) 
		return  moveByStep(dir,s,e,b,_player);
	return false;
	
	// return moveByStep
	// return moveByStep();
	
	
}