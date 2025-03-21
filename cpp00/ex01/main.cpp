/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:15 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 20:41:01 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int Parsing(int ac) {
	if (ac > 1)
		return (1);
	return (0);
}

bool getInput(const std::string &prompt, std::string &output)
{
	while (true) {
		std::cout << prompt << std::flush;
		if (!(std::cin >> output)) {
			std::cout << "\nEOF detected. Goodbye!" << std::endl;
			return false;
		}
		if (!output.empty())
			return true;

		std::cout << "Input cannot be empty. Please try again.\n";
	}
}

int Execution(PhoneBook &pb) {
	std::cout << "*-----------------------------------*\n"
	          << "Hello! This is a phone book program. Please enter one of the following commands:\n"
	          << "ADD: save a new contact\n"
	          << "SEARCH: display a specific contact\n"
	          << "EXIT: exit program\n" << std::endl;

	std::string input, firstName, lastName, nickName;

	while (true) {
		if (!getInput("waiting for input: ", input))
			break;

		if (input == "ADD") {
			if (!getInput("Input first name: ", firstName))
				break;
			if (!getInput("Input last name: ", lastName))
				break;
			if (!getInput("Input nick name: ", nickName))
				break;

			std::cout << "Adding to phonebook..." << std::endl;

			pb.Add(firstName, lastName, nickName);
		}
		else if (input == "SEARCH") {
			pb.Search();
		}
		else if (input == "EXIT") {
			std::cout << "Exiting..." << std::endl;
			return (1);
		}
		else {
			std::cout << "Unknown command.\n" << std::endl;
		}
	}
	return (0);
}

int	main(int ac, char **av) {

	PhoneBook pb;
	(void)av;
	if (Parsing(ac))
		return (1);
	if (Execution(pb))
		return (1);
	return (0);
}
