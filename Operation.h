#pragma once
#include "Suture.h"
#include "Scalpel.h"
#include "Structs.h"
#include "Hemostat.h"
#include "Tweezers.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Operation
{
	vector <Line> cuts;
	Tweezers twee;
	Suture sutur;
	Scalpel scalp;
	Hemostat hem;
public:
	void operation();






};

