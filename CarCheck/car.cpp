#include "car.h"
#include <iostream>
#include <string>
using namespace std;
int car::numOfCar = 0;
car::car()
{
	name = "none";
	errorSize = 0;
	numOfCar++;
}

car::~car()
{
	delete[] error;
	numOfCar--;
}
string car::getName()
{
	return name;
}
int car::getSize()
{
	return errorSize;
}
string * car::getError()
{
	return error;
}
void car::setName(string newName)
{
	name = newName;
}
void car::setSize(int newSize)
{
	errorSize = newSize;
	error = new string[errorSize];//Get size then create dynamic array for error
}
void car::setError(string newError, int index) //index get increase each time this function is call
{
	error[index] = newError; //set code to array of error
}
void car::print(ErrorList *newList, int errorCount)
{
	cout << "Car Name: " << name << endl;
	for (int i = 0; i < errorSize; i++) {
		try {
			if (stoi(error[i]) == 0) //Convert string back to int
				throw 0;
			if (stoi(error[i]) != 0)
				throw stoi(error[i]); //If not 0 then throw the error and print out the message
		}
		catch (int e)
		{
			if (e == 0) //Catch 0 since there are no errors
				cout << "Car is in good shape" << endl;
			else
			{
				cout << "Error " << i + 1 << ": ";
				for (int a = 0; a < errorCount; a++) {
					if (stoi(error[i]) == stoi(newList[a].errorCode))//Convert string back to int
						cout << newList[a].errorMsg << endl; //If error in the car is equal to error code then print the
						//error code message
				}
			}
		}
	}
	cout << endl;
}
int car::printCount()
{
	return numOfCar -1;
}