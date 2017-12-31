#include "rook.h"

#include <cmath>
using std::abs;

using std::cout;
using std::endl;

Rook::Rook(PLAYER player)
:Unit(player)
{
	// std::cout<<"Rook constructor\n";
	_unix = playerToString(player) + unitToString(ROOK);
}
bool Rook::move(Point s, Point e, Unit* b[][9])
{

	Point dir = e-s;

	cout<<"dir: "<<dir<<endl;
	if (dir.row==0 && dir.col==0) return false;
	else if (dir.row!=0 && dir.col!=0) return false;
	
	cout<<"here 21";
	if (dir.row!=0) dir.row = dir.row/abs(dir.row);
	else dir.col= dir.col/abs(dir.col);
	cout<<"dir: "<<dir<<endl;
	return moveByStep(dir,s,e,b,_player);
	// while (!(s==e))
	// {
	// 	s = s+dir;
	// 	Unit *currentTile = b[s.x][s.y];
	// 	if (currentTile!=nullptr)
	// 	{
	// 		//path blocked
	// 		if (!(s==e)) return false;
	// 		//else, at destination, check if friend of foe
	// 		if (currentTile->getPlayer()==_player) return false;
	// 		else
	// 		{
	// 			//kill enemy and move
	// 			delete currentTile;
	// 			return true;
	// 		}
	// 	}
	// }
	// //empty path, empty destination
	// return true;
}
Rook *Rook::clone()
{
	Rook *copy = new Rook(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}