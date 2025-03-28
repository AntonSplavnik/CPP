/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:13:35 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/28 13:26:04 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.hpp"
#include <iostream>
#include <string>

FixedPoint::FixedPoint() {

	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

FixedPoint::FixedPoint(const FixedPoint &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = other._fixedPoint;
}

FixedPoint &FixedPoint::operator=(const FixedPoint &other) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_fixedPoint = other._fixedPoint;

	return (*this);
}

FixedPoint::~FixedPoint () {

	std::cout << "Destructor called" << std::endl;
}

int FixedPoint::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void FixedPoint::setRawBits ( int const raw ) {

	_fixedPoint = raw << _fractionalBits;
}
