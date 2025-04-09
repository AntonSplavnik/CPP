/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:46:33 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/04/09 16:41:24 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain()
	 : _ideaCount(0) {

	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
	 : _ideaCount(other._ideaCount) {

	std::cout << "Brain default copy constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {

	std::cout << "Brain default copy constructor called" << std::endl;

	if (this != &other) {
		_ideaCount = other._ideaCount;

		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}

	return (*this);
}

Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(const std::string& idea) {

	if (_ideaCount < 100)
		ideas[_ideaCount++] = idea;
	else
		std::cout << "Brain is full. Cannot add more ideas.\n";
}

std::string Brain::getIdea(int index) const {

	if (index >= 0 && index < _ideaCount)
		return ideas[index];
	return "[empty]";
}

void Brain::printAllIdeas() const {

	for (int i = 0; i < _ideaCount; ++i)
		std::cout << "Idea[" << i << "]: " << ideas[i] << std::endl;
}