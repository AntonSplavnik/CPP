/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:51:07 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/02 14:47:47 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av){
	(void)ac;
	if (av[1] == NULL)
		return 1;
	ScalarConverter::convert(std::string (av[1]));
	return 0;
}
