/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:28 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:42 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main( void ) {

	Zombie zombieManager("zombieManager");

	Zombie* horde = zombieManager.zombieHorde(3, "biba");

	for (size_t i = 0; i < 3; i++)
		horde[i].announce();

	delete[] (horde);

	return (0);
}