/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:24:45 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 23:15:48 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}
// Intern::Intern (const Intern& other){}
Intern& Intern::operator=(const Intern& other){

	if(this != &other){}
	return (*this);
}
Intern::~Intern(){}

int Intern::getFormType(std::string formName) {

	std::string types[3];
	types[0] = "presidential pardon";
	types[1] = "robotomy request";
	types[2] = "shrubbery creation";

	for (size_t i = 0; i < 3; i++)
	{
		if(types[i] == formName)
			return i;
	}
	return -1;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget){

	int formType = getFormType(formName);

	switch (formType) {
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(formTarget);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(formTarget);
		default:
			throw UnknownFormTypeException();
	}
}
