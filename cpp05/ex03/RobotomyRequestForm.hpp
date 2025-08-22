/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:21:04 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/21 15:42:06 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm(const std::string formTarget);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		void execute(const Bureaucrat& executor) const;

	private:
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		const std::string _formTarget;
};

#endif
