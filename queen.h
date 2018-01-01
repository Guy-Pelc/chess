#ifndef _QUEEN
#define _QUEEN

#include "units.h"
class Queen : public Unit
{
public:
	Queen(PLAYER player);
	~Queen(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
	Queen *clone() override;
};

#endif