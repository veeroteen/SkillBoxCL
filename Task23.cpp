#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

int rec (int n, int k = 3){
int r = 0;
    if(n == 0)
    {

        return 1;
    }
    for (int i = 1; i < k+1 && i < n+1; i++){
        r +=rec(n - i, k);
    }
    return r;
}

void Task23(){

cout << endl << rec(3,2) << endl;
}
