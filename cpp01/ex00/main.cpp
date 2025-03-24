/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:28 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 13:26:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main( void ) {

	Zombie zombieManager("zombieManager");

	Zombie* biba = zombieManager.newZombie("Biaba");
	biba->announce();
	delete (biba);

	zombieManager.randomChump("Boba");

	return (0);
}