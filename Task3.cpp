#include "Tasks.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;
mutex acces3;
vector <string> ready;
void order(string *str){
	cout << "Order request: " << *str << endl;
	acces3.lock();
	this_thread::sleep_for(chrono::seconds(rand() % 11 + 5));
	cout << "Order ready: " << *str << endl;
	ready.push_back(*str);
	
	acces3.unlock(); 
}
void deliver(int* count) {
	int size = 0;
	int tmp = 0;
	while (true) {
		if (size > 0) {
			cout << "delivery man took ";
			for (int i = tmp; i < size; i++) {
				cout << ready[i] << " ";
				*count = *count + 1;
			}
			cout << endl;
		}
		this_thread::sleep_for(chrono::seconds(30));
		tmp = size;
		size = ready.size();
	}
}




void Task3() {
	string str[5] = { "pizza" , "soup" , "steak" , "salad", "sushi" };
	int count = 0;
	thread deliv(deliver, &count);
	deliv.detach();
	while (count < 10) {
		thread th(order, &str[rand() %5]);
		th.detach();
		this_thread::sleep_for(chrono::seconds(rand() % 6 + 5));
	}


}