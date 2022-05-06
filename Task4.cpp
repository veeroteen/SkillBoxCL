#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

void Task4() {

int melody[12] = {0};

string str;


for (int i  = 1; i <= 12; i++){
    cout << "Enter " << i << " combination\n";
    cin >> str;

    for (int n = 0; n < str.length();n++){


        melody[i] |= 1 << (str[n]-49);

    }
}


for (int i = 0;i< 12; i++)
{
    if(melody[i] & DO)
    {
        cout << "DO ";
    }
    if(melody[i] & RE)
    {
        cout << "RE ";
    }
    if(melody[i] & MI)
    {
        cout << "MI ";
    }
    if(melody[i] & FA)
    {
        cout << "FA ";
    }
    if(melody[i] & SOL)
    {
        cout << "SOL ";
    }
    if(melody[i] & LA)
    {
        cout << "LA ";
    }
    if(melody[i] & SI)
    {
        cout << "SI ";
    }
    cout << endl;

}






}
