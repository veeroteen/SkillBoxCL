#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;



void rec(long long lg, int &ans)
{
        if(lg%10%2 == 0)
        {
            ans++;
        }
        lg = lg/10;
        if(lg == 0) return;
        rec(lg,ans);
}






void evendigits(long long lg, int &ans)
{
    ans = 0;
    while (lg != 0){
        if(lg%10%2 == 0)
        {
            ans++;
        }
        lg = lg/10;
    }

}



void Task4(){

    int ans = 0;

    evendigits(9223372036854775806, ans);
    cout << ans << endl;
    ans = 0;
    rec(9223372036854775806, ans);
    cout << ans << endl;
}