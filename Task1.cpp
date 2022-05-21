#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <map>
using namespace std;
void add(map<string,string>& phonebook,string key,string value) {
    phonebook[key] = value;
}
void get(map<string, string>& phonebook, string key) {
    if (key[0] - 48 >= 0 && key[0] - 48 <= 9)
    {
        string tmp = phonebook[key];
        while (true) {
            if (tmp[tmp.length() - 1] - 48 >= 0 && tmp[tmp.length() - 1] - 48 <= 0) {
                tmp.erase(tmp.length() - 1);
            }
            else {
                break;
            }
        }
        cout << tmp << endl;
    }
    else {
        
        map<string,string>::iterator it = phonebook.begin();
        while(it != phonebook.end()) {
            
            string tmp = it->second;
            if (tmp == key) {
                cout << it-> first << " ";
            }
            it++;

        } 
        cout << endl;
    }
}




void Task1(){
   
    map <string, string> phonebook;
    while (true) {
        cout << "Enter query\n";
        string str;
        getline(cin, str);
        if (str[0] - 48 >= 0 && str[0] - 48 <= 9 && str.length() > 9)
        {
            add(phonebook, str.substr(0, 8), str.substr(9));
        }
        else {
            get(phonebook, str);
        }
    }
    cout << endl;

}

