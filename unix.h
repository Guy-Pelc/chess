#ifndef _UNIX
#define _UNIX

#include <string>

enum PLAYER
{
	WHITE=0,
	BLACK,
};

enum unitUNIX
{
SOLDIER,
ROOK,
BISHOP,
QUEEN,
KNIGHT,
KING,
};

std::string playerToString(PLAYER player);
std::string unitToString(unitUNIX unit);

std::ostream& operator<<(std::ostream& os, unitUNIX unit);

#endif