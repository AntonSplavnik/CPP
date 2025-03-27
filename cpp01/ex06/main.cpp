/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:06 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 14:59:31 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool checkInput(const std::string& input, std::string levels[]) {

	bool flag = false;

	for (int i = 0; i < 4; i++) {
		if (input == levels[i])
			flag = true;
	}

	return (flag);
}

int main(int ac, char **av ) {

	if (ac != 2 || std::string (av[1]).empty()){
		return (1);
	}

	std::string input = av[1];
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelNumber[] = {1, 2, 3, 4};

	if (!checkInput(input, levels)) {
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
		return (1);
	}

	for (int i = 0; i < 4; i++) {
		if (input == levels[i]) {

			Harl harl;
			switch (levelNumber[i]) {
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
		}
	}

	return (0);
}
