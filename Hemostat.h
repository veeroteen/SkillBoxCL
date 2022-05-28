#pragma once
#include <string>
#include <iostream>
#include "Structs.h"

class Hemostat {
public:
	Vector2i pos;
	void press(Vector2i n);
};