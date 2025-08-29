/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:51:07 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/29 15:17:12 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av){
	(void)ac;
	std::string input = av[1];
	if (av[1] == NULL)
		return 1;
	ScalarConverter::convert(input);
	return 0;
}
