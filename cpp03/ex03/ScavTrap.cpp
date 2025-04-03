/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/03 21:33:36 by antonsplavn      ###   ########.fr       */
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

ScavTrap::~ScavTrap() {

	std::cout << getClassName() << " "
			  << _name << " Destructor called" << std::endl;
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

int ScavTrap::getMaxHitPoints() const { return (100); }

int ScavTrap::getMaxEnergyPoints() const { return (50); }

int ScavTrap::getMaxAttackDamage() const { return (20); }

const char* ScavTrap::getClassName() const { return ("ScavTrap");}

void ScavTrap::attack(const std::string& target) {

	if (_hitPoints <= 0) {

		std::cout << getClassName() << " "
				  << _name << " is dead and can't attack." << std::endl;
		return ;
	}

	if (_energyPoints <= 0) {

		std::cout << getClassName() << " "
				  << _name << " has no energy left!" << std::endl;
		return ;
	}

	_energyPoints -= 1;

	std::cout << getClassName() << " "
			  << "[ScavTrap override] "
			  << _name << " attacks " << target
			  << ", dealing " << _attackDamage << " points of damage!"
			  << std::endl;

}

void ScavTrap::guardGate() {

	std::cout << getClassName() << " "
			  << _name << " is now in Gatekeeper mode" << std::endl;
}
