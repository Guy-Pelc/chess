#ifndef _BISHOP
#define _BISHOP

#include "units.h"
class Bishop : public Unit
{
public:
	Bishop *clone() override;
	Bishop(PLAYER player);
	~Bishop(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif