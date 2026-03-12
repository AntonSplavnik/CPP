#include "iostream"
#include "vector"
#include "sstream"
#include <algorithm>
#include "PmergMe.hpp"

int main(int argc, char** argv) {

	// (void)argc;
	// (void)argv;

	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}

	// parse input
	std::vector<int> input;
	std::stringstream ss(argv[1]);
	int num;
	while (ss >> num) {
		input.push_back(num);
	}

	std::cout << "initial input: ";
	for (size_t i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << " ";
	}
	std::cout << "\n" << std::endl;

	PmergMe<std::vector<int> > test(input);
	test.sort();

	/*
	// split all elements in pairs (uneven stored separetly)
	std::vector<std::pair<int, int> > pairs;
	int struggler = 0;
	bool has_struggler = false;

	size_t input_size = input.size();

	for (size_t i = 0; i + 1 < input_size; i += 2) {
		pairs.push_back(std::make_pair(input.at(i), input.at(i+1)));
	}
	if (input.size() % 2 == 1) {
		has_struggler = true;
		struggler = input.back();
	}

	for(size_t i = 0; i < pairs.size(); i++) {
		std::cout << "first: " << pairs[i].first << "  second: " << pairs[i].second << "\n";
	}
	if (has_struggler) {
		std::cout << struggler << std::endl;
	}

	// sort throug pairs (larger second)
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if(pairs.at(i).first > pairs.at(i).second) {
			std::swap(pairs.at(i).first, pairs.at(i).second);
		}
	}
	std::cout << "after sorting pairs" << std::endl;
	for(size_t i = 0; i < pairs.size(); i++) {
		std::cout << "first: " << pairs.at(i).first << "  second: " << pairs.at(i).second << "\n";
	}
		if (has_struggler) {
		std::cout << struggler << std::endl;
	}
	*/


/*
	// split to pend and main(larger numbers)
	std::vector<int> main, pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		pend.push_back(pairs.at(i).first);
		main.push_back(pairs.at(i).second);
	}
	if(has_struggler) pend.push_back(struggler);
	for(size_t i = 0; i < main.size(); i++) {
		std::cout << main.at(i) << " ";
	}
	std::cout << std::endl;

	for(size_t i = 0; i < pairs.size(); i++) {
		std::cout << pend.at(i) << " ";
	}
	std::cout << std::endl;
 */
	return 0;
}

// receive input
// store input
// recursive part starts: split to pairs -> compare numbers in pairs -> bigger number goes to next iteration, smaller one goes to pend(follows the bigger number), single one also goes to pend -> next iteration untill one number left
// unvinde: last pend goes before main (free ind[0]) -> binary search between first and the main element that pend was following -> repeat untill all pend elements are inserted. when only one main and pend left. (main should be sorted at that point and pend should not)
// insertion of last pend to main. first insertion is free. follow Jacobthal cequence to incert pend. based on number of base elements of pend pick closest index in cequence. 0 1 1 3 5 11 ...
// do incertions of pend in correct order 1 3 2 5 4 11 10 9 8 7 6 ..
// performe binary search based on the main index position. -> repeat untill all numbers inserted
