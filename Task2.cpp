#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;


void Task2(){
    srand(time(nullptr));
    ofstream file("draw.txt");
    int x,y;
    cout << "Enter length\n";
    cin >> x;
    cout << "Enter height\n";
    cin >> y;

    for(int n = 0; n < y; n++)
    {
        for (int m = 0; m < x; ++m) {
            file << rand()%2;
        }
        file << endl;
    }
    file.close();
}
