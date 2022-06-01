#pragma once
#include <string>
#include <ctime>
using namespace std;
class Track
{
public:
	tm* createDate;
	string name;
	int duration;

	Track(tm* t, int dur, string name);
};

