/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:43:37 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/08 12:16:40 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main(){

	try
	{
		std::vector<int> vectorTest;
		vectorTest.push_back(12);
		vectorTest.push_back(22);
		vectorTest.push_back(2);
		vectorTest.push_back(51);
		vectorTest.push_back(12);
		vectorTest.push_back(62);

		int target = 12;
		easyfind(vectorTest, target);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
