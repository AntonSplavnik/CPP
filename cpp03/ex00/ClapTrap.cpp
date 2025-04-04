/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/04 09:50:29 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"){

	std::cout << "ClapTrap " << _name << " Default constructor called" << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name): _name(name){

	std::cout << "ClapTrap " << name << " Name constructor called" << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name) {

	std::cout << "ClapTrap " << _name << " Copy constructor called" << std::endl;

	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {

	std::cout << "ClapTrap " << _name << " is being assigned from " << other._name << std::endl;

	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}

	return *this;
}

ClapTrap::~ClapTrap() {

	std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
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

	_hitPoints = (amount >= static_cast<unsigned int> (_hitPoints))? 0 : _hitPoints - amount;

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

	if (_hitPoints == 10) {
		std::cout << "ClapTrap " << _name << " already has maximum hit points."
				  << std::endl;
		return;
	}

	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy to repair."
				  << std::endl;
		return;
	}

	if (_hitPoints + amount > 10) {

		_energyPoints -= 1;
		_hitPoints = 10;
		std::cout << "ClapTrap " << _name << " epairs itself to full health (10 HP)."
				  << std::endl;
		return;
	}

	_hitPoints += amount;
	_energyPoints -= 1;

	std::cout << "ClapTrap " << _name << " repairs itself, regaining "
			  << amount << " hit points! Current HP: " << _hitPoints
			  << std::endl;
}
