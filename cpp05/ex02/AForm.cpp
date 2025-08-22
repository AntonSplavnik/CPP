/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:47:14 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 21:13:16 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream& operator<<(std::ostream& out, const AForm& form){

	out << "name: " << form.getName() << std::endl
		<< "status: " << ((form.getSigneStatus()) ?  "signed" : "unsigned") << std::endl
		<< "signe grade: " << form.getSigneGrade() << std::endl
		<< "execute grade: " << form.getExecuteGrade() << std::endl;
	return out;
}

AForm::AForm(const std::string name, unsigned char signeGrade, unsigned char executeGrade)
	:_name(name),
	_signeGrade(validateGrade(signeGrade)),
	_executeGrade(validateGrade(executeGrade)){

	_signed = false;
}

AForm::AForm(const AForm& other)
	:_name(other._name),
	_signeGrade(other._signeGrade),
	_executeGrade(other._executeGrade){

	_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other){

	if(this != &other){
		_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm(){}


std::string AForm::getName() const { return _name; }
bool AForm::getSigneStatus() const { return _signed; }
short AForm::getSigneGrade() const { return _signeGrade; }
short AForm::getExecuteGrade() const {return _executeGrade; }


short AForm::validateGrade(unsigned char grade){

	if(grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;

}

bool AForm::beSigned(const Bureaucrat& bureaucrat){

	if (bureaucrat.getGrade() <= _signeGrade) {
		_signed = true;
		return true;
	}
	else
		throw GradeTooLowException();
}

void AForm::requiermentsCheck(const Bureaucrat& bureaucrat) const{

	if(!_signed)
		throw FormIsNotSignedException();
	if (bureaucrat.getGrade() > _executeGrade)
		throw GradeTooLowException();
}
