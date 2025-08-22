/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:21:02 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:31:50 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
