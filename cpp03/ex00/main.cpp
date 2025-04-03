/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:33:53 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/02 20:44:49 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	std::cout << "Test constructor" << std::endl;
	ClapTrap clap1("Bob");
	std::cout << std::endl;

	std::cout << "Test attack" << std::endl;
	clap1.attack("target dummy");
	std::cout << std::endl;

	std::cout << "Test take damage" << std::endl;
	clap1.takeDamage(3);
	std::cout << std::endl;

	std::cout << "Test repair" << std::endl;
	clap1.beRepaired(5);
	std::cout << std::endl;

	std::cout << "Test multiple attacks (to use up energy)" << std::endl;
	for (int i = 0; i < 10; ++i)
		clap1.attack("training bot");
	std::cout << std::endl;

	std::cout << "Try attacking with 0 energy" << std::endl;
	clap1.attack("low battery bot");
	std::cout << std::endl;

	std::cout << "Test copy constructor" << std::endl;
	ClapTrap clap2(clap1);
	clap2.attack("backup target");
	std::cout << std::endl;

	std::cout << "Test assignment operator" << std::endl;
	ClapTrap clap3("Temp");
	clap3 = clap1;
	clap3.attack("mirror target");
	std::cout << std::endl;

	std::cout << "Damage until death" << std::endl;
	for (int i = 0; i < 5; ++i)
		clap1.takeDamage(5);
	std::cout << std::endl;

	std::cout << "Try repairing a dead ClapTrap" << std::endl;
	clap1.beRepaired(10);
	std::cout << std::endl;

	std::cout << "Try attacking while dead" << std::endl;
	clap1.attack("unreachable target");
	std::cout << std::endl;

	return 0;
}
