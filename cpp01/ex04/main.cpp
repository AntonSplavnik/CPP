/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:18:49 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 19:46:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main (int ac, char **av) {

	if (ac != 4) {
		std::cout << "number of arguments is incorrect" << std::endl;
		return (1);
	}
	std::string fileName, string1, string2, fromFile;

	fileName = av[1];
	string1 = av[2];
	string2 = av[3];

	std::ifstream file(fileName);

	if (!file) {
		std::cerr << "Eaild to open file." << std::endl;
		return (1);
	}

	while (std::getline(file, fromFile))
		std:: cout << fromFile << std :: endl;

	for (size_t i; i < fromFile.length(); i++) {

	}
	return (0);
}