/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:07:25 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 21:09:16 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {

	public:
		Bureaucrat(const std::string, unsigned char grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		short getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		std::string getName() const;
		void setName(std::string name);
		void signForm(AForm& form);
		void executeForm(const AForm& form) const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too High!";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too low!";
			}
		};

	private:
		const std::string _name;
		unsigned char _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif
