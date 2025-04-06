/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:39:40 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/06 15:11:24 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;

	_type = getType();
	_brain = new Brain();
}

Dog::Dog(const Dog& other): AAnimal(other) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other) {
		AAnimal::operator=(other);

		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return (*this);
}

Dog::~Dog() {

	std::cout << getType() << " " << "Default distructor" << std::endl;

	delete _brain;
}

void Dog::makeSound() const {

	std::cout << getType() << " " << "Making a dog sound" << std::endl;
}

const char* Dog::getType () const { return ("Dog");}
