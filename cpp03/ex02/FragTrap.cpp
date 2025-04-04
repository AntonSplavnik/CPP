/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:51:50 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/04 09:47:51 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {

	std::cout << getClassName() << " "
			  << _name << " Default constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {

	std::cout << getClassName() << " "
			  << name << " Name constructor called" << std::endl;

	_hitPoints = getMaxHitPoints();
	_energyPoints = getMaxEnergyPoints();
	_attackDamage = getMaxAttackDamage();
}


FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {

	std::cout << getClassName() << " "
	<< _name << " Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {

	std::cout << getClassName() << " "
			  << _name << " Destructor called" << std::endl;
}

int FragTrap::getMaxHitPoints() const { return (100); }

int FragTrap::getMaxEnergyPoints() const { return (100); }

int FragTrap::getMaxAttackDamage() const { return (30); }

const char* FragTrap::getClassName() const { return ("FragTrap");}

void FragTrap::highFivesGuys(void) {

	std::cout << getClassName() << " "
			  << _name << " is giving a high five!" << std::endl;
}

