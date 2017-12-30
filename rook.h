#ifndef _ROOK
#define _ROOK

#include "units.h"
// #include "point.h"
class Rook : public Unit 
{
public:
	Rook(PLAYER player);
	~Rook(){std::cout<<"Rook destructor\n";};
	bool move(Point s,Point e, Unit* b[][9]) override;
};

#endif