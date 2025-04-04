/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:28:07 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/04 09:51:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
			: ClapTrap(), ScavTrap(), FragTrap(), _name("Default") {

	std::cout << getClassName() << " "
			  << _name << " Default constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

DiamondTrap::DiamondTrap(const std::string& name)
			: ClapTrap(name + "_clap_name"),
			  ScavTrap(), FragTrap() , _name(name){

	std::cout << getClassName() << " "
			  << name << " Name constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), ScavTrap(other),
FragTrap(other), _name(other._name) {

	std::cout << getClassName() << " "
	<< _name << " Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}

	return *this;
}

DiamondTrap::~DiamondTrap() {

	std::cout << getClassName() << " "
			  << _name << " Destructor called" << std::endl;
}

int DiamondTrap::getMaxHitPoints() const { return (100); } // From FragTrap

int DiamondTrap::getMaxEnergyPoints() const { return (50); } // From ScavTrap

int DiamondTrap::getMaxAttackDamage() const { return (30); } // From FragTrap

const char* DiamondTrap::getClassName() const { return ("DiamondTrap");}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap named " << _name
			  << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
