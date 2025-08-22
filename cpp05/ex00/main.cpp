/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/14 14:51:20 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){

	try
	{
		Bureaucrat ananas = Bureaucrat("Ananas", 150);
		std::cout << ananas << std::endl;

		ananas.incrementGrade();
		std::cout << ananas<< std::endl;

		ananas.decrementGrade();
		std::cout << ananas<< std::endl;

		// exception
		ananas.decrementGrade();
		Bureaucrat ananas0 = Bureaucrat("Ananas", 0);
		Bureaucrat ananas151 = Bureaucrat("Ananas", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
