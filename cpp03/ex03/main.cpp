/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:33:53 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/03 21:32:36 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {

	std::cout << "\n[ Test 1: Default Constructor ]" << std::endl;
	DiamondTrap dt1;

	std::cout << "\n[ Test 2: Param Constructor ]" << std::endl;
	DiamondTrap dt2("Bob");

	std::cout << "\n[ Test 3: whoAmI() Identity ]" << std::endl;
	dt2.whoAmI();

	std::cout << "\n[ Test 4: Copy Constructor ]" << std::endl;
	DiamondTrap dt3(dt2);
	dt3.whoAmI();

	std::cout << "\n[ Test 5: Assignment Operator ]" << std::endl;
	dt1 = dt2;
	dt1.whoAmI();

	std::cout << "\n[ Test 6: Attack Method (from ScavTrap) ]" << std::endl;
	dt2.ClapTrap::attack("target dummy");
	dt2.attack("target dummy");

	std::cout << "\n[ Test 7: Manual Value Check ]" << std::endl;
	std::cout << "Hit Points: " << dt2.getMaxHitPoints() << std::endl;
	std::cout << "Energy Points: " << dt2.getMaxEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << dt2.getMaxAttackDamage() << std::endl;

	std::cout << "\n[ Test 8: Destructors Called on Exit ]" << std::endl;

	return (0);
}
