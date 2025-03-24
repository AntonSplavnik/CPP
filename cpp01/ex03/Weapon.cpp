/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:07 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 18:28:37 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {

}

std::string Weapon::getType() {

	return (this->_type);
}

void	Weapon::setType(std::string input) {

	this->_type = input;
}