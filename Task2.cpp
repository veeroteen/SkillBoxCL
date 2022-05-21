#include <iostream>
#include <string>
#include "Tasks.h"
#include <map>

using namespace std;

void Task2(){
	map<string, int> registr;

	while (true) {
		cout << "Enter query\n";
		string str;
		cin >> str;
		
			if (str == "Next") {
				if (registr.size() != 0) {
					auto it = registr.begin();
					string tmp = it->first;
					cout << tmp << endl;
					it->second--;
					if (it->second == 0) {
						registr.erase(it);
					}
				}
			}
			else {
				if (registr[str] == 0)
				{
					registr[str] = 1;
				}
				else {
					registr[str]++;
				}
			}
	}
}
