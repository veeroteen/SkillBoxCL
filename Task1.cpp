#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void Task1(){

    float speed = 0, accel;

    char speedStr[5];
    string str;


    while(true){

        cout << "Enter acceleration\n";
        cin >> accel;
        speed = speed + accel;
        if(speed < 0.01){
            break;
        }
        if(speed > 150){
            speed = 150;
        }
        int tmp = speed*10;
        sprintf(speedStr, "%.1f", speed);


        str = "Speed - " ;
        str = str + speedStr + " Km/h\n";

        cout << str;
    }
    cout << "Car stopped\n";




}
