#include "units.h"


bool Unit::isExposed(Point expLocation, Unit *_board[][9])
{
	// cout<<"king location: "<<kingLocation<<endl;
		// PLAYER attackingPlayer = (player==WHITE) ? BLACK : WHITE;
		for (int row=1;row<=8;row++)
		{
			for (int col=1;col<=8;col++)
			{
				Unit *curUnit=_board[row][col];
				if (curUnit==nullptr) continue;
				else if (curUnit->getPlayer()==_player) continue;
				// if (curUnit->getPlayer==player) continue;
				
				Point curLocation;
				curLocation.row = row;
				curLocation.col = col;
				if (curUnit->move(curLocation,expLocation,_board)==true) 
					{

						std::cout<<"EXPOSED! location of offender:"<<curLocation<<std::endl;
						return true;
					}
			}
		}
		// cout<<"king not exposed\n";
		return false;
}

Unit::Unit(PLAYER player) 
{
	_player = player;
	// std::cout<<"Unit constructor\n";
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
		// std::cout<<"HERE 22 UNITS.CPP";
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
				//kill enemy and move
				// delete currentTile;
				return true;
			}
		}
	}
	//empty path, empty destination
	return true;
}
