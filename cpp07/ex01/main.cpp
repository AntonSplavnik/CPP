/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:39:46 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 17:48:53 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

template<typename T>
void printTemplate(const T& input){
	std::cout << input << std::endl;
}

void printInts(const int& number){
	std::cout << number << std::endl;
}


int main(){

	int numbers[5] = {1, 2, 3, 4, 5};
	iter(numbers, 5, printInts);
	iter(numbers, 5, printTemplate<int>);

	return 0;
}
