/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/04 09:48:14 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {

	std::cout << getClassName() << " "
			  << _name << " Default constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {

	std::cout << getClassName() << " "
			  << name << " Name constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {

	std::cout << getClassName() << " "
	<< _name << " Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {

	std::cout << getClassName() << " "
			  << _name << " Destructor called" << std::endl;
}

int ScavTrap::getMaxHitPoints() const { return (100); }

int ScavTrap::getMaxEnergyPoints() const { return (50); }

int ScavTrap::getMaxAttackDamage() const { return (20); }

const char* ScavTrap::getClassName() const { return ("ScavTrap");}

void ScavTrap::guardGate() {

	std::cout << getClassName() << " "
			  << _name << " is now in Gatekeeper mode" << std::endl;
}
