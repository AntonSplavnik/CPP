/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:13 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/22 22:57:28 by antonsplavn      ###   ########.fr       */
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

void PhoneBook::search(const int indexToSearch) const {

	std::cout << "First name:     " << _contacts[indexToSearch].getFirstName()
			  << std::endl;
	std::cout << "Second name:    " << _contacts[indexToSearch].getLastName()
			  << std::endl;
	std::cout << "Nick name:      " << _contacts[indexToSearch].getNickName()
			  << std::endl;
	std::cout << "Phone number:   " << _contacts[indexToSearch].getPhoneNumber()
			  << std::endl;
	std::cout << "Darkest secret: " << _contacts[indexToSearch].getDarkestSecret()
			  << std::endl;
}

int const &PhoneBook::getNumberOfContacts() {
	return (this->_numberOfContacts);
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
