#ifndef _KING
#define _KING

#include "units.h"
// #include "point.h"
class King : public Unit 
{
public:
	King(PLAYER player);
	// ~King(){std::cout<<"King destructor\n";};
	~King(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
	bool isKing() override {return true;};
	King *clone() override;
	
};

#endif