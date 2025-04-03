/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    FragTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:51:09 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/02 19:05:59 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ScavTrap {

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(FragTrap& other);
	FragTrap& operator=(FragTrap& other);
	~FragTrap();

	void highFivesGuys(void);

};
#endif
