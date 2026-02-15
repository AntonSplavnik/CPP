#include "iostream"
#include "fstream"
#include <sstream>
#include "map"


int parse_arguments(char* file_name) {

	(void)file_name;
	return 1;
}


int main(int argc, char **argv) {

	// (void)argv;
	// (void)argc;

	if(argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::ifstream file;
	file.open("data.csv");
	if(!file.is_open()) {
		std::cout << "DB file is missing!" << std::endl;
		return 1;
	}

	std::map<std::string, std::string> db;

	std::string line;
	while(getline(file, line)){
		std::stringstream ss(line);
		if (!line.find("date")) continue;
		std::string key = ss.str().substr(0, ss.str().find_first_of(','));
		db[key] = ss.str().substr(ss.str().find_first_of(',') + 1);
	}
	file.close();

	// std::map<std::string, std::string>::iterator it = db.begin();
	// for (; it != db.end(); ++it)
	// {
	// 	std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
	// }


	file.open(std::string(argv[1]));
	if(!file.is_open()) {
		std::cout << "Failed to open a file!" << std::endl;
		return 1;
	}

	// std::map<std::string, std::string> input;
	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string sstring = ss.str();

		if (!sstring.find("date")) continue;

		// line validation
		if (sstring.find('|') != 11) {
			std::cout << "Wrong line format" << std::endl;
			continue;
		}

		//date validation, valid date is always in yyyy-mm-dd
		std::string date = sstring.substr(0, sstring.find_first_of('|') - 1);
		if (date.length() != 10) {
			std::cout << "Invalid date format!" << std::endl;
			continue;
		}
		if(date[4] != '-' || date[7] != '-') {
			std::cout << "Invalid date format!" << std::endl;
			continue;
		}

		//value validation, valid value is a float or positive integer between 0 and 1000
		std::string value = sstring.substr(sstring.find_first_of('|') + 2);
		if(value.empty()) {
			std::cout << "Bad input" << std::endl;
			continue;
		}

		int coma_counter = 0;
		bool error = false;
		for (size_t i = 0; i < value.length(); i++) {
			if((value[i] < 48 && value[i] != 46) || value[i] > 57 ) {
				std::cout << "Bad input" << std::endl;
				error = true;
				break;
			}
			if(value[i] == 46) coma_counter++;
		}
		if (error) continue;
		if(coma_counter > 1) {
			std::cout << "Bad input" << std::endl;
			continue;
		}

		std::stringstream sss(value);
		float num;
		sss >> num;
		if(sss.fail()){
			std::cout << "convertion failed" << std::endl;
			continue;
		}
		if(num > 1000.0f) {
			std::cout << "Bad input" << std::endl;
			continue;
		}

		std::map<std::string, std::string>::iterator it = db.upper_bound(date);
		if (it == db.begin()) {
			std::cout << "No earlier date found" << std::endl;
		}
		else {
			--it;
			std::cout << it->first << " => " << value << " = " << atof(it->second.c_str()) * num << std::endl;
		}

		// std::cout << sstring << std::endl;
	}



	file.close();
	// if (parse_arguments(argv[1]))
	// 	compare_db();

	return 0;
}

/*
	1. open db.csv x
	2. store db in map? x
	3. check arguments
	4. read arguments
	5. parse arguments
	6. store arguments in map
	7. proceed with multiplication
	8. output results
*/

