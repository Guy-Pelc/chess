#ifndef _SOLDIER
#define _SOLDIER

#include "units.h"

class Soldier : public Unit 
{
public:
	Soldier(PLAYER player);
	~Soldier(){std::cout<<"Soldier destructor\n";};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif