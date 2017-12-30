#include "point.h"

Point operator+(Point a, Point b){return {a.x+b.x,a.y+b.y};}

Point operator-(Point a, Point b){return {a.x-b.x,a.y-b.y};}

bool  operator==(Point a, Point b){return a.x==b.x && a.y==b.y;}
std::ostream& operator<<(std::ostream& os, Point p)
{
	os<<"("<<p.x<<","<<p.y<<")";
}

