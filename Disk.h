#pragma once
#include <fstream>
#include "Ram.h"
using namespace std;
	void save(std::vector<int> memory) {
		ofstream file("data.txt");

		for (int i = 0; i < memory.size(); i++) {
			file << memory[i] << endl;
		}
		file.close();
	}
	void load(std::vector<int> memory) {
		ifstream file("data.txt");

		for (int i = 0; i < 8; i++) {
			int n;
			file >> n;
			if (file.peek() != EOF) {
				Ram::write(n, i);
			}
			else {
				break;
			}
		}
		file.close();
	}

