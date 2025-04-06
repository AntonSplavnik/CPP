/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:26:22 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/06 12:45:50 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	  : _type(other._type) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
		_type = other._type;

	return (*this);
}

AAnimal::~AAnimal() {

	std::cout << getType() << " " << "Default distructor" << std::endl;

}

const char* AAnimal::getType () const { return ("AAnimal");}
