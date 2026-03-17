#ifndef BITCOINEXCAHANGE_HPP
#define BITCOINEXCAHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool loadDatabase(const std::string& filename);
		bool processInput(const std::string& filename);

	private:
		std::map<std::string, std::string> _db;
};

#endif
