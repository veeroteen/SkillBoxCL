#include <iostream>
#include <string>
#include "Tasks.h"
#include <vector>
#include <thread>
#include <map>
#include <chrono>
#include <mutex>
using namespace std;

mutex acces2;

struct Train {
	char name;
	int time;
};

void travel(int t , char *train){
	while (t != 0) {
		this_thread::sleep_for(chrono::seconds(1));
		t--;
	}
	if (!acces2.try_lock()) {
		cout << "Train " << *train << " waiting for free space\n";
		acces2.lock();
	}
	cout << "Train " << *train << " has arrived\n";
	string tmp;
	cin >> tmp;
	cout << "Train " << *train << " depart\n";
	acces2.unlock();
}
void Task2() {
	vector <Train> trains;
	int tmp;
	cout << "Enter travel time for A\n";
	cin >> tmp;
	trains.push_back(Train{ 'A', tmp });
	cout << "Enter travel time for B\n";
	cin >> tmp;
	trains.push_back(Train{ 'B', tmp });
	cout << "Enter travel time for C\n";
	cin >> tmp;
	trains.push_back(Train{ 'C', tmp });
	thread t1(travel, trains[0].time, &trains[0].name);
	
	thread t2(travel, trains[1].time, &trains[1].name);

	thread t3(travel, trains[2].time, &trains[2].name);
	t1.join();
	t2.join();
	t3.join();
}
