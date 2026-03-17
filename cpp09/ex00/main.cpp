#include <iostream>
#include "BitcoinExcahange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	if (!btc.loadDatabase("data.csv"))
		return 1;
	if (!btc.processInput(std::string(argv[1])))
		return 1;

	return 0;
}
