/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:47:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 19:00:56 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact() {}

void	Contact::SetContact(int index, const std::string &firstName, const std::string &lastName, const std::string &nickName)
{
	this->index = index + 1;
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
}

static std::string	FormatField(const std::string &str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void	Contact::PrintContacts() const {
	std::cout << std::setw(10) << index << "|"
			<< ::FormatField(firstName) << "|"
			<< ::FormatField(lastName) << "|"
			<< ::FormatField(nickName) << "|" << std::endl;
}
