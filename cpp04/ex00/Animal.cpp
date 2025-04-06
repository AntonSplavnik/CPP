/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:26:22 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/06 14:25:24 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;
}

Animal::Animal(const Animal& other)
	  : _type(other._type) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
		_type = other._type;

	return (*this);
}

Animal::~Animal() {

	std::cout << getType() << " " << "Default distructor" << std::endl;

}

const char* Animal::getType () const { return ("Animal");}

void Animal::makeSound() const {

	std::cout << getType() << " " << "Making an animal sound" << std::endl;
}
