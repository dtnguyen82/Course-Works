#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>
#include "circle.h"
using namespace std;
class cylinder : public circle
{
private:
	double height;
public:
	cylinder();
	cylinder(int a, int b, double c, double d);
	~cylinder();
	double getHeight();
	double area();
	double volume();
};
#endif
