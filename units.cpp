#include "units.h"

bool Unit::isExposed(Point expLocation, Unit *_board[][9])
{
		for (int row=1;row<=8;row++)
		{
			for (int col=1;col<=8;col++)
			{
				Unit *curUnit=_board[row][col];
				if (curUnit==nullptr) continue;
				else if (curUnit->getPlayer()==_player) continue;

				Point curLocation;
				curLocation.row = row;
				curLocation.col = col;
				if (curUnit->move(curLocation,expLocation,_board)==true) 
					{
						return true;
					}
			}
		}
		return false;
}

Unit::Unit(PLAYER player) 
{
	_player = player;
}

bool Unit::moveByStep(Point dir,Point s, Point e,Unit* b[][9], PLAYER _player)
{
	while (!(s==e))
	{
		s = s+dir;
		Unit *currentTile = b[s.row][s.col];
		if (currentTile!=nullptr)
		{
			//path blocked
			if (!(s==e)) return false;

			//else, at destination, check if friend of foe
			if (currentTile->getPlayer()==_player) return false;
			else
			{
				return true;
			}
		}
	}
	//empty path, empty destination
	return true;
}
