#include <iostream>
#include <cstdlib>
#include <ctime>

#include "arraylist.h"

int main()
{
	const int MAX = 10000;
	const int REPEATS = 100;
	double sumOfTimes;

	for (int insertions = 0; insertions <= MAX; insertions += 100) {
		sumOfTimes = 0.0;

		for (int iterations = 0; iterations < REPEATS; iterations++) {
			Arraylist list(MAX);
			std::clock_t start = std::clock();

			for (int i = 0; i < insertions; i++) {
				list.insert(rand(), rand() % MAX);
			}

			std::clock_t end = std::clock();
			sumOfTimes += (1000.0 * (end - start) / CLOCKS_PER_SEC);
		}
		std::cout << insertions
		          << ","
		          << (sumOfTimes / REPEATS)
		          << std::endl;
	}
}
