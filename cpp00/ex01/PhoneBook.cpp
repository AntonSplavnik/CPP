/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:13 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 20:41:11 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook() : numberOfContacts(0), nextIndex(0) {}

void PhoneBook::Add(const std::string &firstName, const std::string &lastName, const std::string &nickName) {

	contacts[nextIndex].SetContact(nextIndex, firstName, lastName, nickName);
	nextIndex = (nextIndex + 1) % 8;
	if (numberOfContacts < 8)
		numberOfContacts++;
}

void	PhoneBook::Search() const{

	std::cout << std::setw(10) << "index" <<  "|"
			<< std::setw(10) << "first name" << "|"
			<< std::setw(10) << "last name" << "|"
			<< std::setw(10) << "nick name" << "|" << std::endl;

	for (int i = 0; i < numberOfContacts; i++)
		contacts[i].PrintContacts();
}
