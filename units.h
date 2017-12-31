#ifndef _UNITS
#define _UNITS

#include "unix.h"
#include "point.h"

#include <iostream>
#include <string>

class Unit
{
public:
	// static void testFun();
	// Unit() ;
	Unit(PLAYER player);
	virtual ~Unit(){};
	// virtual ~Unit(){std::cout<<"Unit destructor\n";} ;
	bool isExposed(Point expLocation, Unit *_board[][9]);

	virtual bool move(Point s,Point e, Unit* b[][9])=0;
	static bool moveByStep(Point dir,Point s, Point e,Unit* b[][9], PLAYER _player);
		
	virtual bool isKing(){return false;};
	virtual bool isPawn(){return false;};
	std::string getUnix() {return _unix;};
	PLAYER getPlayer() {return _player;};
	bool setHasMoved(){_hasMoved=true;};
	bool getHasMoved(){return _hasMoved;};
	virtual Unit *clone()=0;

protected:
	bool _hasMoved = false;
	std::string _unix;
	PLAYER _player;
};


#endif