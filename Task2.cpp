#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
#include "Structs.h"
using namespace std;


void Task2(){
    cout << "Enter region count\n";
    int count;
    cin >> count;
    Settlement settlement;
    for(int i = 0; i < count; i++)
    {
        Region reg;
        settlement.regions.push_back(reg);
    }






    for(int i = 0;i < settlement.regions.size(); i++)
    {
        cout << "Enter builds count on " << i+1 << " region\n";
        cin >> count;
        settlement.regions[i].count = count;

    }

    for(int i = 0;i < settlement.regions.size(); i++) {
        int tmp = settlement.regions[i].count - 1;
        Region *reg = &settlement.regions[i];
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have garage? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->garage.have = true;
            }
            tmp--;
        }
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have barn? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->barn.have = true;
            }
            tmp--;
        }
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have bathhouse? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->bathhouse.have = true;
            }
            tmp--;
        }
        string str;
        if(reg->garage.have){
            cout << "Enter garage area\n";
            cin >> count;
            reg->garage.area = count;
        }
        if(reg->barn.have){
            cout << "Enter barn area\n";
            cin >> count;
            reg->barn.area = count;
        }
        if(reg->bathhouse.have){
            cout << "Enter bathhouse area\n";
            cin >> count;
            reg->bathhouse.area = count;
            cout << "Did bathhouse have pipe? yes/no\n";
            cin >> str;
            if (str == "yes"){
                reg->bathhouse.pipe = true;
            }
        }
        cout << "Enter house area\n";
        cin >> count;
        reg->house.area = count;
        cout << "Did house have pipe? yes/no\n";

        cin >> str;
        if (str == "yes"){
            reg->house.pipe = true;
        }
        cout << "How many floors house has?\n";
        cin >> tmp;
        for(int n = 0; n < tmp; n++)
        {
            Lvl lvl;
            reg->house.levels.push_back(lvl);
        }
        for(int n = 0; n < reg->house.levels.size(); n++){
            cout << "Enter height of " << n+1 << " floor\n";
            cin >> tmp;
            reg->house.levels[n].height = tmp;
            cout << "Enter area of " << n+1 << " floor\n";
            cin >> tmp;
            reg->house.levels[n].area = tmp;
            cout << "How many room on " << n+1 << " floor\n";
            cin >> tmp;
            for(int j = 0; j < tmp; j++){
                Room room;
                reg->house.levels[n].rooms.push_back(room);
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have kitchen? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->house.levels[n].rooms[tmp-1].type = "kitchen";
                    cout << "Enter area of kitchen\n";
                    int area;
                    cin >> area;
                    reg->house.levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have living room? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->house.levels[n].rooms[tmp-1].type = "living room";
                    cout << "Enter area of living room\n";
                    int area;
                    cin >> area;
                    reg->house.levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have children's room? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->house.levels[n].rooms[tmp-1].type = "children's room";
                    cout << "Enter area of children's room\n";
                    int area;
                    cin >> area;
                    reg->house.levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n << " have bathroom? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->house.levels[n].rooms[tmp-1].type = "bathroom";
                    cout << "Enter area of bathroom\n";
                    int area;
                    cin >> area;
                    reg->house.levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have bedroom? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->house.levels[n].rooms[tmp-1].type = "bedroom";
                    cout << "Enter area of bedroom\n";
                    int area;
                    cin >> area;
                    reg->house.levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
        }
    }

    cout << "end\n";



}
