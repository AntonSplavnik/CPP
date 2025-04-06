/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:37:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 15:11:54 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;

	_type = getType();
	_brain = new Brain();
}

Cat::Cat(const Cat& other): AAnimal(other) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other) {
		AAnimal::operator=(other);

		delete _brain;
		_brain = new Brain(*other._brain);
	}

	return (*this);
}

Cat::~Cat() {

	std::cout << getType() << " " << "Default distructor" << std::endl;

	delete _brain;
}

void Cat::makeSound() const {

	std::cout << getType() << " " << "Making a cat sound" << std::endl;
}

const char* Cat::getType() const{ return ("Cat"); }
