/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:57:02 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 21:50:38 by antonsplavn      ###   ########.fr       */
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

Ice* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
