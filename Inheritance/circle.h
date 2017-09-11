#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point.h"
using namespace std;
class circle : public point
{
protected:
	double radius;
public:
	circle();
	circle(int a, int b, double c);
	~circle();
	double getRadius();
	double area();
};
#endif