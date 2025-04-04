/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:37:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/04 22:32:30 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;
}

WrongCat::WrongCat(const std::string& name): WrongAnimal(name) {

	std::cout << getType() << " " << "Name constructor" << std::endl;
	_type = getType();
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;

}

WrongCat& WrongCat::operator=(const WrongCat& other){

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other)
	WrongAnimal::operator=(other);

	return (*this);
}

WrongCat::~WrongCat() {

	std::cout << getType() << " " << "Default distructor" << std::endl;
}

void WrongCat::makeSound() const {

	std::cout << getType() << " " << "Making a cat sound" << std::endl;
}

const char* WrongCat::getType() const{ return ("Cat"); }
