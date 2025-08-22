/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:20:57 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 15:38:30 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
* PresidentialPardonForm: Required grades: sign 25, exec 5.
* Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

PresidentialPardonForm::PresidentialPardonForm(const std::string formTarget)
	: AForm("PresidentialPardonForm", 25, 5), _formTarget(formTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other), _formTarget(other._formTarget){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other) {
// Can't call AForm::operator= because it's private
// Can't assign const members anyway
// Only non-const members could be assigned:
// _formTarget = other._formTarget;  // But _formTarget is const too!
}
return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{

	requiermentsCheck(executor);

	std::cout << _formTarget << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
