/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:30:06 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/26 16:35:44 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av ) {

	if (ac != 2 || std::string (av[1]).empty())
		return (1);

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string input = av[1];
	bool match = false;

	for (int i = 0; i < 4; i++) {

		if (input == levels[i]) {

			Harl harl;

			harl.complain(input);
			harl.complain(input);
			harl.complain(input);
			harl.complain(input);

			match = true;
			break;
		}
	}
	if (!match)
		std::cout << "wrong input" << std::endl;
	return (0);
}