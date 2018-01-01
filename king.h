#ifndef _KING
#define _KING

#include "units.h"
class King : public Unit
{
public:
	King(PLAYER player);
	~King(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
	bool isKing() override {return true;};
	King *clone() override;
};

#endif