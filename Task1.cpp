#include <iostream>
#include "Tasks.h"
using namespace std;
#define Monday cout << "Monday\n";
#define Tuesday cout << "Tuesday\n";
#define Wednesday cout << "Wednesday\n";
#define Thursday cout << "Thursday\n";
#define Friday cout << "Friday\n";
#define Saturday cout << "Saturday\n";
#define Sunday cout << "Sunday\n";

void Task1(){
	cout << "Enter month number\n";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
		Monday;
		break;
	case 2:
		Tuesday;
		break;
	case 3:
		Wednesday;
		break;
	case 4:
		Thursday;
		break;
	case 5:
		Friday;
		break;
	case 6:
		Saturday;
		break;
	case 7:
		Sunday;
		break;
	}
}

