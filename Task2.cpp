#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;


void Task2(){
    string str;
    cout << "Enter file path\n";
    cin >> str;
    ifstream file(str);
    if(file.is_open()){
        while (true)
        {
            string tmp;
            getline(file,tmp);
            if(tmp == ""){
                break;
            }
            cout << tmp << endl;
        }

    }
}
