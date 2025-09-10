/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:17:01 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/09 16:47:20 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "vector"

int main(){

	Span test(20000);
	test.addNumber(1);
	test.addNumber(1);
	test.addNumber(6);
	test.addNumber(5);
	test.printSpan();

	test.longestSpan();
	test.shortestSpan();


	std::vector<unsigned int> testVector;
	for (size_t i = 0; i < 10000; i++)
		testVector.push_back(i);

	test.addRange(testVector.begin(), testVector.end());

	test.printSpan();

	return 0;
}

