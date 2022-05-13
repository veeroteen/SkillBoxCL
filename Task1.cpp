#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;


void Task1(){
    string str,tmp;
    while(true) {
        ofstream file("employers.txt",ios::app);
        cout << "Enter name\n";
        cin >> str;
        str = str + ' ';
        cout << "Enter secondName\n";
        cin >> tmp;
        str = str + tmp + ' ';
        cout << "Enter Payment\n";
        int i;
        cin >> i;
        str = str + to_string(i) + ' ';
        while(true) {
            cout << "Enter day number\n";
            cin >> tmp;
            i = atoi(tmp.c_str());
            if (i < 1 || i > 31) {
                cout << "Incorrect\n";
                continue;
            }
            break;
        }
        str = str + to_string(i) + '.';
        while(true) {
            cout << "Enter month number\n";
            cin >> tmp;
            i = atoi(tmp.c_str());
            if (i < 1 || i > 12) {
                cout << "Incorrect\n";
                continue;
            }
            break;
        }
        str = str + to_string(i) + '.';
        while(true) {
            cout << "Enter year\n";
            cin >> tmp;
            i = atoi(tmp.c_str());
            if (i < 0 || i > 9999) {
                cout << "Incorrect\n";
                continue;
            }
            break;
        }
        str = str + to_string(i);
        file << str << endl;
    }

}

