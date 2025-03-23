/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:47:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/23 12:43:40 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact() {}

void Contact::setContact(int index, const std::string &firstName,
						 const std::string &lastName, const std::string &nickName,
						 const std::string &phoneNumber, std::string & darkestSecret) {

	this->index = index + 1;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

const std::string	&Contact::getFirstName() const {
	return (this->_firstName);
}

const std::string	&Contact::getLastName() const {
	return (this->_lastName);
}

const std::string	&Contact::getNickName() const {
	return (this->_nickName);
}

const std::string	&Contact::getPhoneNumber() const {
	return (this->_phoneNumber);
}

const std::string	&Contact::getDarkestSecret() const {
	return (this->_darkestSecret);
}

std::string	Contact::_formatField(const std::string &str) const{

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void Contact::printContacts() const{

	std::cout << std::setw(10) << index << "|"
			  << _formatField(_firstName) << "|"
			  << _formatField(_lastName) << "|"
			  << _formatField(_nickName)
			  << std::endl;
}
