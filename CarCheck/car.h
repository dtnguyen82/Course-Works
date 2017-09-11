#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

struct ErrorList
{
	string errorCode;
	string errorMsg;
};

class car
{
private:
	string name;
	int errorSize;
	string *error;
	static int numOfCar;
	int count = 0;
public:
	car();
	~car();
	string getName();
	int getSize();
	string* getError();
	void setName(string newName);
	void setSize(int newSize);
	void setError(string newError, int index);
	void print(ErrorList *newList, int errorCount);
	static int printCount();
};
#endif