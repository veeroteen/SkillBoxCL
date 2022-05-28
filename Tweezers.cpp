#include "Tweezers.h"

void Tweezers::press(Vector2i n) {
	pos = n;
	cout << "Tweezers successful" << n.get() << endl;
}