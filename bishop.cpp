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
	if (dir.row==0 || dir.col==0) return false;
	dir.row = dir.row/abs(dir.row);
	dir.col = dir.col/abs(dir.col);
	if (abs(dir.row*dir.col)!=1) return false;
	
	// return moveByStep
	// return moveByStep();
	return moveByStep(dir,s,e,b,_player);
	
	
}