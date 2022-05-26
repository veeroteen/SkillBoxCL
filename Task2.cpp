#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Tasks.h"
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
struct Born {
	string name;
	tm date;
};

void Task2() {
	vector <Born> arr;
	time_t t = time(nullptr);
	tm local = *localtime(&t);
	while (true) {
		string str;
		cout << "Enter name\n";
		cin >> str;
		if (str == "end") {
			break;
		}
		cout << "Enter date Y/M/D\n";
		cin >> get_time(&local, "%Y/%m/%d");
		arr.push_back(Born{ str,local });
	}
	vector <Born> min;
	t = time(nullptr);
	local = *localtime(&t);
	if (arr.size() > 0) {
		min.push_back(arr[0]);
	}
	for (int i = 1; i < arr.size(); i++) {
		if ((min[0].date.tm_mon < arr[i].date.tm_mon) && (arr[i].date.tm_mon > local.tm_mon)) {
			min.clear();
			min.push_back(arr[i]);
		}
		else if ((min[0].date.tm_mon == arr[i].date.tm_mon && min[0].date.tm_mday > arr[i].date.tm_mday) && (arr[i].date.tm_mday > local.tm_mday))
		{
			min.clear();
			min.push_back(arr[i]);
		}
		else if (min[0].date.tm_mon == arr[i].date.tm_mon && min[0].date.tm_mday == arr[i].date.tm_mday) {
			min.push_back(arr[i]);
		}
	}

	for (int i = 0; i < min.size(); i++) {
		if (local.tm_mon == min[i].date.tm_mon && local.tm_mday == min[i].date.tm_mday)
		{
			cout << "Today is " << min[i].name << " birthday\n";
		}
		else {
			cout << min[i].name << " has a birthday in " << put_time(&min[i].date, "%m/%d") << endl;
		}
	}



}
