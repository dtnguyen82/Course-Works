#include <iostream>
#include <stdio.h>
#include <time.h>
#include <tchar.h>
#include <windows.h>
#include <limits.h>
using namespace std;
int main() {
	int Bytes = 0;
	int Page = 0;
	int Virtual = 0;
	MEMORYSTATUS MemoryInfo;
	GlobalMemoryStatus(&MemoryInfo);
	Bytes = MemoryInfo.dwAvailPhys;
	Page = MemoryInfo.dwAvailPageFile;
	Virtual = MemoryInfo.dwAvailVirtual;
	cout << "dwAvailPhys: " << MemoryInfo.dwAvailPhys << endl;
	cout << "dwAvailPageFile: " << MemoryInfo.dwAvailPageFile << endl;
	cout << "dwAvailVirtual: " << MemoryInfo.dwAvailVirtual << endl;
	double testValues[] = { 0.5,0.6,0.7,0.8,0.9,0.95,0.99,1.,1.01,1.1,1.5,2.,5.,10.,50. };
	int numberofNewBytes;
	int *arrayOfIntegers;
	for (int i = 0; i < 15; i++) {
		cout << endl << "Value tested: " << testValues[i] << endl;
		clock_t start = clock();
		numberofNewBytes = (int)(testValues[i] * (Bytes));
		arrayOfIntegers = new int[((numberofNewBytes) / sizeof(int))];
		GlobalMemoryStatus(&MemoryInfo);
		cout << "dwAvailPhys: " << MemoryInfo.dwAvailPhys << endl;
		cout << "dwAvailPageFile: " << MemoryInfo.dwAvailPageFile << endl;
		cout << "dwAvailVirtual: " << MemoryInfo.dwAvailVirtual << endl;
		for (int x = 0; x < numberofNewBytes / sizeof(int); x++) {
			arrayOfIntegers[x] = 1;
		}
		for (int x = 0; x < numberofNewBytes / sizeof(int); x++) {
			arrayOfIntegers[x] = arrayOfIntegers[x] + 1;
		}
		cout << "Time it took: " << ((((double)clock() - start)) / CLOCKS_PER_SEC) << " seconds" << endl;
	}
	delete[] arrayOfIntegers;
	system("pause");
	return 0;
	}
