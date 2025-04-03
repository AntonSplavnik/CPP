/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:33:53 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/03 11:52:37 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "\n=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Froggo");

	std::cout << "\n=== Basic Action Test ===" << std::endl;
	frag.attack("enemy bot");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(25);

	std::cout << "\n=== Draining FragTrap energy ===" << std::endl;
	for (int i = 0; i < 100; ++i)
		frag.attack("dummy bot");

	frag.attack("final bot"); // should fail due to energy == 0
	frag.beRepaired(10);      // should also fail due to energy == 0

	std::cout << "\n=== Killing FragTrap ===" << std::endl;
	frag.takeDamage(999); // HP drops to 0
	frag.attack("ghost"); // should say it's dead
	frag.beRepaired(10);  // should say it's dead

	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	FragTrap copyFrag(frag);
	copyFrag.highFivesGuys();

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	FragTrap another("Backup");
	another = frag;
	another.attack("copied enemy");

	std::cout << "\n=== End of test ===" << std::endl;
	return 0;
}
