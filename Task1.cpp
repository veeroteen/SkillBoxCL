#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void swapvec (vector <int> &a, int *b){

    for (int i = 0; i < a.size(); i++)
    {
        int tmp = b[i];
        b[i] = a[i];
        a[i] = tmp;
    }


}

void Task1(){
    vector <int> a = {1,2,3,4};
    int arr[] = {2,4,6,8};
    int *b = arr;

    swapvec(a, b);

    for(int i = 0; i < 4; ++i) {
        cout << a[i];
    }
    cout << std::endl;

    for(int i = 0; i < 4; ++i) {
        cout << b[i];
    }
}
