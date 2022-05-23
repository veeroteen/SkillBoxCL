#include <iostream>
#include "Tasks.h"

using namespace std;
void chekMore(int &train, int i) {
	if (train > 20) {
		cout << "Carriage " << i + 1 << " overflow\n";
	}
}
void chekLess(int &train, int i){
	if (train < 20) {
		cout << "Carriage " << i + 1 << " has empty space\n";
	}
}
void add(int &train, int i, int &count) {
	cout << "Enter count of passanger in " << i+1 << " carriage\n";
	cin >> train;
	count = count + train;
}

#define CHEK for(int i = 0; i < 10; i++)
#define ADD for(int i = 0; i < 10; i++)

void Task2(){
	int* train = new int;
	int count = 0;
	ADD{
		add(train[i],i, count);
	}
	CHEK{
		chekMore(train[i],i);
	}
	CHEK{
		chekLess(train[i],i);
	}
	cout << "Total number of passengers " << count << endl;
}
