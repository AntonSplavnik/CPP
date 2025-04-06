/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:26:22 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/06 14:30:25 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	  : _type(other._type) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
		_type = other._type;

	return (*this);
}

WrongAnimal::~WrongAnimal() {

	std::cout << getType() << " " << "Default distructor" << std::endl;

}

const char* WrongAnimal::getType () const { return ("WrongAnimal");}

void WrongAnimal::makeSound() const {

	std::cout << getType() << " " << "Making an animal sound" << std::endl;
}
