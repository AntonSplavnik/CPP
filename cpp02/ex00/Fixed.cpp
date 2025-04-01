/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:13:35 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/01 11:27:07 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = other._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_fixedPoint = other._fixedPoint;

	return (*this);
}

Fixed::~Fixed () {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits ( int const raw ) {

	_fixedPoint = raw << _fractionalBits;
}
