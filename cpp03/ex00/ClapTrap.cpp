/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/02 11:49:14 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	std::cout << "Default Constructor called" << std::endl;

	_name = "Default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << "ClapTrap " << name << " created!" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

ClapTrap::~ClapTrap() {

	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {

	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}


void ClapTrap::attack(const std::string& target) {

	if (_hitPoints <= 0) {

		std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
		return ;
	}

	if (_energyPoints <= 0) {

		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!"
			  << std::endl;

	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (_hitPoints <= 0) {

		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}

	_hitPoints -= amount;

	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << "ClapTrap " << _name << " takes "
			  << amount << " damage. Remaining HP: "
			  << _hitPoints << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot repair."
				  << std::endl;
		return;
	}

	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy to repair."
				  << std::endl;
		return;
	}

	_hitPoints += amount;
	_energyPoints += 1;

	std::cout << "ClapTrap " << _name << " repairs itself, regaining "
			  << amount << " hit points! Current HP: " << _hitPoints
			  << std::endl;
}
