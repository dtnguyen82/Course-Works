//1410
//Program 10
//student: Duc Nguyen
//TA: Shengrong Yin
//Date: 04/25/2016

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct student //Define Structure
{
	string firstName; 
	string lastName;
	double grade[3];
	int ID;
	double average;
};

class StudentList //Define class
{
public:
	void insert(int ID, string firstName, string lastName, double grade[]); //Store the file information
	void average(); //Get the average of scores
	void sort(); //Sort the average in a descending order
	void print(char* argv[]); //Print out the sorted list
private:
	student studList[100]; //Structure array
	int NumOfStu;
};

void StudentList::insert(int ID, string firstName, string lastName, double grade[])
{
	studList[NumOfStu].firstName = firstName; //Initialize the structure arrays
	studList[NumOfStu].ID = ID;
	studList[NumOfStu].lastName = lastName;
	for(int i = 0; i < 3; i++) { //In order to save 3 grades integer, use a loop for to store 
		studList[NumOfStu].grade[i] = grade[i];
	}
	NumOfStu++; //Count how many students that were stored in the array
	
}
void StudentList::average()
{
	for(int i = 0; i < NumOfStu; i++) //Nested for loops because there are 2 arrays being used
	{
		for (int j = 0; j < 3; j++)
		{
			studList[i].average += (studList[i].grade[j])/3; //Get the sum of the grade and divide it by total amount of grades
		}
	}
}

void StudentList::sort()
{
	student temp;
	for(int i =0; i < NumOfStu - 1; i++) //Sorting function
	{
		for(int j = i + 1; j < NumOfStu; j++)
		{
			if(studList[i].average < studList[j].average) //Compare the average
			{
				temp = studList[i]; //Temp is a temporary holder
				studList[i] = studList[j];
				studList[j] = temp;
			}
		}	
	}
}

void StudentList::print(char* argv[])
{
	ofstream outfile (argv[2]); //Passing the argument into the printing function
	char letter;
	for (int i =0; i < NumOfStu; i++) 
	{
		if(studList[i].average >= 89.50) //Finding the letter grade and round it up if it .50 and up
			letter = 'A';
		else if(studList[i].average >= 79.50)
			letter = 'B';
		else if(studList[i].average >= 69.50)
			letter = 'C';
		else if(studList[i].average >= 59.50)
			letter = 'D';
		else
			letter = 'F';
		
		cout.setf(ios::right);//Set the output to the right
		cout << studList[i].ID << setw(10) << studList[i].firstName << setw(10) << studList[i].lastName << "    "; //Print out the list
		for (int j = 0; j < 3; j++)
		{
			cout << setw(8) << studList[i].grade[j];
		}
		cout << setw(11) << studList[i].average << setw(8) << letter << endl;
		outfile << studList[i].ID << setw(10) << studList[i].firstName << setw(10) << studList[i].lastName << "   "; //Pass the infomation into the output file and print it out there
		for (int x = 0; x < 3; x++)
		{
			outfile << setw(7) << std::fixed << std::setprecision(2) << studList[i].grade[x]; //Set the numbers to have two decimals digits in the output file
		}
		outfile << setw(8) << studList[i].average << setw(8) << letter << endl;
	}
	outfile.close();
}

StudentList list;
student info;

void readIn(StudentList& list, char *argv[])//Read the called in file and take the information from the files to work with the program
{
	ifstream myfile (argv[1]); //Argument #1
	string firstName, lastName;
	int ID;
	double grade[3]; //3 is the max size of the grade
	if (myfile.is_open())
	{
		myfile >> ID >> firstName >> lastName; //Read in the file
		for(int i = 0; i < 3; i++)
		{
			myfile >> grade[i];
		}
		while (! myfile.eof()) //Loop the storing and read in the file line by line until it is the end of the file
		{
			list.insert(ID, firstName, lastName, grade);
			myfile >> ID >> firstName >> lastName;
			for(int i = 0; i < 3; i++)
			{
				myfile >> grade[i];
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

int main(int argc, char *argv[]) //Arguments
{
	cout.setf(ios::fixed|ios::showpoint);//Set salary to have 2 digits decimals
	cout.precision(2);
	readIn(list, argv);	
	list.average();
	list.sort();
	list.print(argv);
}
