/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:27:05 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 19:01:14 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	Contact();
	void SetContact(int index, const std::string &firstName, const std::string &lastName, const std::string &nickName);
	void PrintContacts() const;

private:
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	static std::string	FormatField(const std::string &str);
};

#endif
