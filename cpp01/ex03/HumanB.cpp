/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:11 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 18:57:20 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB( std::string name ) {

	this->_name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {

	this->_weapon = &weapon;
}

void	HumanB::attack() {
	if (_weapon)
		std::cout << this->_name
				  << " attacks with their "
				  << _weapon->getType()
				  << std::endl;
	else
	std::cout << this->_name
			  <<" no weapon "
			  << std::endl;

}