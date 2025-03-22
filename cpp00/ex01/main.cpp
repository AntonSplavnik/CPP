/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:15 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/22 18:51:01 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

void animateLoop(const std::string &base, int cycles = 6, int delayMicroseconds = 400000) {
	for (int i = 0; i < cycles; ++i) {
		int dotCount = (i % 3) + 1;
		std::string dots(dotCount, '.');
		std::string padding(3 - dotCount, ' ');
		std::cout << "\r" << base << dots << padding << std::flush;
		usleep(delayMicroseconds);
	}
	std::cout << std::endl;
}

int validateArguments(int ac) {
	if (ac > 1)
		return (1);
	return (0);
}

bool getInput(const std::string &prompt, std::string &output) {

	std::cout << prompt << std::flush;

	while (true) {
		if (!std::getline(std::cin, output)) {
			std::cout << "\nEOF detected. Goodbye!" << std::endl;
			return false;
		}

		if (output.find_first_not_of(" \t\n\r") != std::string::npos)
			return true;

		std::cout << "Input cannot be empty. Try again.\n" << prompt << std::flush;
	}
}

int runPhoneBook(PhoneBook &pb) {

	std::cout << "*******************************************\n"
	          << "Hello User! This is a phone book program.\n"
			  << "Enter one of the following commands:\n"
			  << "*------------------------------------------*\n"
	          << "ADD:    make a new contact\n"
	          << "SEARCH: display list of contacts\n"
	          << "EXIT:   exit program\n"
			  << "*******************************************\n"
			  << std::endl;

	std::string input, firstName, lastName, nickName,
				phoneNumber, darkestSecret, index;

	while (true) {
		if (!getInput("waiting for command: ", input))
			break;

		if (input == "ADD") {
			if (!getInput("input first name: ", firstName))
				break;
			if (!getInput("input last name: ", lastName))
				break;
			if (!getInput("input nick name: ", nickName))
				break;
			if (!getInput("input phone number: ", phoneNumber))
				break;
			if (!getInput("input darkest secret: ", darkestSecret))
				break;

			animateLoop("adding contact");
			pb.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
		}
		else if (input == "SEARCH") {
			pb.printListOfContacts();
			if (!getInput("input index to search: ", index))
				break;
			animateLoop("searching");
			pb.search(index);
		}
		else if (input == "EXIT") {
			animateLoop("exiting");
			return (1);
		}
		else
			std::cout << "unknown command" << std::endl;
	}
	return (0);
}

int	main(int ac, char **av) {

	PhoneBook pb;
	(void)av;

	if (validateArguments(ac))
		return (1);
	if (runPhoneBook(pb))
		return (1);

	return (0);
}

/*  LIST OF BUGS
1. index can be a character
2. while animation is active it aceps input
*/
