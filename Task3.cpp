#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
#include <sstream>
using namespace std;
void fillRiver(){
    ofstream river("river.txt",ios::app);
    river << "sunfish" << endl;
    river << "shad" << endl;
    river << "carp" << endl;
    river << "bass" << endl;
    river << "bullhead" << endl;
    river << "carp" << endl;
    river << "walleye" << endl;
    river << "catfish" << endl;
    river << "carp" << endl;
}

void Task3(){
    //fillRiver();
    ifstream river("river.txt");
    ofstream basket("basket.txt",ios::app);

    cout << "Enter fish name\n";
    string fish;
    cin >> fish;
    int count;
    while(true)
    {
        string tmp;
        river >> tmp;
        if(tmp == "")
        {
            break;
        }
        if(tmp == fish){
            count++;
            basket << fish << endl;
        }

    }

    cout << "You caught " << count << " fish\n";


}
