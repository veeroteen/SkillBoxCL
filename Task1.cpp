#include <iostream>
#include "Tasks.h"
using namespace std;
#define January 1
#define February 2
#define March 3
#define April 4
#define May 5
#define June 6
#define July 7
#define August 8
#define September 9
#define October 10
#define November 11
#define December 12

void Task1(){
	cout << "Enter month number\n";
	int a;
	cin >> a;
	switch (a)
	{
	case January:
		cout << "January\n";
		break;
	case February:
		cout << "February\n";
		break;
	case March:
		cout << "March\n";
		break;
	case April:
		cout << "April\n";
		break;
	case May:
		cout << "May\n";
		break;
	case June:
		cout << "June\n";
		break;
	case August:
		cout << "August\n";
		break;
	case September:
		cout << "September\n";
		break;
	case October:
		cout << "October\n";
		break;
	case November:
		cout << "November\n";
		break;
	case December:
		cout << "December\n";
		break;
	}
}

