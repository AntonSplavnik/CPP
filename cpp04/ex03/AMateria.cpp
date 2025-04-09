/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:39:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/07 14:24:13 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) { this->type = type; }

AMateria::AMateria(const AMateria& other) { this->type = other.type; }

AMateria& AMateria::operator=(const AMateria& other) {

	if(this != &other)
		this->type = other.type;

	return (*this);
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return (type); }
