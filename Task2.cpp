#include <iostream>
#include "Tasks.h"

using namespace std;
void chek(int* train) {
	int count = 0;
	for(int i = 0; i < 10; i++){
		if (train[i] > 20) {
			cout << "Carriage "<< i+1 <<" overflow\n";
		}
		count = count + train[i];
	}
	for (int i = 0; i < 10; i++) {
		if (train[i] < 20) {
			cout << "Carriage " << i + 1 << " has empty space\n";
		}
	}
	cout << "Total number of passengers " << count << endl;

}
void add(int* train) {
	for (int i = 0; i < 10; i++) {
		cout << "Enter count of passaòger in " << i+1 << " carriage\n";
		cin >> train[i];
	}
}

#define CHEK(train) chek(train)
#define ADD(train) add(train)

void Task2(){
	int* arr = new int;
	ADD(arr);
	CHEK(arr);
}
