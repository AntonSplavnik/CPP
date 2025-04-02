/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/02 18:39:42 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {

	std::cout << "Default Constructor of ScavTrap called" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {

	std::cout << "Constructor of ScavTrap called" << std::endl;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {

	std::cout << "Destructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {

	std::cout << "Copy constructor of ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {

	std::cout << "Copy assignment operator of ScavTrap called" << std::endl;

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {

	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {

	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " is too dead to attack!" << std::endl;
		return;
	}

	if (_energyPoints <=0){
		std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
		return;
	}

	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " launches a powerful attack on "
			  << target << ", dealing " << _attackDamage << " points of damage!"
			  << std::endl;
}

