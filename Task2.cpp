#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

void swap (int *arr){

    for(int i =0 ; i < 5; i++){
        int tmp = arr[i];
        arr[i] = arr[9-i];
        arr[9-i] = tmp;
    }
}

void Task2(){
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    int *arr = ar;
    int y = 10;
        for (int i = 0; i < 10; i++){
            arr[i] = i;
            cout << arr[i] << " ";
        }
    cout << endl;

    swap(arr);

    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
