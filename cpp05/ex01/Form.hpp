/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:47:18 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/14 18:54:22 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	public:
		Form(const std::string name, unsigned char signeGrade, unsigned char executeGrade);
		Form(const Form& other);
		~Form();

		std::string getName() const;
		bool getSigneStatus() const;
		short getSigneGrade() const;
		short getExecuteGrade() const;

		short ValidateGrade(unsigned char grade);

		bool beSigned(Bureaucrat bureaucrat);

	private:
		const std::string _name;
		bool _signed;
		const unsigned char _signeGrade;
		const unsigned char _executeGrade;

	Form& operator=(const Form& other);

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Grade is too High!";
			}
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Grade is too Low!";
			}
	};

};

std::ostream& operator<<(std::ostream& out, const Form form);

#endif
