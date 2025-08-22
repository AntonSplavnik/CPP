/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:21:02 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 15:26:33 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized successfully
 50% of the time. Otherwise, it informs that the robotomy failed.
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string formTarget)
	: AForm("RobotomyRequestForm", 72, 45), _formTarget(formTarget){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _formTarget(other._formTarget){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		// Can't call AForm::operator= because it's private
		// Can't assign const members anyway
		// Only non-const members could be assigned:
		// _formTarget = other._formTarget;  // But _formTarget is const too!
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{

	requiermentsCheck(executor);

	std::cout << "Makeing some drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << _formTarget << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _formTarget << std::endl;
}
