#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;
void fill(){
    ofstream file("words.txt");
    file << "hello afgadga ahdfrafdhg adfg hello" << endl << "hello afdg adsfg adfg";
    file.close();
}

void Task1(){
    fill();
    ifstream file("words.txt");

    string word = "hello";
    int i = 0;
    while (true) {
        string str;
        file >> str;
        if (str == ""){
            break;
        }
        if (str == word) {
            i++;
        }
    }
    file.close();
    cout << i << endl;
}
