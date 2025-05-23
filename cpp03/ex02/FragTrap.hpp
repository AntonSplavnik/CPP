/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:51:09 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/03 11:10:27 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:

	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	virtual int getMaxHitPoints() const;
	virtual int getMaxEnergyPoints() const;
	virtual int getMaxAttackDamage() const;
	virtual const char* getClassName() const;

	void highFivesGuys(void);

};

#endif
