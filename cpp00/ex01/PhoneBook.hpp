/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:09 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/22 22:57:54 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {
public:

	PhoneBook();

	void		 add(const std::string &firstName, const std::string &lastName,
					 const std::string &nickName, const std::string &phoneNumber,
					 std::string &darkestSecret);
	void		 printListOfContacts();
	void		 search(const int indextToSearch) const;
	void		 exit();
	const int	&getNumberOfContacts();

private:

	Contact	_contacts[8];
	int		_numberOfContacts;
	int		_nextIndex;

	void	_printHeader() const;
};

#endif
