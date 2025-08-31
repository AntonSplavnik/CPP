/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:26:34 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 17:04:57 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void swapTest(){

	std::cout << "=== Swap Test ===" <<std::endl;

	int a = 2;
	int b = 5;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b <<  std::endl;

	swap<int>(a , b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b <<  std::endl;

}

void minTest(){

	std::cout << "=== Min/Max Test ===" <<std::endl;
	int a = 10;
	int b = 25;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b <<  std::endl;

	int minResult = min<int>(a , b);

	std::cout << "min value = " << minResult << std::endl;

	minResult = max<int>(a , b);

	std::cout << "max value = " << minResult << std::endl;


	std::cout << " -- equal values --" <<std::endl;

	a = 10;
	b = 10;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b <<  std::endl;

	minResult = min<int>(a , b);

	std::cout << "equal value = " << minResult << std::endl;

}

int main(){

	swapTest();
	minTest();

	return 0;
}
