/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:07:50 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/07 14:08:26 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name): _name(name) {

	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}


Character::Character(const Character& other): _name(other._name) {

	for (int i = 0; i < 4; i++){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
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
				_inventory[i] = 0;
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

	int i = 0;
	while (i < 4) {
		if (_inventory[i])
			i++;
		else {
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {

	if (idx < 0 || idx > 3) {
		std::cout << "critical error!";
		return ;
	}

	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
