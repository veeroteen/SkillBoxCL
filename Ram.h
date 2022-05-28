#pragma once
#include <vector>
std::vector <int> mem = std::vector<int>(8);
class Ram {
public:
	static void write(int n,int i) {
		mem[i] = n;
	}
	static std::vector <int> read() {
		return mem;

	}
};