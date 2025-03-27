/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:21:40 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 14:12:30 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie();
	Zombie( std::string	name );
	~Zombie();


	void announce( void );
	Zombie* zombieHorde( int N, std::string name );

private:

	std::string	_name;
};

#endif