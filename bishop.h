#ifndef _BISHOP
#define _BISHOP

#include "units.h"
// #include "point.h"
class Bishop : public Unit 
{
public:
	Bishop(PLAYER player);
	~Bishop(){std::cout<<"Bishop destructor\n";};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif