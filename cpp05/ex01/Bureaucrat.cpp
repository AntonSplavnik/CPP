/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:09:57 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 21:17:53 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat){

	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned char grade)
	:_name(name){

	if (grade < 1 || grade > 150)
		(grade < 1 ) ? throw GradeTooHighException() : throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:_name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){

	if(this != &other){
		_grade = other._grade;
	}
	return(*this);
}
Bureaucrat::~Bureaucrat(){}

short Bureaucrat::getGrade(void) const{ return(_grade); }

std::string Bureaucrat::getName() const{ return(_name); }

void Bureaucrat::incrementGrade(void){

	if(_grade == 1) throw GradeTooHighException();
	_grade --;
}

void Bureaucrat::decrementGrade(void){

	if(_grade == 150) throw GradeTooLowException();
	_grade++;
}


void Bureaucrat::signForm(Form& form){

	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e){

		std::cout << _name << " couldn’t sign " << form.getName() << " -- " << e.what() << std::endl;
	}
}
