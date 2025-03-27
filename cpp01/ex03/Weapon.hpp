/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:44:04 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/27 14:08:47 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

public:

	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string& getType();
	void setType(std::string type);

private:

	std::string	_type;

};

#endif