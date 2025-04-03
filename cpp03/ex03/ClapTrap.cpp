/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/02 22:32:47 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default") {

	std::cout << getClassName() << " "
			  << _name << " Default constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

ClapTrap::ClapTrap(const std::string& name): _name(name) {

	std::cout << getClassName() << " "
			  << name << " Name constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

ClapTrap::~ClapTrap() {

	std::cout << getClassName() << " "
			  << _name << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name) {

	std::cout << getClassName() << " "
			  << _name << " Copy constructor called" << std::endl;

	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

	std::cout << getClassName() << " "
			  << _name << " is being assigned from " << other._name << std::endl;

	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

int ClapTrap::getMaxHitPoints() const { return (10); }

int ClapTrap::getMaxEnergyPoints() const { return (10); }

int ClapTrap::getMaxAttackDamage() const { return (0); }

const char* ClapTrap::getClassName() const { return ("ClapTrap");}

void ClapTrap::attack(const std::string& target) {

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
			  << _name << " attacks " << target
			  << ", dealing " << _attackDamage << " points of damage!"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (_hitPoints <= 0) {

		std::cout << getClassName() << " "
				  << _name << " is already dead!" << std::endl;
		return ;
	}

	_hitPoints = (amount >= static_cast<unsigned int> (_hitPoints))? 0 : _hitPoints - amount;

	std::cout << getClassName() << " "
			  << _name << " takes "
			  << amount << " damage. Remaining HP: "
			  << _hitPoints << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_hitPoints <= 0) {
		std::cout << getClassName() << " "
				  << _name << " is dead and cannot repair."
				  << std::endl;
		return;
	}

	if (_hitPoints == getMaxHitPoints()) {
		std::cout << getClassName() << " "
				  << _name << " already has maximum hit points."
				  << std::endl;
		return;
	}

	if (_energyPoints <= 0) {
		std::cout << getClassName() << " "
				  << _name << " has no energy to repair."
				  << std::endl;
		return;
	}

	if (_hitPoints + amount > static_cast<unsigned int>(getMaxHitPoints())) {

		_energyPoints -= 1;
		_hitPoints = getMaxHitPoints();
		std::cout << getClassName() << " "
				  << _name << " repairs itself to full health "
				  << getMaxHitPoints()
				  << std::endl;
		return;
	}

	_hitPoints += amount;
	_energyPoints -= 1;

	std::cout << getClassName() << " "
			  << _name << " repairs itself, regaining "
			  << amount << " hit points! Current HP: " << _hitPoints
			  << std::endl;
}
