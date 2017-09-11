#include "circle.h"
#include <iostream>
using namespace std;
circle::circle()
{
	radius = 0;
}
circle::circle(int a, int b, double c) : point(a,b)
{
	radius = c;
}
circle::~circle()
{}
double circle::getRadius()
{
	return radius;
}
double circle::area()
{
	double temp;
	temp = 3.14 * radius*radius;
	return temp;
}