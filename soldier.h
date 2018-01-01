#ifndef _SOLDIER
#define _SOLDIER

#include "units.h"

class Soldier : public Unit 
{
public:
	Soldier(PLAYER player);
	~Soldier(){};
	bool move(Point s,Point e, Unit* b[][9]) override;
	Soldier *clone() override;
	bool isPawn() override {return true;};
};

#endif