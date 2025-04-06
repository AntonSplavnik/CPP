/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:46:33 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/05 15:06:59 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain() {

	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {

	std::cout << "Brain default copy constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {

	std::cout << "Brain default copy constructor called" << std::endl;

	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];

	return (*this);
}

Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl;
}
