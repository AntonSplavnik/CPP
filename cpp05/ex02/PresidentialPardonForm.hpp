/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:21:00 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/20 23:22:47 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

	public:
		PresidentialPardonForm(const std::string formTarget);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute(const Bureaucrat& executor) const;

	private:
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		const std::string _formTarget;

};


#endif
