/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:14 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 18:40:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA( std::string name, Weapon &weapon )
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() {

	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}