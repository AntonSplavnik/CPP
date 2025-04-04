/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:39:40 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/04 16:54:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {}
Dog::Dog(const Dog& other) {}
Dog& Dog::operator=(const Dog& other) {}
Dog::~Dog() {}

void makeSound() {

	std::cout << getType() <<

}

const char* Animal::getType () { return ("Dog");}