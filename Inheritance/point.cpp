#include <iostream>
#include "point.h"
using namespace std;

point::point()
{
	x = 0;
	y = 0;
}
point::point(int a, int b)
{
	x = a;
	y = b;
}
point::~point()
{}
int point::getX()
{
	return x;
}
int point::getY()
{
	return y;
}

