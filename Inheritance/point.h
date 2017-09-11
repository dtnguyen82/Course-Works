#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class point {
private:
	int x;
	int y;
public:
	point();
	point(int a, int b);
	~point();
	int getX();
	int getY();
	virtual double area() =0;
};
#endif
