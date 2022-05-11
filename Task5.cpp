#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Tasks.h"
using namespace std;
void create(){
    for(int i = 1; i < 14; i++)
    {
        string path = "";
        path = to_string(i);
        ofstream ask(path+"ask.txt");
        ofstream answ(path+"answ.txt");
        ask << i << " + " << i;
        answ << i+i;
        ask.close();
        answ.close();

    }

}

void Task5(){
create();
bool sectors[13];
int wat = 0, player = 0;
for(int i = 0; i <13; i++){
    sectors[i] = true;
}
int counter = 0;
for(int i = 0; i< 13; i++) {
    cout << "Enter offset\n";
    int offset;
    cin >> offset;
    offset = offset % 13;
    counter = counter + offset;
    while(true) {
        if (counter < 0) {
            counter = 12 + counter;
        } else if (counter > 12) {
            counter = counter % 12;
        }
        if (!sectors[counter]) {
            counter++;
            i--;
            continue;

        }
        string tmp = to_string(counter + 1);
        ifstream ask(tmp + "ask.txt");
        ifstream answ(tmp + "answ.txt");
        getline(ask, tmp);
        cout << tmp << endl;
        string res;
        cin >> res;
        answ >> tmp;
        if (res == tmp) {
            cout << "Player gets a point\n";
            player++;

        } else {
            cout << "Right answer is " << tmp << ", viewer gets a point\n";
            wat++;
        }
        sectors[counter] = false;
        break;
    }
    if (wat == 6) {
        cout << "Watcher won\n";
        break;
    }
    if (player == 6) {
        cout << "Player won\n";
        break;
    }

}
}