/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:15 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/23 00:14:11 by antonsplavn      ###   ########.fr       */
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

bool isNumber(const std::string &str) {
	if (str.empty())
		return (false);

	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

bool getInput(const std::string &prompt, std::string &output) {

	std::cout << prompt << std::flush;

	while (true) {
		if (!std::getline(std::cin, output)) {
			std::cout << "\nEOF detected. Goodbye!" << std::endl;
			return (false);
		}

		if (output.find_first_not_of(" \t\n\r") != std::string::npos)
			return (true);

		std::cout << "Input cannot be empty. Try again.\n" << prompt << std::flush;
	}
}

int addCommand(PhoneBook &phoneBook) {

	std::string input, firstName, lastName, nickName, phoneNumber, darkestSecret;

	if (!getInput("input first name: ", firstName))
		return 1;
	if (!getInput("input last name: ", lastName))
		return 1;
	if (!getInput("input nick name: ", nickName))
		return 1;
	if (!getInput("input phone number: ", phoneNumber))
		return 1;
	if (!getInput("input darkest secret: ", darkestSecret))
		return 1;

	animateLoop("adding contact");
	phoneBook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);

	return (0);
}

int searchCommand(PhoneBook &phoneBook) {
	phoneBook.printListOfContacts();

	std::string	index;
	int			indexToInt;

	while (true) {
		if (!getInput("input index to search: ", index))
			continue;

		if (!isNumber(index)) {
			std::cout << "Invalid input: index must be a number" << std::endl;
			continue;
		}

		indexToInt = std::atoi(index.c_str());
		indexToInt -= 1;

		if (indexToInt < 0 || indexToInt >= phoneBook.getNumberOfContacts()) {
			std::cout << "Invalid index" << std::endl;
			continue;
		}
		break;
	}

	animateLoop("searching");
	phoneBook.search(indexToInt);
	return (0);
}

int runPhoneBook(PhoneBook &phoneBook) {

	std::cout << "*******************************************\n"
	          << "Hello User! This is a phone book program.\n"
			  << "Enter one of the following commands:\n"
			  << "*------------------------------------------*\n"
	          << "ADD:    make a new contact\n"
	          << "SEARCH: display list of contacts\n"
	          << "EXIT:   exit program\n"
			  << "*******************************************\n"
			  << std::endl;

	std::string input;

	while (true) {
		if (!getInput("waiting for command: ", input))
			break;

		if (input == "ADD") {
			addCommand(phoneBook);
		}
		else if (input == "SEARCH") {
			searchCommand(phoneBook);
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

	PhoneBook phoneBook;
	(void)av;

	if (validateArguments(ac))
		return (1);
	if (runPhoneBook(phoneBook))
		return (1);

	return (0);
}
