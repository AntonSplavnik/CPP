/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:28:27 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/02 18:39:10 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class ScavTrap: public ClapTrap {

public:

	ScavTrap();
	ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap(const ScavTrap& othere);
	ScavTrap& operator=(const ScavTrap& other);

	void guardGate();
	void attack(const std::string& target);
};

#endif
