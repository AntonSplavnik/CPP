/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:45 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:57 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie* zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i ++)
		zombieHorde[i]._name = name;

	return (zombieHorde);
}
