/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:18:49 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/26 16:17:20 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>


std::string replaceString(std::string const &fromFile, std::string const &string1, std::string const &string2) {

	std::string toFile;

	size_t i = 0;
	while (i < fromFile.length()) {

		if (i <= fromFile.length() - string1.length() &&
			fromFile[i] == string1[0] &&
			fromFile[i + (string1.length() - 1)] == string1[string1.length() - 1] &&
			fromFile.compare(i, string1.length(), string1) == 0) {

			toFile += string2;
			i += string1.length();
		}
		else{
			toFile += fromFile[i];
			i++;
		}
	}

	// removes last unnececary \n line in toFile it might come from rading a file.
	if (!fromFile.empty() && fromFile[fromFile.length() - 1] != '\n' &&
		!toFile.empty() && toFile[toFile.length() - 1] == '\n')
		toFile.erase(toFile.length() - 1);

	return (toFile);
}

int main (int ac, char **av) {

	if (ac != 4) {
		std::cout << "number of arguments is incorrect" << std::endl;
		return (1);
	}
	if (std::string(av[2]).empty()) {
		std::cout << "Emty string found" << std::endl;
		return (1);
	}


	std::string fileName = av[1];
	std::string	string1 = av[2];
	std::string	string2 = av[3];
	std::string fromFile, toFile, line;

	std::ifstream reading(fileName.c_str());

	if (!reading) {
		std::cerr << "Faild to open file." << std::endl;
		return (1);
	}

	while (std::getline(reading, line)){
		fromFile += line;
		fromFile += "\n";
	}

	toFile += replaceString(fromFile, string1, string2);

	std::ofstream writing((fileName + ".replace").c_str());

	if (!writing) {
		std::cerr << "Failed to open file for writing." << std::endl;
		return 1;
	}

	writing << toFile;
	writing.close();
	return (0);
}

/*
void replaceString(std::string &fromFile, std::string const &string1, std::string const &string2) {
	std::string original = fromFile;

	for (size_t i = 0; i <= fromFile.length() - string1.length();) {
		if (fromFile[i] == string1[0] &&
			fromFile[i + (string1.length() - 1)] == string1[string1.length() - 1] &&
			fromFile.compare(i, string1.length(), string1) == 0) {

			fromFile.erase(i, string1.length());
			fromFile.insert(i, string2);
			i += string2.length();
		}
		else
			i++;
	}

	if (!original.empty() && original[original.length() - 1] != '\n' &&
		!fromFile.empty() && fromFile[fromFile.length() - 1] == '\n') {
		fromFile.erase(fromFile.length() - 1);
	}
}

int main (int ac, char **av) {

	if (ac != 4) {
		std::cout << "number of arguments is incorrect" << std::endl;
		return (1);
	}
	else {
		if (std::string(av[2]).empty()) {
			std::cout << "Emty string found" << std::endl;
			return (1);
		}
	}

	std::string fileName = av[1];
	std::string	string1 = av[2];
	std::string	string2 = av[3];
	std::string fromFile, line;

	std::ifstream reading(fileName.c_str());
	if (!reading) {
		std::cerr << "Faild to open file." << std::endl;
		return (1);
	}

	while (std::getline(reading, line)){
		fromFile += line;
		fromFile += "\n";
	}

	replaceString(fromFile, string1, string2);

	std::ofstream writing((fileName + ".replace").c_str());
	if (!writing) {
		std::cerr << "Failed to open file for writing." << std::endl;
		return 1;
	}

	writing << fromFile;
	writing.close();

	return (0);
}
 */