/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:23:17 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/04 16:53:07 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

public:

	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();

	void makeSound();
	virtual const char* getType();

protected:

	std::string _type;

};

#endif