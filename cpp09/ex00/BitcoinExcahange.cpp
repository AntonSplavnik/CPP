#include "BitcoinExcahange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) {
		std::cout << "DB file is missing!" << std::endl;
		return false;
	}

	std::string line;
	while (getline(file, line)) {
		std::stringstream ss(line);
		if (!line.find("date")) continue;
		std::string key = ss.str().substr(0, ss.str().find_first_of(','));
		_db[key] = ss.str().substr(ss.str().find_first_of(',') + 1);
	}
	file.close();
	return true;
}

bool BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Failed to open a file!" << std::endl;
		return false;
	}

	std::string line;
	while (getline(file, line)) {
		std::stringstream ss(line);
		std::string sstring = ss.str();

		if (!sstring.find("date")) continue;

		// line validation
		if (sstring.find('|') != 11) {
			std::cout << "Error: bad input => " << sstring << std::endl;
			continue;
		}

		// date validation, valid date is always in yyyy-mm-dd
		std::string date = sstring.substr(0, sstring.find_first_of('|') - 1);
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		// value validation, valid value is a float or positive integer between 0 and 1000
		std::string value = sstring.substr(sstring.find_first_of('|') + 2);
		if (value.empty()) {
			std::cout << "Error: bad input => " << sstring << std::endl;
			continue;
		}

		int coma_counter = 0;
		bool error = false;
		for (size_t i = 0; i < value.length(); i++) {
			if ((value[i] < 48 && value[i] != 46) || value[i] > 57) {
				std::cout << "Error: not a positive number." << std::endl;
				error = true;
				break;
			}
			if (value[i] == 46) coma_counter++;
		}
		if (error) continue;
		if (coma_counter > 1) {
			std::cout << "Error: bad input => " << value << std::endl;
			continue;
		}

		std::stringstream sss(value);
		float num;
		sss >> num;
		if (sss.fail()) {
			std::cout << "Error: bad input => " << value << std::endl;
			continue;
		}
		if (num > 1000.0f) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, std::string>::iterator it = _db.upper_bound(date);
		if (it == _db.begin()) {
			std::cout << "Error: bad input => " << date << std::endl;
		} else {
			--it;
			std::cout << date << " => " << value << " = " << atof(it->second.c_str()) * num << std::endl;
		}
	}

	file.close();
	return true;
}
