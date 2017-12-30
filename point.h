#ifndef _POINT
#define _POINT

#include <iostream>

typedef struct {
int col; //was x
int row; //was y


} Point;

Point operator+(Point a, Point b);
Point operator-(Point a, Point b);
bool  operator==(Point a, Point b);
std::ostream& operator<<(std::ostream& os, Point p);

#endif