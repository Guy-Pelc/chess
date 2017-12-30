#include "soldier.h"


Soldier::Soldier(PLAYER player) 
:Unit(player)
{
	std::cout<<"Soldier constructor\n";
	_unix =playerToString(player) + unitToString(SOLDIER) ;
}
bool Soldier::move(Point s,Point e, Unit* b[][9])
{
	int direction = (_player==WHITE) ? 1 : -1;
	//check if unit can move like that
	if (s.x + direction == e.x)
	{
		//move (not eat), must not be any collision
		if ( s.y == e.y && b[e.x][e.y]==nullptr)
		{
			return true;
		}
		// eat, must be diagonal must contain enemy
		else if ((s.y == e.y+1) || (s.y == e.y-1))
		{
			// std::cout<<"checking if can eat\n";
			Unit* toBeEaten = b[e.x][e.y];
			if (toBeEaten!=nullptr && toBeEaten->getPlayer()!=_player)
			{
				//eat player
				// delete toBeEaten;
				// toBeEaten = nullptr;
				// (toBeEaten == nullptr) ? std::cout<<"Deleted\n":std::cout<<"Exists\n";
				return true;
			}
		}
	}
	return false;
}
