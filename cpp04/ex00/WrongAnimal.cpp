/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:26:22 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/04 22:20:53 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name)
	  :_name(name), _type(getType()){

	std::cout << getType() << " " << "Name constructor" << std::endl;

	// _type = getType();
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	  : _name(other._name), _type(other._type) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
		_name = other._name;
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
