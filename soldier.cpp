#include "soldier.h"

Soldier::Soldier(PLAYER player) 
:Unit(player)
{
	_unix =playerToString(player) + unitToString(SOLDIER) ;
}
bool Soldier::move(Point s,Point e, Unit* b[][9])
{
	Point dir = e-s;
	int playerRowDir = (_player==WHITE) ? 1 : -1;

	//check that soldier goes in right direction
	if (dir.row*playerRowDir<=0) 
		{
			return false; 
		}

	//if soldier moves, not eats
	if (dir.col==0)
	{
		//check if first tile in direction is clear
		if (b[s.row+playerRowDir][s.col]!=nullptr) return false;
		if (abs(dir.row)==1) return true;
		// else, soldier needs to move more than 1 tile.
		//if soldier has moved or requested to move more than 2 return false
		if (_hasMoved || abs(dir.row)>2) return false;
		//check 2nd tile is empty
		if (b[e.row][e.col]!=nullptr) return false;
		return true;
	}

	//if soldier eats, not moves.
	if (abs(dir.col)==1)
	{
		//check advances only 1 row
		if (abs(dir.row)!=1)return false;
		//check tile not empty
		Unit *toBeEaten = b[e.row][e.col];
		if (toBeEaten==nullptr) return false;
		
		//check tile contains enemy
		if (toBeEaten->getPlayer()==_player) return false;
		return true;
	}

	return false;
}
Soldier *Soldier::clone()
{
	Soldier *copy = new Soldier(_player);
	copy->_hasMoved = _hasMoved;
	return copy;
}
