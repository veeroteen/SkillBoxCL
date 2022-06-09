#include <iostream>
#include "Tasks.h"
#include <ctime>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <map>
#include <mutex>
using namespace std;
//#define  FORK
//I advise to check define and rate it))
mutex acces1;
#if !defined (FORK)
class Swimmer {
public:
	string name;
	int time = 0;
	Swimmer(string name, int time) {
		this->name = name;
		this->time = time;
	}
};

vector<Swimmer> swimmers;
void swimming(string name, float speed) {
	float lenth = 100;
	int i = 0;
	while (lenth > 0) {
		lenth -= speed;
		i++;
	}
	acces1.lock();
	swimmers.emplace_back(name, i);
	acces1.unlock();
}



void Task1() {
	vector <thread> threads;
	time_t t = time(nullptr);
	for (int i = 0; i < 6; i++) {
		cout << "Enter name and speed of " << "N" << i + 1 << " swimmer\n";
		string name;
		float speed;
		cin >> name >> speed;
		threads.push_back(thread(swimming, name,speed));

	}
	for (int i = 0; i < 6; i++) {
		threads[i].join();
	}


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++){
			if (swimmers[i].time < swimmers[j].time) {
				Swimmer tmp = swimmers[i];
				swimmers[i] = swimmers[j];
				swimmers[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		cout << swimmers[i].name << " - " << swimmers[i].time << endl;
	}

}
#endif

#if defined FORK
class Swimmer {
public:
	string name;
	int time = 0;
	Swimmer(string name, int time) {
		this->name = name;
		this->time = time;
	}
};
class ToThread {
public:
	string name;
	float speed;
	ToThread(string name, float speed) {
		this->name = name;
		this->speed = speed;
	}

};
vector<Swimmer> swimmers;
void swimming(ToThread *to) {
	float lenth = 100;
	int i = 0;
	while (lenth > 0) {
		lenth -= to->speed;
		i++;
	}
	acces1.lock();
	swimmers.emplace_back(to->name, i);
	acces1.unlock();
}



void Task1(){
	vector <thread> threads;
	vector <ToThread> to;
	acces1.lock();
	time_t t = time(NULL);
	for (int i = 0; i < 6; i++) {
		cout << "Enter name and speed of " << "N" << i+1 << " swimmer\n";
		string name;
		float speed;
		cin >> name >> speed;
		to.emplace_back(name,speed);
		
	}
	acces1.unlock();
	for (int i = 0; i < 6; i++) {
		threads.push_back(thread(swimming, &to[i]));
	}
	for (int i = 0; i < 6; i++) {
		threads[i].join();
	}
	to.clear();

	for (int i = 0; i < 6; i++) {
		cout << swimmers[i].name << " - " << swimmers[i].time << endl;
	}


}
#endif
