#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void swap (int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;

}

void Task1(){

    int a = 10;

    int b = 20;

    swap(&a, &b);

    cout << a << " " << b << endl;

}
