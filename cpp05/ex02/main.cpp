/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:28:44 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

void testInvalidBureaucratCreation1() {

	std::cout << "=== Testing invalid grade 0 ===" << std::endl;
	try {
		Bureaucrat invalid1 = Bureaucrat("Ananas", 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n\n";
}

void testInvalidBureaucratCreation2() {

	std::cout << "=== Testing invalid grade 151 ===" << std::endl;
	try {
		Bureaucrat invalid2 = Bureaucrat("Ananas", 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\n\n";
}

void testFormOperations() {

	try
	{
		Bureaucrat buba = Bureaucrat("Buba", 5);
		Bureaucrat ananas = Bureaucrat("Ananas", 150);
		AForm* forms[3];
		forms[0] = new RobotomyRequestForm("Bender");
		forms[1] = new ShrubberyCreationForm("home");
		forms[2] = new PresidentialPardonForm("Kim Jong-un");

		std::cout << "=== Error catching tests ===" << std::endl;
		for (size_t i = 0; i < 3; i++) {
			ananas.signForm(*forms[i]);
			ananas.executeForm(*forms[i]);
		}
		std::cout << "\n\n\n";

		std::cout << "=== Correct behavior tests ===" << std::endl;
		for (size_t i = 0; i < 3; i++) {
			buba.signForm(*forms[i]);
			buba.executeForm(*forms[i]);
		}
		std::cout << "\n\n\n";

		std::cout << "=== Testing Robotomy Randomness ===" << std::endl;
		for (int i = 0; i < 5; i++)
		buba.executeForm(*forms[0]);
		std::cout << "\n\n\n";

		for (size_t i = 0; i < 3; i++)
			delete forms[i];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

 void testGradeModification() {

	std::cout << "=== Testing grade modification ===" << std::endl;
	try {
		Bureaucrat test("Test", 2);
		std::cout << test << std::endl;
		test.incrementGrade();
		std::cout << test << std::endl;
		test.incrementGrade();
	} catch(const std::exception& e) {
		std::cout << "Expected boundary error: " << e.what() << std::endl;
	}
	std::cout << "\n\n\n";
}

int main(void) {

	srand(time(NULL));

	testInvalidBureaucratCreation1();
	testInvalidBureaucratCreation2();
	testFormOperations();
	testGradeModification();

	return 0;
}
