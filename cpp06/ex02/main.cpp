/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:43 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/01 12:39:47 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(){

	try
	{
		for (size_t i = 0; i < 5; i++)
		{
			Base* randomClass = generate();
			Base& randomClassRef = *randomClass;

			std::cout << " -- Test " << i+1 << " -- " << std::endl;

			std::cout << "Identify random class by pointer: ";
			identify(randomClass);
			std::cout << "Identify random class by reference: ";
			identify(randomClassRef);

			delete randomClass;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
