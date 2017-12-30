#include "point.h"

Point operator+(Point a, Point b){return {a.col+b.col,a.row+b.row};}

Point operator-(Point a, Point b){return {a.col-b.col,a.row-b.row};}

bool  operator==(Point a, Point b){return a.row==b.row && a.col==b.col;}
std::ostream& operator<<(std::ostream& os, Point p)
{
	os<<"(col:"<<p.col<<",row:"<<p.row<<")";
}

