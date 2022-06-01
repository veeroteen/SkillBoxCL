#include "Desktop.h"
void Desktop::move(){
	int x, y;
	cout << "Enter x and y axis\n";
	cin >> x >> y;
	window.set_cord(Vector2i{ x,y }, size);
}


void Desktop::resize(){
	int x, y;
	cout << "Enter x and y size\n";
	cin >> x >> y;
	window.set_size(Vector2i{ x,y }, size);
}


void Desktop::display(){
	for (int y = 0; y < size.y; y++) {
		for (int x = 0; x < size.x; x++) {
			if ((x >= window.cord.x && x <= window.size.x + window.cord.x) && (y >= window.cord.y && y <= window.size.y + window.cord.y)){
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}

}

void Desktop::engine() {
	while (true) {
		cout << "Enter command\n";
		string str;
		cin >> str;

		if (str == "move") {
			move();
		}
		else if (str == "resize") {
			resize();
		}
		else if (str == "display") {
			system("cls");
			display();
		}
		else if (str == "close") {
			break;
		}
	}
}