#include <iostream>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <cmath>

int main()
{
	srand(time(NULL));

	int n;
	std::ofstream out("out_cpp.txt");
	for (int i = 0; i < 8; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		n = pow(10, i);
		std::map<int, int> counter{};
		for (int j = 0; j < n; j++) {
			counter.insert(std::make_pair(std::rand(), std::rand()));
		}
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << n << " " << sizeof(counter) + counter.size() * n << " " << time.count() << std::endl;
	out << n << " " << sizeof(counter) + counter.size() * n << " " << time.count() << std::endl;
	}

	return 0;
}



