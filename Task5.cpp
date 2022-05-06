#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "Tasks.h"
using namespace std;

enum note
{
    ENERGY = 1,
    LIGHTS_INSIDE = 2,
    LIGHTS_OUTSIDE = 4,
    HEATERS = 8,
    WATER_PIPE_HEATING = 16,
    CONDITIONER = 32
};

void Task5(){

    string str;
    int state = 0;
    int hour = 0;
    int kel = 0;


    for(int i = 0; i <48; i++)
    {
        cout << "Time is " << hour << ":00\n";
        cout << "Enter energy/temperature outside/movement outside/temperature inside/light inside\n";
        getline(cin, str);
        stringstream strm;
        strm << str;

        string en, tempout, move, tempin, lightin;
        strm >> en >> tempout >> move >> tempin >> lightin;
        if(en == "on" && !(state & ENERGY)) {
            cout << "Energy ON\n";
            state |= ENERGY;
        }
        else if (state & ENERGY && en == "off"){
            cout << "Energy off\n";
            state &= ~ENERGY;
        }
        if(state & ENERGY) {
            int tmp = atoi(tempout.c_str());
            if (tmp < 0 && !(state & WATER_PIPE_HEATING)) {
                cout << "Water heating ON\n";
                state |= WATER_PIPE_HEATING;
            }
            if (tmp > 5 && (state & WATER_PIPE_HEATING)) {
                cout << "Water heating OFF\n";
                state &= ~WATER_PIPE_HEATING;
            }
            if (move == "yes" && (hour > 16 || hour < 5) && !(state & LIGHTS_OUTSIDE)){
                state |= LIGHTS_OUTSIDE;
                cout << "Lights outside ON\n";
            }
            else if(move == "no" && (state & LIGHTS_OUTSIDE)){
                state &= ~LIGHTS_OUTSIDE;
                cout << "Lights outside OFF\n";
            }
            tmp = atoi(tempin.c_str());
            if (tmp < 22 && !(state & HEATERS)){
                cout << "Heaters ON\n";
                state |= HEATERS;
            }
            if (tmp > 25 && (state & HEATERS)){
                state &= ~HEATERS;
                cout << "Heaters OFF\n";
            }
            if (tmp > 29 && !(state & CONDITIONER)){
                state |= CONDITIONER;
                cout << "Conditioner ON\n";
            }
            if(tmp < 26 && (state & CONDITIONER)){
                state &= ~CONDITIONER;
                cout << "Conditioner OFF\n";
            }
            if (lightin == "on" && !(state & LIGHTS_INSIDE)){
                state |= LIGHTS_INSIDE;
                kel = 5000;
                cout << "Lights inside ON\n";
            }
            else if(lightin == "off" && ( state & LIGHTS_INSIDE)) {
                state &= ~LIGHTS_INSIDE;
                cout << "Lights inside OFF\n";
            }
            if (state & LIGHTS_INSIDE ){
                cout << "Light brightness " << kel << endl;
                if (hour >= 16 && hour <= 20) {
                    if (kel - 300 < 2700) { kel = 2700; }
                    else kel -= 300;
                }
            }
            if (hour == 0) kel = 5000;
        }
        hour ++;
        if (hour > 23) hour = 0;
    }







}