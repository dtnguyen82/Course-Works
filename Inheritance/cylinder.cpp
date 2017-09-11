#include "cylinder.h"
#include "circle.h"
#include "point.h"
#include <iostream>
using namespace std;
cylinder::cylinder()
{
	height = 0;
}
cylinder::cylinder(int a, int b, double c, double d) : circle(a,b,c) 
{
	height = d;
}
cylinder::~cylinder()
{}
double cylinder::getHeight()
{
	return height;
}

double cylinder::area()
{
	double temp2;
	temp2 = circle::area();
	temp2 = temp2 * 2 + (2 * radius*height*3.14);
	return temp2;
}
double cylinder::volume()
{
	double temp;
	temp = 3.14 * radius * radius * height;
	return temp;
}