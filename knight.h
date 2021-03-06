#ifndef _KNIGHT
#define _KNIGHT

#include "units.h"
class Knight : public Unit
{
public:
	Knight *clone() override;
	Knight(PLAYER player);
	~Knight(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif