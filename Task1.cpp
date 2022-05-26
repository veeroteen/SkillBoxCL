#include <iostream>
#include "Tasks.h"
#include <ctime>
#include <string>
#include <vector>
using namespace std;
struct Quest {
	int64_t time;
	string name;
};



void Task1(){

	vector <Quest> arr;
	int64_t timer = time(nullptr);
	bool status = false;

	while (true) {
		cout << "Enter command\n";
		string str;
		cin >> str;
		if (str == "begin") {
			if (status) {
				arr[arr.size() - 1].time = time(nullptr) - timer;
				status = false;
			}
			status = true;
			timer = time(nullptr);
			cout << "Enter quest name\n";
			cin >> str;
			arr.push_back(Quest{ 0,str });
		}
		else if(str == "end") {
			arr[arr.size() - 1].time = time(nullptr) - timer;
			status = false;
		}
		else if (str == "status") {
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i].time > 0) {
					str = to_string(arr[i].time / 3600) + ':' +  to_string((arr[i].time % 3600 )/ 60);
				}
				else {
					str = "";
				}
					
				cout << arr[i].name << " " << str << endl;
				
			}
		}
		else if (str == "exit") {
			break;
		}
	}
	
}

