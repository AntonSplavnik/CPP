/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:09 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/03/21 18:29:11 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {
public:
	PhoneBook();
	void	Add(const std::string &firstName, const std::string &lastName, const std::string &nickName);
	void	Search() const;
	void	Exit();

private:
	Contact		contacts[8];
	int			numberOfContacts;
	int			nextIndex;
};

#endif
