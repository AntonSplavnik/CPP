/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:57:08 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/07 14:45:17 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {

	if (this != &other)
		AMateria::operator=(other);

	return (*this);
}

Cure::~Cure() {}

Cure* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
