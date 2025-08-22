/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 14:59:09 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void correctBehaviorTest(){

	std::cout << "=== Correct behavior test ===" << std::endl << std::endl;

	try {
		Bureaucrat ananas = Bureaucrat("Ananas", 150);
		std::cout << ananas << std::endl;

		ananas.incrementGrade();
		std::cout << " == Grade incremented\n" << ananas << std::endl;

		ananas.decrementGrade();
		std::cout << " == Grade decremented\n" << ananas << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
}

void exceptionsTest() {

	std::cout << "=== Eceptions test ===" << std::endl << std::endl;

	std::cout << " == Should throw exception GradeTooHigh ===" << std::endl;
	try	{
		Bureaucrat ananas0 = Bureaucrat("Ananas", 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << " == Should throw exception GradeTooLow ===" << std::endl;
	try {
		Bureaucrat ananas151 = Bureaucrat("Ananas", 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

}

int main(void){

	correctBehaviorTest();
	exceptionsTest();

	return 0;
}
