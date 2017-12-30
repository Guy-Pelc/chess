#ifndef _QUEEN
#define _QUEEN

#include "units.h"
// #include "point.h"
class Queen : public Unit 
{
public:
	Queen(PLAYER player);
	~Queen(){std::cout<<"Queen destructor\n";};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif