#pragma once
#include <iostream>
#include "Ram.h"
using namespace std;
void enter() {
	for (int i = 0; i < 8; i++) {
		cout << "Enter " << i + 1 << " number\n";
		int n;
		cin >> n;
		Ram::write(n, i);
	}
}