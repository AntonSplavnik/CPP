#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <ctime>
#include "PmergMe.hpp"

int parse_input(int argc, char** argv, std::vector<int>& input, std::deque<int> input_2) {
	if (argc < 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if (argc == 2) {
		std::stringstream ss(argv[1]);
		int num;
		while (ss >> num) {
		input.push_back(num);
		input_2.push_back(num);
		}
	}
	else {
		for (int i = 1; i < argc; i++) {
			int buf = atoi(argv[i]);
			// std::cout << " Negative value: " << buf << std::endl;
			if (buf < 0) {
				std::cout << "Negative values are not alloud!" << std::endl;
				return 1;
			}
			input.push_back(buf);
			input_2.push_back(buf);
		}
	}
	return 0;
}

int main(int argc, char** argv) {

	std::vector<int> input;
	std::deque<int> input_2;

	if (parse_input(argc, argv, input, input_2)) return 0;

	std::cout << "Initial input: ";
	for (size_t i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
/*
	- clock() — counts only time when the CPU is actively executing instructions. Memory stall time is not counted.
	- gettimeofday() — counts all real elapsed time, including time when the CPU is stalled waiting for RAM.
*/
/*
	PmergMe<std::vector<int> > test(input);
	clock_t start = clock();
	test.sort();
	clock_t end = clock();
	double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << input.size() << " elements with std::vector<int>: " << std::fixed << std::setprecision(6) << elapsed << std::endl;

	PmergMe<std::deque<int> > test2(input_2);
	start = clock();
	test2.sort();
	end = clock();
	elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << input.size() << " elements with std::deque<int>: " << std::fixed << std::setprecision(6) << elapsed << std::endl;

 */
	struct timeval start, end;
	double elapsed;

	// std::cout << "starting VECTOR sort\n" << std::endl;
	PmergMe<std::vector<int> > test(input);
	gettimeofday(&start, NULL);
	test.sort();
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << input.size() << " elements with std::vector<int>: " << std::fixed << std::setprecision(6) << elapsed / 1000000 << std::endl;

	// std::cout << "starting DEQUE sort\n" << std::endl;
	PmergMe<std::deque<int> > test2(input_2);
	gettimeofday(&start, NULL);
	test2.sort();
	gettimeofday(&end, NULL);
	elapsed = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec + start.tv_usec)) / 1000000;
	std::cout << "Time to process a range of " << input.size() << " elements with std::deque<int>: " << std::fixed << std::setprecision(6) << elapsed << std::endl;

	return 0;
}
