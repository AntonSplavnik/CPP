/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:28:27 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/04 09:55:49 by asplavni         ###   ########.fr       */
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
	ScavTrap(const ScavTrap& othere);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	virtual int getMaxHitPoints() const;
	virtual int getMaxEnergyPoints() const;
	virtual int getMaxAttackDamage() const;
	virtual const char* getClassName() const;

	void attack(const std::string& target);
	void guardGate();

};

#endif
