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
        for (int j = 0; j < count; j++) {
            settlement.regions[i].buildings.push_back(Building());
        }

    }

    for(int i = 0;i < settlement.regions.size(); i++) {
        int tmp = settlement.regions[i].buildings.size() -1;
        Region *reg = &settlement.regions[i];
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have garage? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->buildings[tmp - 1].type |= garage;
                tmp--;
            }
            
        }
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have barn? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->buildings[tmp - 1].type |= barn;
                tmp--;
            }
            
        }
        if (tmp > 0) {
            cout << "Does " << i+1 << " region have bathhouse? yes/no \n";
            string str;
            cin >> str;
            if (str == "yes")
            {
                reg->buildings[tmp - 1].type |= bathhouse;
                tmp--;
            }
            
        }
        reg->buildings[0].type |= house;
        string str;
        for (int j = 0; j < reg->buildings.size(); j++) {
            if (reg->buildings[j].type & garage) {
                cout << "Enter garage area\n";
                cin >> count;
                reg->buildings[j].area = count;
                break;
            }
        }
        for (int j = 0; j < reg->buildings.size(); j++) {
            if (reg->buildings[j].type & barn) {
                cout << "Enter barn area\n";
                cin >> count;
                reg->buildings[j].area = count;
                break;
            }
        }
        for (int j = 0; j < reg->buildings.size(); j++) {
            bool kk = reg->buildings[j].type & bathhouse;
            int h = reg->buildings[j].type;
            if (reg->buildings[j].type & bathhouse) {
                cout << "Enter bathhouse area\n";
                cin >> count;
                reg->buildings[j].area = count;
                cout << "Did bathhouse have pipe? yes/no\n";
                cin >> str;
                if (str == "yes") {
                    reg->buildings[j].pipe = true;
                }
            }
        }
        cout << "Enter house area\n";
        cin >> count;
        reg->buildings[0].area = count;
        cout << "Did house have pipe? yes/no\n";

        cin >> str;
        if (str == "yes"){
            reg->buildings[0].pipe = true;
        }
        cout << "How many floors house has?\n";
        cin >> tmp;
        for(int n = 0; n < tmp; n++)
        {
            Lvl lvl;
            reg->buildings[0].levels.push_back(lvl);
        }
        for(int n = 0; n < reg->buildings[0].levels.size(); n++){
            cout << "Enter height of " << n+1 << " floor\n";
            cin >> tmp;
            reg->buildings[0].levels[n].height = tmp;
            cout << "Enter area of " << n+1 << " floor\n";
            cin >> tmp;
            reg->buildings[0].levels[n].area = tmp;
            cout << "How many room on " << n+1 << " floor\n";
            cin >> tmp;
            for(int j = 0; j < tmp; j++){
                Room room;
                reg->buildings[0].levels[n].rooms.push_back(room);
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have kitchen? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->buildings[0].levels[n].rooms[tmp-1].type |= kitchen;
                    cout << "Enter area of kitchen\n";
                    int area;
                    cin >> area;
                    reg->buildings[0].levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have living room? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->buildings[0].levels[n].rooms[tmp-1].type  |= living;
                    cout << "Enter area of living room\n";
                    int area;
                    cin >> area;
                    reg->buildings[0].levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have children's room? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->buildings[0].levels[n].rooms[tmp-1].type |= children;
                    cout << "Enter area of children's room\n";
                    int area;
                    cin >> area;
                    reg->buildings[0].levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n << " have bathroom? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->buildings[0].levels[n].rooms[tmp-1].type |= bathroom;
                    cout << "Enter area of bathroom\n";
                    int area;
                    cin >> area;
                    reg->buildings[0].levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
            if (tmp > 0) {
                cout << "Does floor " << n+1 << " have bedroom? yes/no \n";
                string str;
                cin >> str;
                if (str == "yes")
                {
                    reg->buildings[0].levels[n].rooms[tmp-1].type |= bedroom;
                    cout << "Enter area of bedroom\n";
                    int area;
                    cin >> area;
                    reg->buildings[0].levels[n].rooms[tmp-1].area = area;
                    tmp--;
                }
            }
        }
    }

    cout << "end\n";



}
