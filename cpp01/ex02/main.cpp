/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:11 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 16:41:46 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ( void ) {

	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;

	std::string &stringREF = string;

	std::cout << "The memory address of the string variable. " << &string << std::endl;
	std::cout << "The memory address held by stringPTR. "<< stringPTR << std::endl;
	std::cout << "The memory address held by stringREF. " << &stringREF << std::endl;

	std::cout << "The value of the string variable. " << string << std::endl;
	std::cout << "The value pointed to by stringPTR. "<< *stringPTR << std::endl;
	std::cout << "TThe value pointed to by stringREF. " << stringREF << std::endl;
}
