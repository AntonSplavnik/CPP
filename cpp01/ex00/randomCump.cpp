/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomCump.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:32:56 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 13:34:41 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {

	Zombie zombie(name);
	zombie.announce();
}