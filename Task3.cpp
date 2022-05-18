#include <vector>
#include <iostream>
#include <string>
#include "Tasks.h"
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
class Vector2f{
public :
    float x , y;

    Vector2f operator + (Vector2f vec)
    {
        Vector2f ret;
        ret.x = x + vec.x;
        ret.y = y + vec.y;
        return ret;
    }
    Vector2f operator - (Vector2f vec)
    {
        Vector2f ret;
        ret.x = x - vec.x;
        ret.y = y - vec.y;
        return ret;
    }
    Vector2f scale(float n){
        Vector2f ret = {x * n , y * n};
        return ret;
    }
    float length(){
        float ret = {sqrt(x*x + y*y)};
        return ret;
    }
    Vector2f normalize(){
        float leng = length();
        Vector2f vec = {x/leng , y /leng};
        return vec;
    }
};
void Task3(){
cout << "Enter command\n";
string str;
cin >> str;
if(str == "add"){
    Vector2f vec1,vec2;
    cout << "Enter first vector\n";
    float x,y;
    cin >> x >> y;
    vec1 = {x,y};
    cout << "Enter second vector\n";
    cin >> x >> y;
    vec2 = {x,y};

    vec1 = vec1 + vec2;

    cout << vec1.x << " " << vec1.y << endl;
}
else if(str == "subtract"){
    Vector2f vec1,vec2;
    cout << "Enter first vector\n";
    float x,y;
    cin >> x >> y;
    vec1 = {x,y};
    cout << "Enter second vector\n";
    cin >> x >> y;
    vec2 = {x,y};

    vec1 = vec1 - vec2;

    cout << vec1.x << " " << vec1.y << endl;
}
else if(str == "scale"){
    Vector2f vec1;
    cout << "Enter vector\n";
    float x,y;
    cin >> x >> y;
    vec1 = {x,y};
    cout << "Enter scale\n";
    cin >> x;
    vec1 = vec1.scale(x);
    cout << vec1.x << " " << vec1.y << endl;
}
else if(str == "length"){

    Vector2f vec1;
    cout << "Enter vector\n";
    float x,y;
    cin >> x >> y;
    vec1 = {x,y};
    x = vec1.length();
    cout << x << endl;

}
else if(str == " normalize"){
    Vector2f vec1;
    cout << "Enter vector\n";
    float x,y;
    cin >> x >> y;
    vec1 = {x,y};
    vec1 = vec1.normalize();
    cout << vec1.x << " " << vec1.y << endl;
}


}
