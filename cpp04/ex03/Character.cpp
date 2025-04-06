/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:07:50 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 22:37:20 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name): _name(name) {

	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}


Character::Character(const Character& other): _name(other._name) {

	for (int i = 0; i < 4; i++){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other) {

	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++){
			delete _inventory[i];

			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character() {

	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

const std::string& Character::getName() const { return (_name); }

void Character::equip(AMateria* m) {

	for (int i = 0; i < 4; i++){
		if (_inventory[i])
			i++;
	else
		_inventory[i] = m;
	}
}

void Character::unequip(int idx) {

	if (idx < 0 || idx > 3) {
		std::cout << "critical error!";
		return ;
	}

	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {

	
}
