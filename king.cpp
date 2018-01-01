#include "king.h"
#include "point.h"
#include <cmath>
using std::abs;


King::King(PLAYER player)
:Unit(player)
{
	_unix = playerToString(player) + unitToString(KING);
}
bool King::move(Point s, Point e, Unit* b[][9])
{
	Point dir = e-s;
	//assert not same place
	if (dir.row==0 && dir.col==0) return false;

	//check for hatsraha:
	if (dir.row==0 && 
		abs(dir.col)==2 &&
		!_hasMoved)
	{
		//normalize dir vec
		dir.col = dir.col/abs(dir.col);

		if (b[s.row][s.col+dir.col]!= nullptr)return false;
		if (b[e.row][e.col]!= nullptr) return false;

		//if moving right check G col
		Unit *possibleRook= b[s.row][1];
		if (dir.col>0) 
		{
			possibleRook = b[s.row][8];
			if (b[s.row][7]!=nullptr)return false;
		}

		//check rook exists and hasn't moved yet.
		if (possibleRook==nullptr) return false;				
		if (possibleRook->getHasMoved()) return false;

		// check king is not exposed
		if (isExposed(s,b)) return false;

		//check for intermediate tile
		Unit *king = b[s.row][s.col];
		b[s.row][s.col] = nullptr;
		s.col+=dir.col;
		b[s.row][s.col] = king;

		if (isExposed(s,b)) return false;

		//check for last tile
		b[s.row][s.col] = nullptr;
		s.col+=dir.col;
		b[s.row][s.col] = king;
		if (isExposed(e,b)) return false;

		//reset king to original tile
		b[s.row][s.col] = nullptr;
		s.col-=2*dir.col;
		b[s.row][s.col] = king;
		return true;
	}
		

		

	


	if (abs(dir.row)>1 || abs(dir.col)>1) return false;

	return  moveByStep(dir,s,e,b,_player);
	
	
	// return moveByStep
	// return moveByStep();	
}
King *King::clone()
{
	King *copy = new King(_player);
		copy->_hasMoved = _hasMoved;
			return copy;

}