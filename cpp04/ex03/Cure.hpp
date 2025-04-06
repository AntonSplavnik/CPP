/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:24:23 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/06 21:13:21 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{

	public:

		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		virtual Cure* clone() const;
		void use(ICharacter& target);

};

#endif
