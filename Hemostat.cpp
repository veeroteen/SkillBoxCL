#include "Hemostat.h"



void Hemostat::press(Vector2i n) {
	pos = n;
	cout << "Hemostat successful" << n.get() << endl;
}