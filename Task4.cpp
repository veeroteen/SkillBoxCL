#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;

void Task4(){
    string path;
    cout << "Enter Path to file\n";
    cin >> path;
    if(path.find(".png") != -1)
    {
        ifstream file(path,ios::binary );
        string str;
        file >> str;
        if(str[0] == -119 && str[1] == 'P' && str[2] == 'N' && str[3] == 'G' )
        {
            cout << "It is PNG file\n";
        }

    }
    else{
        cout << "It is not PNG file\n";
    }

}