/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:33:53 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/02 11:52:11 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	// Test constructor
	ClapTrap clap1("Bob");

	// Test attack
	clap1.attack("target dummy");

	// Test take damage
	clap1.takeDamage(3);

	// Test repair
	clap1.beRepaired(5);

	// Test multiple attacks (to use up energy)
	for (int i = 0; i < 10; ++i)
		clap1.attack("training bot");

	// Try attacking with 0 energy
	clap1.attack("low battery bot");

	// Test copy constructor
	ClapTrap clap2(clap1);
	clap2.attack("backup target");

	// Test assignment operator
	ClapTrap clap3("Temp");
	clap3 = clap1;
	clap3.attack("mirror target");

	// Damage until death
	for (int i = 0; i < 5; ++i)
		clap1.takeDamage(5);

	// Try repairing a dead ClapTrap
	clap1.beRepaired(10);

	// Try attacking while dead
	clap1.attack("unreachable target");

	return 0;
}