#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
#include <sstream>
using namespace std;
struct Employee
{
string Name;
string SecondName;
int Payment;
string date;
};
void start(){
    ofstream file("employers.txt");
    file << "Tom Hanks 35500 10.11.2020" << endl;
    file << "Rebecca Williams 85000 1.1.2021" << endl;
    file << "Sally Field 15600 15.8.2021" << endl;
    file << "Michael Humphreys 29400 23.5.2020" << endl;
    file << "Harold Herthum 74300 9.6.2019" << endl;
    file << "George Kelly 45000 12.3.2018" << endl;
    file << "Bob Penny 12500 13.5.2020" << endl;
    file << "John Randall 23400 2.10.2020" << endl;
    file << "Sam Anderson 6500 15.7.2020" << endl;
    file << "Margo Moorer 12350 24.2.2019" << endl;
    file.close();
}
void Task3(){
    start();
    ifstream file("employers.txt");
    Employee max;
    int sum = 0;
    while(true) {
        string str;
        getline(file, str);
        if(str == ""){
            break;
        }
        stringstream buff;
        buff << str;
        Employee employe;
        buff >> employe.Name;
        buff >> employe.SecondName;
        buff >> employe.Payment;
        buff >> employe.date;
        if(sum == 0){
            max = employe;
        }
        sum = sum + employe.Payment;
        if(employe.Payment > max.Payment)
        {
            max = employe;
        }
    }

    cout << max.Name << " " << max.SecondName << " has the biggest payment\n";
    cout << "Sum of payment - " << sum << endl;

}
