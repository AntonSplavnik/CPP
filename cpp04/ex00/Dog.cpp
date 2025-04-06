/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:39:40 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/06 14:28:15 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;

	_type = getType();
}

Dog::Dog(const Dog& other): Animal(other) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
		Animal::operator=(other);

	return (*this);
}

Dog::~Dog() {

	std::cout << getType() << " " << "Default distructor" << std::endl;
}

void Dog::makeSound() const {

	std::cout << getType() << " " << "Making a dog sound" << std::endl;
}

const char* Dog::getType () const { return ("Dog");}
