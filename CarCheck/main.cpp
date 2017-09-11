//Duc Nguyen
//1338383

#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
using namespace std;

int main()
{
	fstream errorFile;
	fstream carFile;
	ErrorList *List;
	car *CarList;
	carFile.open("Cars.txt", ios::in);
	errorFile.open("detailReport.txt", ios::in);
	string temp;
	int errorCount = 0;
	while (!errorFile.eof()) { //Count the amount of errors in the file
		getline(errorFile, temp); //+1 to count after each line
		errorCount++;
	}	
	errorFile.close();
	errorFile.open("detailReport.txt", ios::in);

	List = new ErrorList[errorCount]; //Create an dynamic array to save the errors
	int i = 0;
	while(!errorFile.eof())	{ //Save it to the struct
		getline(errorFile, temp);
		List[i].errorCode = temp.substr(0, 1); 
		List[i].errorMsg = temp.substr(2, temp.length() - 2);
		i++;
	}
	int j = 0;
	string a;
	int carCount = 0;
	while (!carFile.eof()) //Count the amount of cars
	{
		getline(carFile, a);
		carCount++;
	}
	carFile.close();
	carFile.open("Cars.txt", ios::in);
	CarList = new car[carCount]; //Create an dynamic array to save the cars and initialize how many spaces needed for the cars
	while (!carFile.eof()) 
	{
		int count = 0;
		getline(carFile, a);
		for (size_t i = 0; i < a.length(); i++) //Split the string by a space
		{
			if (a.substr(i, 1) != " ")
				count++;
			else
				break;
		}
		CarList[j].setName(a.substr(0, count)); //Set the first element in the string to as name
		CarList[j].setSize((a.length() - count) / 2); //Find how many error code for a car
		for (size_t i = 0; i < (a.length() - count) / 2; i++)
		{
			CarList[j].setError(a.substr(count + 1 + 2 * i, 1), i);  //Set the splitted error code in the array of error
		}
		j++;
	}
	for (int i = 0; i < carCount-1; i++)
	{
		CarList[i].print(List, errorCount); //Print
	}
	cout << "Numer of Cars = " << car::printCount() << endl; //Print # of cars
	errorFile.close();
	carFile.close();
	delete[] CarList;
	delete[] List;
	system("pause");
	return 0;
}