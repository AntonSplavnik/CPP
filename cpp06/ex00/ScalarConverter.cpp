/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:35:13 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/07 19:38:29 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <limits>

/*
      STRINGSTREAM GUIDE

      Think of it as:
      - A container that holds text (like a string)
      - But you can read from it and write to it using >> and << operators (like cin/cout)

      CONSTRUCTION:
      - std::stringstream ss;              // Empty stream
      - std::stringstream ss("hello");     // Initialize with string
      - std::stringstream ss(std::string); // Initialize with string object

      How it works internally:
      1. Storage: It maintains an internal string buffer
      2. Position pointer: Keeps track of current read/write position
      3. Stream state flags: Tracks success/failure of operations

      READING OPERATIONS:
      - ss >> variable     - Extract/read data (moves position forward, skips whitespace)
      - ss.get(char)       - Read single character (including whitespace)
      - ss.getline(str, n) - Read entire line
      - ss.peek()          - Look at next character without consuming it

      WRITING OPERATIONS:
      - ss << value        - Insert/write data to stream
      - ss.put(char)       - Write single character

      POSITION CONTROL:
      - ss.seekg(0)        - Reset READ position to beginning
      - ss.seekp(0)        - Reset WRITE position to beginning
      - ss.tellg()         - Get current READ position
      - ss.tellp()         - Get current WRITE position

      ERROR HANDLING & STATE:
      - ss.fail()          - Check if last operation failed
      - ss.bad()           - Check if stream is corrupted
      - ss.good()          - Check if everything is OK
      - ss.eof()           - Check if end of stream reached
      - ss.clear()         - Reset ALL error flags

      STREAM MANIPULATORS:
      - std::fixed         - Force fixed-point notation (no scientific)
      - std::setprecision(n) - Set decimal places
      - std::setw(n)       - Set field width
      - std::left/right    - Alignment

      UTILITY:
      - ss.str()           - Get entire stream content as string
      - ss.str("new")      - Replace entire stream content

      COMMON PATTERNS:
      // Reset for reuse:
      ss.clear();          // Clear error flags
      ss.seekg(0);         // Reset position

      // Check complete conversion:
      ss >> value;
      if (!ss.fail() && ss.eof()) // Success AND consumed entire input

      Difference between read methods:
      - get() - Reads ALL characters including spaces and newlines
      - >>    - Skips whitespace characters (spaces, tabs, newlines)
  */

bool isValidNumber(std::string input, LiteralType type){

	if(type == INT){
		for (size_t i = 0; i < input.length(); i++)
			if(input[i] < '0' || input[i] > '9') return false;
	}
	else if(type == FLOAT){
			for (size_t i = 0; i < input.length(); i++)
			if((input[i] < '0' || input[i] > '9') && !(input[i] == '.') && !(i == input.length() - 1 && input[i] == 'f')) return false;
	}
	else if(type == DOUBLE){
					for (size_t i = 0; i < input.length(); i++)
			if((input[i] < '0' || input[i] > '9') && !(input[i] == '.')) return false;
	}
	return true;
}

void handleChar(std::string input){

	char inputChar;
	if(input[0] == '\'')
		inputChar = input[1];
	else
		inputChar = input[0];

	int intValue = static_cast<int>(inputChar);
	float floatValue = static_cast<float>(inputChar);
	double doubleValue = static_cast<double>(inputChar);

	std::cout << "char:   " << "'" << inputChar << "'" << std::endl;
	std::cout << "int:    " << intValue << std::endl;
	std::cout << "float:  " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue  << std::endl;
	return;
}

void handleInt(std::string input, LiteralType type){

	std::stringstream ss(input);
	double convertedDouble;
	ss >> convertedDouble;
	if(ss.fail()){
		if(isValidNumber(input, type)){
			std::cout << "char:   impossible" << std::endl;
			std::cout << "int:    impossible" << std::endl;
			std::cout << "float:  impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		else{
			std::cout << "Parsing error" << std::endl;
			return;
		}
	}
	ss.clear();
	ss.seekg(0);

	if(convertedDouble > std::numeric_limits<int>::max() || convertedDouble < std::numeric_limits<int>::min())
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int convertedInput;
	ss >> convertedInput;
	if(ss.fail()){
		std::cout << "Conversion error" << std::endl;
		return;
	}

	float floatValue = static_cast<float>(convertedInput);
	double doubleValue = static_cast<double>(convertedInput);

	if (convertedInput >= 32 && convertedInput <= 126)
		std::cout << "char:   " << "'" << static_cast<char>(convertedInput) << "'"<< std::endl;
	else if (convertedInput >= 0 && convertedInput <= 127)
		std::cout << "char:   Non displayable" << std::endl;
	else
		std::cout << "char:   impossible" << std::endl;

	std::cout << "int:    " << convertedInput << std::endl;
	std::cout << "float:  " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue  << std::endl;
	return;

}

void handleFloat(std::string input, LiteralType type){

	std::string parsedStr = input;
	int precision = 1;

	if(input.find('.') != std::string::npos){
		size_t dotPos = input.find('.');

		//decimal point position
		if(dotPos == input.length() - 1){
			std::cout << "parsing error" << std::endl;
			return;
		}

		char afterDot = input[dotPos + 1];
		if(afterDot < '0' || afterDot > '9') {
			std::cout << "parsing error" << std::endl;
			return;
		}

		//multiple decimal points
		int dotCount = 0;
		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] == '.')
				dotCount++;
		}
		if (dotCount > 1) {
			std::cout << "parsing error" << std::endl;
			return;
		}

		//precision counter
		precision = 0;
		for(size_t i = dotPos; i < input.length(); i++) {
			if(input[i] == 'f')
				break;
			if(input[i] != '.')
				precision++;
			if(precision == 18)
				break;
		}
	}

	//'f' at wrong position
	size_t fPos = input.find('f');
	if (fPos != std::string::npos && fPos != input.length() - 1) {
		std::cout << "parsing error" << std::endl;
		return;
	}

	//'f' removal
	if(input.length() > 1 && input[input.length() - 1] == 'f')
		parsedStr = input.substr(0, input.length() - 1);

	std::stringstream ss(parsedStr);
	double convertedDouble;
	ss >> convertedDouble;
	if(ss.fail() || !ss.eof()){
		if(isValidNumber(input, type)){
			std::cout << "char:   impossible" << std::endl;
			std::cout << "int:    impossible" << std::endl;
			std::cout << "float:  impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		else{
			std::cout << "Parsing error" << std::endl;
			return;
		}
	}
	ss.clear();
	ss.seekg(0);

	if(convertedDouble > std::numeric_limits<float>::max() || convertedDouble < -std::numeric_limits<float>::max())
	{
		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	float convertedInput;
	ss >> convertedInput;

	int intValue = static_cast<int>(convertedInput);
	double doubleValue = static_cast<double>(convertedInput);

	if (convertedInput >= 32 && convertedInput <= 126)
		std::cout << "char:   " << "'" << static_cast<char>(convertedInput) << "'"<< std::endl;
	else if (convertedInput >= 0 && convertedInput <= 127)
		std::cout << "char:   Non displayable" << std::endl;
	else
		std::cout << "char:   impossible" << std::endl;

	if(convertedInput > std::numeric_limits<int>::max() || convertedInput < std::numeric_limits<int>::min())
		std::cout << "int:    impossible" << std::endl;
	else
		std::cout << "int:    " << intValue << std::endl;

	std::cout << "float:  " << std::fixed << std::setprecision(precision) << convertedInput << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << doubleValue  << std::endl;
	return;
}


void handleDouble(std::string input, LiteralType type){

	int precision = 1;

	if (input.find('.') != std::string::npos){
		size_t dotPos = input.find('.');

		//decimal point position
		if(dotPos == input.length() - 1){
			std::cout << "parsing error" << std::endl;
			return;
		}

		char afterDot = input[dotPos + 1];
		if(afterDot < '0' || afterDot > '9') {
			std::cout << "parsing error" << std::endl;
			return;
		}

		//multiple decimal points
		int dotCount = 0;
		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] == '.')
				dotCount++;
		}
		if (dotCount > 1) {
			std::cout << "parsing error" << std::endl;
			return;
		}

		//precision counter
		precision = 0;
		for(size_t i = dotPos; i < input.length(); i++) {
			if(input[i] == 'f')
				break;
			if(input[i] != '.')
				precision++;
			if(precision == 18)
				break;
		}
	}

	std::stringstream ss(input);
	double convertedInput;
	ss >> convertedInput;
	if(ss.fail()){
		if(isValidNumber(input, type)){
			std::cout << "char:   impossible" << std::endl;
			std::cout << "int:    impossible" << std::endl;
			std::cout << "float:  impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		else{
			std::cout << "Parsing error" << std::endl;
			return;
		}
	}
	ss.clear();
	ss.seekg(0);

	int intValue = static_cast<int>(convertedInput);
	float floatleValue = static_cast<float>(convertedInput);

	if (convertedInput >= 32 && convertedInput <= 126)
		std::cout << "char:   " << "'" << static_cast<char>(convertedInput) << "'"<< std::endl;
	else if (convertedInput >= 0 && convertedInput <= 127)
		std::cout << "char:   Non displayable" << std::endl;
	else
		std::cout << "char:   impossible" << std::endl;


	if(convertedInput > std::numeric_limits<int>::max() || convertedInput < std::numeric_limits<int>::min())
		std::cout << "int:    impossible" << std::endl;
	else
		std::cout << "int:    " << intValue << std::endl;

	std::cout << "float:  " << std::fixed << std::setprecision(precision) << floatleValue << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << convertedInput  << std::endl;
	return;

}

void handleSpecial(std::string input){

if(input == "-inff" || input == "inff" || input == "+inff" || input == "nanf"){

		if(input == "-inff"){
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "-inff" << std::endl;
			std::cout << "double: " << "-inf" << std::endl;
		}
		else if(input == "+inff" || input == "inff"){
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "+inff" << std::endl;
			std::cout << "double: " << "+inf" << std::endl;
		}
		else{
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
		return;
	}
	else if(input == "-inf" || input == "+inf" || input == "inf"|| input == "nan"){

		if(input == "-inf"){
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "-inff" << std::endl;
			std::cout << "double: " << "-inf" << std::endl;
		}
		else if(input == "+inf" || input == "inf"){
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "+inff" << std::endl;
			std::cout << "double: " << "+inf" << std::endl;
		}
		else{
			std::cout << "char:   " << "impossible" << std::endl;
			std::cout << "int:    " << "impossible" << std::endl;
			std::cout << "float:  " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
		return;
	}

}

bool isValidInput(std::string input){

	if(input.empty())
		return false;

	//sign placement (+ or -):
	size_t plusCount = 0;
	size_t minusCount = 0;
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == '+')
			plusCount++;
		if (input[i] == '-')
			minusCount++;
	}

	//only one sign at the beginning
	if (plusCount > 1 || minusCount > 1 || (plusCount > 0 && minusCount > 0)) {
		std::cout << "parsing error" << std::endl;
		return false;
	}

	size_t tickPos = input.find('\'');
	size_t plusPos = input.find('+');
	size_t minusPos = input.find('-');
	if ((plusPos != std::string::npos && plusPos != 0
		&& !(tickPos == 0 && plusPos == 1))
		|| (minusPos != std::string::npos && minusPos != 0
		&& !(tickPos == 0 && minusPos == 1))) {
		std::cout << "parsing error" << std::endl;
		return false;
	}


	return true;
}

LiteralType detectType(std::string input){

	if (input.length() == 3 && input[0] == '\'' && input[2] == '\''){
		// std::cout << "CHAR" << std::endl;
		return CHAR;
	}
	if (input.length() == 1 && (input[0]>= 0 && input[0] <= 127) && !(input[0] >= '0' && input[0] <= '9')){
		// std::cout << "CHAR" << std::endl;
		return CHAR;
	}
	if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan" || input == "inff" || input == "-inff" || input == "+inff" || input == "nanf"){
		// std::cout << "SPECIAL" << std::endl;
		return SPECIAL;
	}
	if (input[input.length() - 1 ] == 'f' && input.find('.') != std::string::npos){
		// std::cout << "FLOAT" << std::endl;
		return FLOAT;
	}
	if (input.find('.') != std::string::npos){
		// std::cout << "DOUBLE" << std::endl;
		return DOUBLE;
	}
	// std::cout << "INT" << std::endl;
	return INT;
}

void ScalarConverter::convert(std::string input) {

	if (!isValidInput(input)) {
		std::cout << "Invalid input" << std::endl;
		return;
	}

	LiteralType type = detectType(input);

	switch(type){
		case CHAR:
			handleChar(input);
			break;
		case INT:
			handleInt(input, type);
			break;
		case DOUBLE:
			handleDouble(input, type);
			break;
		case FLOAT:
			handleFloat(input, type);
			break;
		case SPECIAL:
			handleSpecial(input);
			break;
	}
}
