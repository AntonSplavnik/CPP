/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:27:05 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/24 18:56:08 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	Contact();

	void	setContact(int index, const std::string &firstName,
					   const std::string &lastName, const std::string &nickName,
					   const std::string &phoneNumber, std::string &darkestSecret);

	const std::string	&getFirstName() const;
	const std::string	&getLastName() const;
	const std::string	&getNickName() const;
	const std::string	&getPhoneNumber() const;
	const std::string	&getDarkestSecret() const;

	void	printContacts() const;

private:
	int			index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	std::string	_formatField(const std::string &str) const;
};

#endif
