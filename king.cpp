#include "king.h"


#include <cmath>
using std::abs;
using std::cout;

King::King(PLAYER player)
:Unit(player)
{
	// std::cout<<"King constructor\n";
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
		cout<<"possible hatsraha...\n";

		//if moving left:
		//normalize dir vec
		dir.col = dir.col/abs(dir.col);

		if (b[s.row][s.col+dir.col]!= nullptr)return false;
		if (b[e.row][e.col]!= nullptr) return false;
		//if moving reight check G col
		Unit *possibleRook= b[s.row][1];
		if (dir.col>0) 
		{
			possibleRook = b[s.row][8];
			if (b[s.row][7]!=nullptr)return false;
		}
		//check rook exists and hasnt moved yet.
		if (possibleRook==nullptr) return false;				
		if (possibleRook->getHasMoved()) return false;
		// check king is not exposed
		cout<<"still need to check not exposed...\n";
		return false;

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