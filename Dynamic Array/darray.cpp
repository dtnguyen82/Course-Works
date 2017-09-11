
#include <iostream>

using namespace std;

class dynArray //Class Definition
{
	public:
		dynArray(); //Constructor
		void showArray(); //Show array
		void addElem(); //Add element
		void removeElem(); //Remove element
		void CallIn(); //Use after menu to choose which function to run
	private:
		void doubleSize(); //Double size of array when it is filled
		void halfSize(); //Half the size when element size is 1/4 of array size
		int menu(); //Display choices
		int *a; //Pointer
		int arraySize; 
		int elemSize;	
};

dynArray::dynArray() //Set values to the variables in private class
{	
	arraySize = 2; //Intialize array size to 2
	elemSize = 0; //Initialize element size to 0
	a = new int[arraySize]; //Dynamic array
}

void dynArray::showArray()
{
	for(int i = 0; i < elemSize; i++) //Print out the current value stored
	{
		cout << "Array[" << i << "]= " << a[i] << endl;
	}
	cout << endl << "Physical Array Size = " << arraySize << endl; // Print out current array size
	cout << "Number of Elements = " << elemSize << endl << endl; //Print out current element size
}

void dynArray::addElem()
{
	if(elemSize <= arraySize -1 ) //Check if the element size is less than array size, the -1 make sure it will double before add if the element size = to array size
	{
		a[elemSize] = elemSize + 1;// Add one to the array
		elemSize++;//Increment
	}
	else
	{
		doubleSize();//Double size of array
		a[elemSize] = elemSize + 1; //Add after double
		elemSize++;
	}
}
		
void dynArray::removeElem()
{
	if(elemSize-1 <= arraySize/4) //Half the array size if the element size is 1/4 of array size before removing
	{
		halfSize();
		elemSize--;
	}
	else //Subtract one from array list
	{
		elemSize--;
	}
	if(elemSize < 0 || arraySize < 2) //Limit the array size and element size to its initial value, cannot go under those value
	{
		elemSize =0;
		arraySize =2;
		cout << endl << "Nothing to remove" << endl;
		cout << "No element left in this array" << endl;
	}
}

void dynArray::CallIn()// After getting the input choice, do the following options
{
	do
	{
		int input = menu(); //Call in the input choice
		switch(input)
		{
		case 1: //If it is 1 then add and show current array
		addElem();
		showArray();
		break;
		case 2: //If it is 2 then remove and show current array
		removeElem();
		showArray();
		break;
		case 3: //Show current array
		showArray();
		break;
		case 4: //Print out quitting and quit the program
		cout << "Quitting...." << endl;
		exit(0);
		break;
		default: //If it is not any of the choice, display error message and ask for input again
		cout << endl;
		cout << "Please enter a valid choice." << endl << endl;
		}
	}
	while(true); //If exit is true then quit loop		
}

void dynArray::doubleSize()
{
	int *list; //New pointer+
	list = new int[arraySize*2]; //New dynamic array
	for(int i = 0; i < arraySize; i++) //Transfer value from old array to new array
	{
		list[i] = a[i];
	}
	delete []a; //Delete old array
	a = list; //Pointer point to new array
	arraySize *= 2;//Double the array size
	cout << "***Array size doubled to " << arraySize << endl;
}

void dynArray::halfSize()
{
	int *list; //New pointer
	list = new int [arraySize/2]; //New dynamic array that is half of old array
	for(int i = 0; i < arraySize/4; i++) //Transfer value from old array to new array
	{	
		list[i] = a[i];
	}
	delete []a; //Delete old array
	a = list; //Old pointer point to new array
	arraySize /= 2; //Divide array size by 2
	if(arraySize >= 2) //Only print out if the array size is more than 2
		cout << "***Array size reduced to " << arraySize << endl;
}
	
int dynArray::menu()
{
	int input; //Give choices and ask for user input
	cout << "1. Add Element" << endl;
	cout << "2. Remove Element" << endl;
	cout << "3. Show Array" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter choice:";
	cin >> input;
	return input;
}

int main ()
{
	dynArray a;
	a.CallIn(); //Call in the function
} 
