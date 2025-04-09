/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:57:02 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/07 15:16:23 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") { }

Ice::Ice(const Ice& other): AMateria(other) { }

Ice& Ice::operator=(const Ice& other) {

	if(this != &other)
		AMateria::operator=(other);

	return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
