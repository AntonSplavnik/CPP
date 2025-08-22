/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:20:01 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/20 23:12:11 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <sstream>

class ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm(const std::string formTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		std::string getUniqueFilename() const;
		void execute(const Bureaucrat& executor) const;

	private:
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		const std::string _formTarget;
};

#endif
