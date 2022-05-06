#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void Task3(){


    string str;

    cout << "Enter operation\n";
    cin >> str;

    double a = atof(str.c_str());

    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            str.erase(0,i);
        }
    }
    char sign = str.substr(0,1)[0];
    str.erase(0,1);
    switch (sign)
    {
        case '+':
            a = a + atof(str.c_str());
            break;
        case '-':
            a = a - atof(str.c_str());
            break;
        case '/':
            a = a / atof(str.c_str());
            break;
        case '*':
            a = a * atof(str.c_str());
            break;

    }
    cout << a << endl;

}