#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
#include <sstream>
using namespace std;

struct Employee
{
    string Name;
    string SecondName;
    int Payment;
    string date;
};
void add()
{
    string str,tmp;

    ofstream file("employers.txt", ios::app);
    cout << "Enter name\n";
    cin >> str;
    str = str + ' ';
    cout << "Enter secondName\n";
    cin >> tmp;
    str = str + tmp + ' ';

    int i;
    while (true) {
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
    while (true) {
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
    while (true) {
        cout << "Enter year\n";
        cin >> tmp;
        i = atoi(tmp.c_str());
        if (i < 0 || i > 9999) {
            cout << "Incorrect\n";
            continue;
        }
        break;
    }
    str = str + to_string(i) + ' ';

    cout << "Enter Payment\n";
    cin >> i;
    str = str + to_string(i);
    file << str << endl;
    file.close();
}
void read(){
    ifstream file("employers.txt");

    vector <Employee> arr;

    while(true)
    {
        string str;
        getline(file,str);
        if(str == ""){
            break;
        }
        stringstream tmp;
        tmp << str;

        Employee buff;
        tmp >> buff.Name;
        tmp >> buff.SecondName;
        tmp >> buff.date;
        tmp >> str;
        buff.Payment = atoi(str.c_str());
        arr.push_back(buff);
    }
    for(int i = 0; i < arr.size();i++)
    {
        cout << arr[i].Name << " " << arr[i].SecondName << " " << arr[i].date << " " << arr[i].Payment << endl;
    }

}


void Task1(){
    cout << "Enter command read/add\n";
    string str;
    cin >> str;
    if(str == "add"){
        add();
    }
    else if(str == "read"){
        read();
    }
    else{
        cout << "Incorrect\n";
    }
}

