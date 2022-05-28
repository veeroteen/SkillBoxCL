#pragma once
#include <iostream>
#include <vector>
void compute(std::vector<int> memory) {
	int n = 0;
	for (int i = 0; i < memory.size(); i++) {
		n = n + memory[i];
	}
	std::cout << n << std::endl;
}