/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:47:18 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 17:17:13 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class AForm {

	public:
		AForm(const std::string name, unsigned char signeGrade, unsigned char executeGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		std::string getName() const;
		bool getSigneStatus() const;
		short getSigneGrade() const;
		short getExecuteGrade() const;
		short validateGrade(unsigned char grade);
		void requiermentsCheck(const Bureaucrat& bureaucrat) const;
		bool beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;

	private:
		const std::string _name;
		bool _signed;
		const unsigned char _signeGrade;
		const unsigned char _executeGrade;
	AForm& operator=(const AForm& other);

	class FormIsNotSignedException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Form is not signed!";
			}
	};

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

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
