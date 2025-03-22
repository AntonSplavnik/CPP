/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:13 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/22 18:24:28 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook() : _numberOfContacts(0), _nextIndex(0) {}

void PhoneBook::add(const std::string &firstName, const std::string &lastName,
					const std::string &nickName, const std::string &phoneNumber,
					std::string &darkestSecret) {

	_contacts[_nextIndex].setContact(_nextIndex, firstName, lastName, nickName,
									 phoneNumber, darkestSecret);

	_nextIndex = (_nextIndex + 1) % 8;

	if (_numberOfContacts < 8)
		_numberOfContacts++;
}

void PhoneBook::search(std::string indexToSearch) const {

	int indexToInt = std::atoi(indexToSearch.c_str());
	indexToInt -= 1;

	std::cout << indexToSearch << std::endl;
	std::cout << indexToInt << std::endl;

	if (indexToInt < 0 || indexToInt >= this->_numberOfContacts) {
		std::cout << "Invalid index" << std::endl;
		return;
	}

	std::cout << "First name:     " << _contacts[indexToInt].getFirstName()
			  << std::endl;
	std::cout << "Second name:    " << _contacts[indexToInt].getLastName()
			  << std::endl;
	std::cout << "Nick name:      " << _contacts[indexToInt].getNickName()
			  << std::endl;
	std::cout << "Phone number:   " << _contacts[indexToInt].getPhoneNumber()
			  << std::endl;
	std::cout << "Darkest secret: " << _contacts[indexToInt].getDarkestSecret()
			  << std::endl;
}

void PhoneBook::_printHeader() const {

	std::cout << std::setw(10) << "index" <<  "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nick name" << std::endl;
}

void PhoneBook::printListOfContacts() {

	PhoneBook::_printHeader();

	for (int i = 0; i < _numberOfContacts; i++)
	_contacts[i].printContacts();
}

/* bool	isNumber() {

} */
