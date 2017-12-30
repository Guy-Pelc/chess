#include "bishop.h"


#include <cmath>
using std::abs;
using std::cout;

Bishop::Bishop(PLAYER player)
:Unit(player)
{
	std::cout<<"Bishop constructor\n";
	_unix = playerToString(player) + unitToString(BISHOP);
}
bool Bishop::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	if (dir.x==0 || dir.y==0) return false;
	dir.x = dir.x/abs(dir.x);
	dir.y = dir.y/abs(dir.y);
	if (abs(dir.x*dir.y)!=1) return false;
	
	// return moveByStep
	// return moveByStep();
	return moveByStep(dir,s,e,b,_player);
	
	
}