//1410
//Program 9
//student: Duc Nguyen
//TA: Shengrong Yin
//Date: 04/14/2016

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_EMPLOYEE = 100; //Maximum number of employee in the company

struct employee //Define Struct and its member
{
	string firstName; 
	string lastName;
	double salary;
	int ID;
};

class company
{
public:
	void insert(int id, string fname, string lname, double salary); //Fill up the array with the information from the file
	void search(int idinput); //Overload search
	void init(); //Initialize the array to empty
	void search(string input);//Overloading
	void print(); //Print out the employee list
	company();
private:
	employee employeeList[MAX_EMPLOYEE]; //Structure of arrays
	int numOfEmploy;
};

void company::init()
{
	for(int i = 0; i < MAX_EMPLOYEE; i++)
	{
		employeeList[i].firstName = "First Name"; //Initialize the structure arrays
		employeeList[i].ID = 0;
		employeeList[i].lastName = "Last Name";
		employeeList[i].salary = 0;
	}
}

void company::insert(int id, string fname, string lname, double salary)
{
	employeeList[numOfEmploy].firstName = fname; //Fill up the array with the file info
	employeeList[numOfEmploy].lastName = lname;
	employeeList[numOfEmploy].ID = id;
	employeeList[numOfEmploy].salary = salary;
	numOfEmploy++; //Increment each time it loops
}

void company::print()
{
	cout << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "ID" << setw(15) << "Salary" << endl << endl;
	for (int i =0; i < numOfEmploy; i++) 
	{
		cout.setf(ios::right);//Set the output to the right
		if(employeeList[i].firstName != "First Name") //Limit the printing to only printing whatever was filled up in the array and not the initializing values
		cout << setw(15) << employeeList[i].firstName << setw(15) << employeeList[i].lastName << setw(15) << employeeList[i].ID << setw(15) << employeeList[i].salary << endl;
	}
}

void company::search(string input)
{
	int count = 100;
	for (int i =0; i < 100; i++)
	{
		if(employeeList[i].lastName == input ) //Search for the last name and print it out if the "string" is equal to the input, output every employee with that last name
			cout << setw(3) << "Name: " << employeeList[i].firstName << " " << employeeList[i].lastName << setw(4) << ", ID: " << employeeList[i].ID << setw(6) << ", Salary: " << employeeList[i].salary << endl;
		else
			count--; //Decrement the max number of employee everytime it cannot find the name in the search
	}
	if (count ==0) //If count equal 0 that means there are no employee with that last name
		cout << input << " Not Found" << endl;
}

void company::search(int idinput)
{
	int count = 100;
	for (int i =0; i < 100; i++)
	{
		if(employeeList[i].ID == idinput )//Search for the ID, if the ID is the same as the idinput then print out the person with the same ID
			cout << setw(3) << "Name: " << employeeList[i].firstName << " " << employeeList[i].lastName << setw(4) << ", ID: " << employeeList[i].ID << setw(6) << ", Salary: " << employeeList[i].salary << endl;
		else
			count--;//Decrement each time it search and cannot find the ID
	}
	if (count ==0)//Print out if it finish searching and there was no ID inputted in the system
		cout << idinput << " Not Found" << endl;
}

company::company()//Constructure to see the value of the private member to 0 so it can be increment
{
	numOfEmploy = 0;
}

employee emp;
company comp;

void readIn(company& comp)//Read the called in file and take the information from the files to work with the program
{
	string fname, lname;
	int id;
	double salary;
	comp.init(); // initialize the array to empty
	ifstream myfile ("prog9in.txt"); //Open the file
	if (myfile.is_open())
	{
	 	myfile >> id >> fname >> lname >> salary; //Get the info from file
	 	while (! myfile.eof()) //End if file reach the end
		{ 
	 		comp.insert(id, fname, lname, salary);// Fill the array with info from file
	 		myfile >> id >> fname >>lname >> salary;
	 	}
		myfile.close(); //Close the file
	}
 	else cout << "Unable to open file";
}

int main()
{
	string input;
	int idinput;
	int choice;
	cout.setf(ios::fixed|ios::showpoint);//Set salary to have 2 digits decimals
	cout.precision(2);
	while(choice != 4) //Loop the whole program and end if it is 4
	{
		readIn(comp); //Call the read in file
		cout << "   Select your option: " << endl; //Give choices to user
		cout << "1. Search employee by last name" << endl;
		cout << "2. Search employee by ID" << endl;
		cout << "3. Print list of all employees" << endl;
		cout << "4. Exit" << endl;
		cout << "-> ";
		cin >> choice; //Get input
		if (choice == 1) //Do the search for last name
		{
			cout << "Enter the employee's last name: " << endl;
			cout << "-> ";
			cin >> input;
			comp.search(input);
			cout << endl << "-------------------------------------------" << endl << endl;
		}
		else if(choice == 2) //Search for ID
		{
			cout << "Enter the employee's ID: " << endl;
			cout << "-> ";
			cin >> idinput;
			comp.search(idinput);
			cout << endl << "-------------------------------------------" << endl << endl;
		}
		else if (choice == 3) //Print the employee list
		{
			comp.print();
			cout << endl << "-------------------------------------------" << endl << endl;
		}
		else if(choice > 4 || choice < 0) //Limit the choices to between 1-4
		{
			cout << "Invalid Choice" << endl;
		}
	}
}
