/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:13 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 14:09:24 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string _name, Weapon &weapon );
	~HumanA();

	void attack();

private:

	std::string	_name;
	Weapon		&_weapon;

};

#endif