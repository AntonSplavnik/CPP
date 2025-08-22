/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:06:30 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/22 15:22:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


void expectedBehavior() {

	std::cout << "=== Expected Behavior Test ===" << std::endl;
	try {
		Bureaucrat ananas = Bureaucrat("Ananas", 150);
		Form form = Form("Light Fixing Form", 150, 150);
		std::cout << " == Form stats before signing" << std::endl;
		std::cout << form << std::endl;
		std::cout << std::endl
				  << " == Form stats after signing" << std::endl;
		ananas.signForm(form);
		std::cout << form << std::endl << std::endl;

	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
}

void exceptionsTest() {

	std::cout << "=== Exceptions Test ===" << std::endl;
	try {
		Bureaucrat mango = Bureaucrat("Mango", 150);
		Form form2 = Form("Room Fixing Form", 140, 150);
		std::cout << " == Form stats before signing with correct grade" << std::endl;
		std::cout << form2 << std::endl;
		mango.signForm(form2);
		for (size_t i = 0; i < 10; i++)
			mango.incrementGrade();
		std::cout << std::endl
				  << " == Form stats after signing with correct grade" << std::endl;
		mango.signForm(form2);
		std::cout << form2 << std::endl << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}

}

int main(void) {

	expectedBehavior();
	exceptionsTest();

	return 0;
}
