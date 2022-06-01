#pragma once
#include "Structs.h"
class Window
{
public:
	Vector2i size = Vector2i{ 10,10 };
	Vector2i cord = Vector2i{ 0,0 };

	void set_size(Vector2i vec, Vector2i out);
	void set_cord(Vector2i vec, Vector2i out);
	Vector2i* get_window();

};

