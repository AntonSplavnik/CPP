/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:53:30 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

void correctBehaviorTest() {

	std::cout << " === Correct Behavior Test === " << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Bureaucrat denis = Bureaucrat("Denis", 5);
		denis.signForm(*rrf);
		denis.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void cornerCaseBehaviorTest() {

	std::cout << " === Corner Case Behavior Test === " << std::endl;
	try
	{
		std::cout << " == Expected an exception" << std::endl;
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy ", "Bender");
		Bureaucrat denis = Bureaucrat("Denis", 5);
		denis.signForm(*rrf);
		denis.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}


int main(void) {

	srand(time(NULL));

	correctBehaviorTest();
	cornerCaseBehaviorTest();

	return 0;
}
