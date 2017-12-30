#include "units.h"


Unit::Unit(PLAYER player) 
{
	_player = player;
	std::cout<<"Unit constructor\n";
}
bool Unit::move(Point s,Point e, Unit* b[][9] )
{
	return false;
}
// void Unit::testFun()
// {
// 	std::cout<<"HELLO! testFun";
// }

bool Unit::moveByStep(Point dir,Point s, Point e,Unit* b[][9], PLAYER _player)
{
	while (!(s==e))
	{
		s = s+dir;
		Unit *currentTile = b[s.x][s.y];
		if (currentTile!=nullptr)
		{
			//path blocked
			if (!(s==e)) return false;
			//else, at destination, check if friend of foe
			if (currentTile->getPlayer()==_player) return false;
			else
			{
				//kill enemy and move
				// delete currentTile;
				return true;
			}
		}
	}
	//empty path, empty destination
	return true;
}
