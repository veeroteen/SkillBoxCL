#include "Window.h"

void Window::set_size(Vector2i vec , Vector2i out) {
	size = size + vec;
	if (cord.x + size.x > out.x)
	{
		size.x = out.x - cord.x;
	}
	else if (size.x < 0) {
		size.x = 0;
	}
	if (cord.y + size.y > out.y) {
		size.y = out.y - cord.y;
	}
	else if (size.y < 0) {
		size.y = 0;
	}
}
void Window::set_cord(Vector2i vec , Vector2i out) {
	cord = cord + vec;
	if (cord.x + size.x > out.x)
	{
		cord.x = out.x - size.x;
	}
	else if (cord.x < 0) {
		cord.x = 0;
	}
	if (cord.y + size.y > out.y) {
		cord.y = out.y - size.y;
	}
	else if (cord.y < 0) {
		cord.y = 0;
	}
}
