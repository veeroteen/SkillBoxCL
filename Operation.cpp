#include "Operation.h"


void Operation::operation() {

	while (true) {
		cout << "Enter comand\n";
		string str;
		cin >> str;
		if (str == "scalpel") {
			Line line;
			cout << "Enter x of first coordinates\n";
			cin >> line.positions[0].x;
			cout << "Enter y of first coordinates\n";
			cin >> line.positions[0].y;
			cout << "Enter x of second coordinates\n";
			cin >> line.positions[1].x;
			cout << "Enter y of second coordinates\n";
			cin >> line.positions[1].y;
			scalp.scalp(line);
			cuts.push_back(line);

		}
		else if (str == "hemostat") {
			Vector2i vec;
			cout << "Enter x coordinat\n";
			cin >> vec.x;
			cout << "Enter y coordinat\n";
			cin >> vec.y;
			hem.press(vec);
		}
		else if (str == "tweezers") {
			Vector2i vec;
			cout << "Enter x coordinat\n";
			cin >> vec.x;
			cout << "Enter y coordinat\n";
			cin >> vec.y;
			twee.press(vec);
		}
		else if (str == "suture") {
			Line line;
			cout << "Enter x of first coordinates\n";
			cin >> line.positions[0].x;
			cout << "Enter y of first coordinates\n";
			cin >> line.positions[0].y;
			cout << "Enter x of second coordinates\n";
			cin >> line.positions[1].x;
			cout << "Enter y of second coordinates\n";
			cin >> line.positions[1].y;
			bool cut = false;
			for (int i = 0; i < cuts.size(); i++) {
				if (cuts[i] == line) {
					sutur.sut(line);
					cuts.erase(cuts.begin()+i);
					cut = true;
					break;
				}
			}
			if (!cut) {
				cout << "Incompletable\n";
			}
			if(cuts.size() == 0){
				break;
			}
		}
	}
	cout << "Operation completed\n";
}