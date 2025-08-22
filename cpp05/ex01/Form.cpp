/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:47:14 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:16:28 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std::ostream& out, const Form form){

	out << "name: " << form.getName() << std::endl
		<< "status: " << ((form.getSigneStatus()) ?  "signed" : "unsigned") << std::endl
		<< "signe grade: " << form.getSigneGrade() << std::endl
		<< "execute grade: " << form.getExecuteGrade();
	return out;
}

Form::Form(const std::string name, unsigned char signeGrade, unsigned char executeGrade)
	:_name(name),
	_signeGrade(ValidateGrade(signeGrade)),
	_executeGrade(ValidateGrade(executeGrade)){

	_signed = false;
}

Form::Form(const Form& other)
	:_name(other._name),
	_signeGrade(other._signeGrade),
	_executeGrade(other._executeGrade){

	_signed = other._signed;
}

Form& Form::operator=(const Form& other){

	if(this != &other){
		_signed = other._signed;
	}
	return (*this);
}

Form::~Form(){}


std::string Form::getName() const { return _name; }
bool Form::getSigneStatus() const { return _signed; }
short Form::getSigneGrade() const { return _signeGrade; }
short Form::getExecuteGrade() const {return _executeGrade; }


short Form::ValidateGrade(unsigned char grade){

	if(grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;

}

bool Form::beSigned(Bureaucrat bureaucrat){

	if (bureaucrat.getGrade() <= _signeGrade) {
		_signed = true;
		return true;
	}
	else
		throw GradeTooLowException();
}
