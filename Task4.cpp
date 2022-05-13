#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
using namespace std;
class ATM{
    int bill5000 =0;
    int bill2000 = 0;
    int bill1000 = 0;
    int bill500= 0;
    int bill200= 0;
    int bill100= 0;
    int count = 1000;

public:
    void fill()
    {
        ifstream file("ATM.bin",ios::binary);
        file >> bill5000;
        file >> bill2000;
        file >> bill1000;
        file >> bill500;
        file >> bill200;
        file >> bill100;
        count =  1000 - (bill5000 + bill2000 + bill1000 + bill500 + bill200 + bill100);
        file.close();
    }
    void inc(){
        ofstream file("ATM.bin",ios::binary);
        int billcount = rand()%count+1;
        count = count - billcount;
        file << billcount << endl;
        billcount = rand()%count+1;
        count = count - billcount;
        file << billcount << endl;
        billcount = rand()%count+1;
        count = count - billcount;
        file << billcount << endl;
        billcount = rand()%count+1;
        count = count - billcount;
        file << billcount << endl;
        billcount = rand()%count+1;
        count = count - billcount;
        file << billcount << endl;
        billcount = count;
        count = count - billcount;
        file << billcount << endl;
        file.close();
        fill();
    };
    void recalculation()
    {
        ofstream file ("ATM.bin",ios::binary);
        file << bill5000 << endl;
        file << bill2000<< endl;
        file << bill1000<< endl;
        file << bill500<< endl;
        file << bill200<< endl;
        file << bill100<< endl;
        file.close();
    }
    bool take(int sum)
    {
        int tmp = sum/5000;
        if (tmp > bill5000)
        {
            sum = sum - (5000*bill5000);
            bill5000 = 0;
        }
        else{
            sum = sum - (5000*tmp);
            bill5000 -=tmp;
        }
        tmp = sum/2000;
        if (tmp > bill2000)
        {
            sum = sum - (2000*bill2000);
            bill2000 = 0;
        }
        else{
            sum = sum - (2000*tmp);
            bill2000 -= tmp;
        }
        tmp = sum/1000;
        if (tmp > bill1000)
        {
            sum = sum - (1000*bill1000);
            bill1000 = 0;
        }
        else{
            sum = sum - (1000*tmp);
            bill1000 -= tmp;
        }
        tmp = sum/500;
        if (tmp > bill500)
        {
            sum = sum - (500*bill500);
            bill500 = 0;
        }
        else{
            sum = sum - (500*tmp);
            bill500 -= tmp;
        }

        tmp = sum/200;
        if (tmp > bill200)
        {
            sum = sum - (200*bill200);
            bill200 = 0;
        }
        else{
            sum = sum - (200*tmp);
            bill200 -= tmp;
        }
        tmp = sum/100;
        if (tmp > bill100)
        {
            sum = sum - (100*bill100);
            bill100 = 0;
        }
        else{
            sum = sum - (100*tmp);
            bill100 -= tmp;
        }
        if(sum == 0){
            recalculation();
            return true;
        }
        return false;

    }
};


void Task4(){

    ATM bb;
    bb.inc();

    string str;
    cout << "Enter command\n";
    cin >> str;

    if(str == "+"){
        bb.inc();
    }
    else if(str == "-"){
        int n;
        while(true) {
            cout << "Enter sum\n";
            cin >> n;
            if(n%100 == 0)
            {
                break;
            }
            cout << "Incorrect\n";
        }
        if(bb.take(n)){
            cout << "Operation complete\n";
        }
        else{
            cout << "ATM have not bills\n";
        }

}
}