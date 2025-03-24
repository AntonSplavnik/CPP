/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:25:43 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 13:58:22 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie( std::string	name ) {
	this->_name = name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " is destroyed" << std::endl;
};


void Zombie::announce( void ) {

	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
