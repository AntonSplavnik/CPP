/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:24:40 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 23:20:26 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern();
		~Intern();
		int getFormType(std::string formName);
		AForm* makeForm(std::string formName, std::string formTarget);

		class UnknownFormTypeException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Unknown form type!";
			}
		};
	private:
		Intern (const Intern& other);
		Intern& operator=(const Intern& other);
};

#endif
