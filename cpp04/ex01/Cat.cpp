/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:37:36 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/09 16:39:12 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {

	std::cout << getType() << " " << "Default constructor" << std::endl;

	_brain = new Brain();
	_type = getType();
}

Cat::Cat(const Cat& other): Animal(other) {

	std::cout << getType() << " " << "Default copy constructor" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other){

	std::cout << getType() << " " << "Default assingment operator" << std::endl;

	if (this != &other) {
		Animal::operator=(other);

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

void Cat::addIdea(const std::string& idea) {

	_brain->addIdea(idea);
}

void Cat::printIdeas() const {

	_brain->printAllIdeas();
}