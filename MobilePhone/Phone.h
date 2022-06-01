#pragma once
#define BOOK
#include "AddressBook.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
class Phone
{
#ifdef MAP
	map<string, string> bookM;
#endif 

#ifdef BOOK
	vector <AddressBook> book;
public:
	string findNumber(string name);
#endif 
public:
	
	void add();
	void call();
	void sms();
	void engine();

};

