#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
#include "Tasks.h"
#include "Compute.h"
using namespace std;


void Task2() {
	while (true) {
		cout << "Enter command\n";
		string str;
		cin >> str;
		if (str == "sum") {
			compute(Ram::read());
		}
		else if (str == "load") {
			load(Ram::read());
		}
		else if (str == "save") {
			save(Ram::read());
		}
		else if (str == "input") {
			enter();
		}
		else if (str == "display") {
			draw();
		}
		else if (str == "exit") {
			break;
		}
	}








}
