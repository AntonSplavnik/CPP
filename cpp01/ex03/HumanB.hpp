/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:10 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/24 18:53:24 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string _name );
	~HumanB();

	void	setWeapon(Weapon &wepon);
	void	attack();

private:

	std::string	_name;
	Weapon		*_weapon;

};

#endif