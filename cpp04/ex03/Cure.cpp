/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:57:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 21:50:47 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("Cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {

	if (this != &other)
		AMateria::operator=(other);

	return (*this);
}

Cure* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << " wounds *" <<std::endl;
}
