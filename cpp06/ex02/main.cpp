/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:43 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/01 12:30:11 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(){

	try
	{
		Base* randomClass = generate();
		Base& randomClassRef = *randomClass;

		std::cout << "Identify random class by pointer: ";
		identify(randomClass);
		std::cout << "Identify random class by reference: ";
		identify(randomClassRef);

		delete randomClass;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
