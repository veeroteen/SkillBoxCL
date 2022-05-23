#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;
#define SPRING 0
#define SUMMER 0
#define AUTUMN 1
#define WINTER 0

void Task3() {
#if SPRING || SUMMER || AUTUMN || WINTER

	if (SPRING) {
		cout << "SPRING\n";
	}
	else if (SUMMER) {
		cout << "SUMMER\n";
	}
	else if (AUTUMN){
		cout << "AUTUMN\n";
	}
	else if (WINTER) {
		cout << "WINTER\n";
	}
#endif
}
