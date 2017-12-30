#include "soldier.h"
using std::cout;

Soldier::Soldier(PLAYER player) 
:Unit(player)
{
	std::cout<<"Soldier constructor\n";
	_unix =playerToString(player) + unitToString(SOLDIER) ;
}
bool Soldier::move(Point s,Point e, Unit* b[][9])
{
	std::cout<<"here! s,e:"<<s<<e<<std::endl;
	int direction = (_player==WHITE) ? 1 : -1;
	//check if unit can move like that
	if (s.row + direction == e.row)
	{
		cout<<"here 17";
		//move (not eat), must not be any collision
		if ( s.col == e.col && b[e.row][e.col]==nullptr)
		{
			return true;
		}
		
		// eat, must be diagonal must contain enemy
		else if ((s.col == e.col+1) || (s.col == e.col-1))
		{
			cout<<"here 27";
			// std::cout<<"checking if can eat\n";
			Unit* toBeEaten = b[e.row][e.col];
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
	cout<<"here 39";
	return false;
}
