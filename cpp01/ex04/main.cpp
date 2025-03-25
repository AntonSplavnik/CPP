/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:18:49 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/26 00:06:17 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceString(std::string const &fromFile, std::string const &string1, std::string const &string2) {

	std::string toFile;

	for (size_t i = 0; i <= fromFile.length() - string1.length();) {

		if (fromFile[i] == string1[0] &&
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

	toFile += fromFile.substr(fromFile.length() - string1.length());
	return (toFile);
}

int main (int ac, char **av) {

	if (ac != 4) {
		std::cout << "number of arguments is incorrect" << std::endl;
		return (1);
	}
	std::string fileName = av[1];
	std::string	string1 = av[2];
	std::string	string2 = av[3];
	std::string fromFile, toFile, line;

	std::ifstream reading(fileName);

	if (!reading) {
		std::cerr << "Faild to open file." << std::endl;
		return (1);
	}

	while (std::getline(reading, line)){
		fromFile += line;
		fromFile += "\n";
	}

	toFile += replaceString(fromFile, string1, string2);

	std::ofstream writing(fileName + ".replace");

	if (!writing) {
		std::cerr << "Failed to open file for writing." << std::endl;
		return 1;
	}

	writing << toFile;
	writing.close();
	return (0);
}
