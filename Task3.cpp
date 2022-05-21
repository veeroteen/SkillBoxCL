#include <iostream>
#include <string>
#include "Tasks.h"
#include <math.h>
using namespace std;

void Task3(){
	string first, second;
	cout << "Enter firs word\n";
	cin >> first;
	cout << "Enter second word\n";
	cin >> second;

	if (first.length() == second.length()) {
		for (int n = 0; n < first.length(); n++) {
			
			if (first[0] == second[n]) {
				first.erase(0, 1);
				second.erase(n, 1);
				n = -1;
			}
			if (first.length() == 0) {
				cout << "Yes\n";
				break;
			}
		}
		if (first.length() > 0) {
			cout << "No\n";
		}
		
	}
	else {
		cout << "No\n";
	}



}
