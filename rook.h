#ifndef _ROOK
#define _ROOK

#include "units.h"
class Rook : public Unit
{
public:
	Rook(PLAYER player);
	~Rook(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
	Rook *clone() override;
};

#endif