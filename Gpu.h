#pragma once
#include <iostream>
#include "Ram.h"
using namespace std;
void draw() {
	vector <int> arr = Ram::read();
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}