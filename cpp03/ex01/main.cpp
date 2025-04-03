/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:33:53 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/02 22:29:41 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "\n=== Testing ClapTrap ===" << std::endl;
	clap.attack("training dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.attack("ghost");
	clap.beRepaired(5);

	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("GateBot");

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	scav.attack("intruder");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n=== Demonstrating Copy Constructor ===" << std::endl;
	ScavTrap copyScav(scav);
	copyScav.attack("copy target");

	std::cout << "\n=== Demonstrating Assignment Operator ===" << std::endl;
	ScavTrap anotherScav("AnotherOne");
	anotherScav = scav;
	anotherScav.attack("assigned target");

	std::cout << "\n=== End of main ===" << std::endl;
	return 0;
}
