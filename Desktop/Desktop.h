#pragma once
#include "Structs.h"
#include "Window.h"
#include <iostream>
using namespace std;
class Desktop
{
	Window window;
	Vector2i size = Vector2i{ 80,50 };
public:
	void move();
	void resize();
	void display();
	void engine();
};

