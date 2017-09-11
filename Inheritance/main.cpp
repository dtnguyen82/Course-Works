//Duc Nguyen
//1338383

#include <iostream>
#include <iomanip>
#include "point.h"
#include "circle.h"
#include "cylinder.h"
using namespace std;

int main()
{
	circle c1(9, 11, 12.66);
	cylinder cyl1(40, 50, 17.45, 14.23);
	double cArea, cylArea, cylVolume;
	cArea = c1.area();
	cout << "The area of the circle is " << fixed << setprecision(2) << cArea << endl;
	cylArea = cyl1.area();
	cout << "The area of the cylinder is " << fixed << setprecision(2) << cylArea << endl;
	cylVolume = cyl1.volume();
	cout << "The volume of the cylinder is " << fixed << setprecision(2) << cylVolume << endl;
	cin.get();
	return 0;
}