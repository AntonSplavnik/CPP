/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:06 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 13:35:57 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool toInt(const std::string& str, int& result) {
	std::stringstream ss(str);
	return (ss >> result) ? true : false;
}

int main(int ac, char **av ) {

	if (ac != 2 || std::string (av[1]).empty()){
		return (1);
	}

	std::string input = av[1];
	int level;

	if (!toInt(input,level)) {
		std::cerr << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
		return (1);
	}

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	Harl harl;
	switch (level) {
		case 1:
			harl.complain(levels[0]);
		case 2:
			harl.complain(levels[1]);
		case 3:
			harl.complain(levels[2]);
		case 4:
			harl.complain(levels[3]);
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}

	return (0);
}