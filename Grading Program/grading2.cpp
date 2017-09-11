//1410
//Program 6
//student: Duc Nguyen
//TA: Shengrong Yin
//Date: 03/21/2016

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

const int N = 100; //Constant integer
int getScore(int N); //Function prototype
void getScores(int array[], int N);
void getStat(int array[], int N, double(& mean), int(& max));
int computeLetterGrade(int array[], int N);
void curveGrades(int array[], int N, double (&mean), int (&max));
int computeCurveGrade(int curve[], int N);

int main()
{
	int s[N], max; 
	double mean = 0; 
	for( int i = 0; i < N; ++i) //Generate random number
	{
		s[i] = getScore(N);
	}
	getScores(s, N); //Fill up 100 numbers
	getStat(s, N, mean, max); //Calculate mean, deviation, lowest and highest score, and also letter grade
	curveGrades(s,N, mean, max); //Calculations of the curved grades
	return 0;
}

int getScore(int N)
{
	int random;
	random = (rand() % 100+1);
	return random;
}
 
void getScores(int array[], int N)
 {
	srand(time(NULL));
 	int number;
 	for (int i = 0; i < N; i++)
 	{
 		number = i % 10; //Separate random numbers into different variety of ranges
		switch(number)
		{
		case 1: case 7:	array[i] = (rand() % 100+1); //20% of number between 1-100
		cout << "s[" << i << "]" << " = " << array[i] << endl;
		break;
		case 3: case 6: case 8:	array[i] = (rand() % (50+1) +40); //30% of number between 40-90
		cout << "s[" << i << "]" << " = " << array[i] << endl;
		break;
		default: array[i] = (rand() % (20+1) + 60); //50% between 60-80
		cout << "s[" << i << "]"<< " = " << array[i] << endl; 
		break;
		}
	}
	cout << endl;
 }

void getStat(int array[], int N, double(& mean), int(& max))
{
	cout << fixed << showpoint;  
	cout << setprecision (2) ; 
	double sum = array[0], sum2 = 0, deviation = 0;
	for (int i = 1; i < N; ++i) //Compute Average
	{
		sum += array[i];
	}
	mean = sum/N;
	cout << "Mean is " <<  mean << endl;

	for (int x = 0; x < N; x++) //Computer Deviation
	{
		sum2 += pow((array[x]-mean),2);
	}
	deviation = sqrt(sum2/N);
	cout << "Deviation is " << deviation << endl;
	
	int min = 0;
	min = max = array[0];
	for (int y = 0; y < N ; y++) // Lowest and Highest Grade
	{
		if (array[y] < min)
			min = array[y];
		else if (array[y] > max)
			max = array[y];
	}
	cout << "Lowest Grade is " << min << endl;
	cout << "Highest Grade is " << max << endl;
	cout << endl;
	computeLetterGrade(array, N); //Count the letter grades

}
int computeLetterGrade(int array[], int N)
{
	int A= 0, B= 0, C = 0, D = 0, F = 0;
	for(int i = 0; i < N; i++)
	{
		if(array[i] >= 90 && array[i] <= 100) //If grade between 90-100, A count + 1
			A++;
		else if(array[i] >= 80 && array[i] <= 89) //Grade between 80-89, B count + 1
			B++;
		else if(array[i] >= 70 && array[i] <= 79) //Grade between 70-79, C count + 1
			C++;
		else if(array[i] >= 60 && array[i] <= 69) // Grade between 60-69, D count + 1
			D++;
		else //Grade below 60 , F count + 1
			F++;
	}
	cout << "There were a total of " << A << " A's, " << B << " B's, " << C << " C's, " << D << " D's, " << F << " F's, " <<endl;
	cout << endl;
}
void curveGrades(int array[], int N, double (&mean), int (&max))
{
	int curve[N];
	double mean2 = 0, deviation2 = 0, difference = max - mean;
	int min2 = 0, max2 = 0;
	for(int i = 0 ;i < N  ; ++i) //Find the curve grade 
	{
		curve[i] = ((( array[i] -  mean) / (difference)) * 25) + 75 ; //Change value in array and store it in another array
		cout << array[i] << " => " << curve[i]  << endl;
	}
	cout << endl;
	cout << "After the curve: " << endl;
	cout << endl;
	cout << fixed << showpoint;  
	cout << setprecision (2) ; 
	double sum3 = curve[0], sum4 = 0;
	for (int i = 1; i < N; i++) //Average of curve grade
	{
		sum3 += curve[i];
	}
	mean2 = sum3/N;
	cout << "Mean is " <<  mean2 << endl;
	for (int x = 0; x < N; x++) //Deviation of curve grade
	{
		sum4 += pow((curve[x]-mean2),2);
	}
	deviation2 = sqrt(sum4/N);
	cout << "Deviation is " << deviation2 << endl;
	
	min2 = max2 = curve[0];
	for (int y = 0; y < N ; y++) //Highest and lowest grade of new number
	{
		if (curve[y] < min2)
			min2 = curve[y];
		else if (curve[y] > max2)
			max2 = curve[y];
	}
	cout << "Lowest Grade is " << min2 << endl;
	cout << "Highest Grade is " << max2 << endl;
	cout << endl;
	computeCurveGrade(curve, N); //Letter grade of curved grade
}

int computeCurveGrade(int curve[], int N)
{
	int A= 0, B= 0, C = 0, D = 0, F = 0;
	for(int i = 0; i < N; i++)
	{
		if(curve[i] >= 90 && curve[i] <= 100)
			A++;
		else if(curve[i] >= 80 && curve[i] <= 89)
			B++;
		else if(curve[i] >= 70 && curve[i] <= 79)
			C++;
		else if(curve[i] >= 60 && curve[i] <= 69)
			D++;
		else
			F++;
	}
	cout << "There were a total of " << A << " A's, " << B << " B's, " << C << " C's, " << D << " D's, " << F << " F's, " <<endl;
	cout << endl;
}
