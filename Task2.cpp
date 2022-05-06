#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void Task2(){

string integer, div;
double number,fract;

cout << "Enter integer\n";
cin >> integer;
cout << "Enter fraction\n";
cin >> div;

fract = atoi(div.c_str());

while(fract>1)
{
    fract = fract / 10;
}

number = atoi(integer.c_str()) + fract;
cout << number << endl;

}
