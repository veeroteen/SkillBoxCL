#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Tasks.h"
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
#define SPRING 0
#define SUMMER 0
#define AUTUMN 1
#define WINTER 0

void Task3() {
	time_t t = time(nullptr);
	tm local = *localtime(&t);
	cout << "Enter timer\n";
	int min, seconds;
	cin >> get_time(&local, "%M:%S");
	min = local.tm_min;
	seconds = local.tm_sec;
	t = seconds + (min * 60);
	time_t timerStart, timerEnd;
	timerStart = time(nullptr);
	timerEnd = time(nullptr);
	int temp = 0;
	while (t > timerEnd - timerStart) {
		timerEnd = time(nullptr);
		if (temp < timerEnd - timerStart) {
			temp = timerEnd - timerStart;
			local.tm_min = (t - temp) / 60;
			local.tm_sec = (t - temp) % 60;
			cout <<  put_time(&local, "%M:%S") << endl;
		}
	}

	cout << "DING! DING! DING!\n";
}
