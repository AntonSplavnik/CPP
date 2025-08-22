/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/14 19:03:26 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){

	try
	{
		Bureaucrat ananas = Bureaucrat("Ananas", 150);
		Form form = Form("LIght Fixing Form", 150, 150);

		ananas.signForm(form);

		///
		Bureaucrat mango = Bureaucrat("Mango", 150);
		Form form2 = Form("Room Fixing Form", 140, 150);

		mango.signForm(form2);
		///
		for (size_t i = 0; i < 10; i++)
			mango.incrementGrade();

		mango.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
