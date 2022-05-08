#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;

bool substr(char* a, char* b)
{
    for(int i = 0; a[i] != '\0';i++)
    {

       if(a[i] == b[0])
       {
           for (int n = 1; b[n] != '\0' && a[i+n] !='\0'; n++ )
           {
               if(a[i+n] != b[n])
               {
                   break;
               }
               if(b[n+1] == '\0'){
                   return true;
               }
           }

       }
    }




}



void Task3(){

    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";


    std::cout << substr(a,b) << " " << substr(a,c);


}