/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:25:16 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 21:37:26 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:

		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		virtual Ice* clone() const;
		void use(ICharacter& target);

};

#endif
