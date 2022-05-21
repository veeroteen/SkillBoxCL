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

					while (tmp[tmp.length() - 1] - 48 <= 9 && tmp[tmp.length() - 1] - 48 >= 0)
					{
						tmp.erase(tmp.length() - 1);
					}
					cout << tmp << endl;
					while (true) {
						string hh;
						if (it != registr.end()) {
							hh = (it)->first.substr(0, tmp.length());
						}
						else {
							hh = "";
						}
						if (hh != tmp)
						{
							it--;
							registr.erase(it);
							break;
						}
						it++;
					}
				}
			}
			else {
				int i = 0;
				while (true) {

					if (registr[str + to_string(i)] == 0)
					{
						registr[str + to_string(i)] = 1;
						break;
					}
					i++;
				}

			}

		
	}




}
