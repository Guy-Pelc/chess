#include "unix.h"
#include <string>

std::string playerToString(PLAYER player)
{
	switch(player)
	{
		case (WHITE): return "\33[37m";
		case (BLACK):return "\33[30m";
		default: return "ERROR";
	}
}

std::string unitToString(unitUNIX unit)
{
	switch (unit)
	{
		// case (EMPTY): return " ";
		case (SOLDIER): return "\u265F";
		case (ROOK): return "\u265C";
		case (BISHOP): return "\u265D";
		case (QUEEN): return "\u265B";
		case (KNIGHT): return "\u265E";
		case (KING): return "\u265A";
		default: return "ERROR";
	}
}

std::ostream& operator<<(std::ostream& os, const unitUNIX unit)
{
	// return os<<"HELLO TEST";
	return os<<unitToString(unit);
}