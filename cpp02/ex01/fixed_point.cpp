/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:13:35 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/28 22:41:28 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.hpp"
#include <iostream>
#include <string>
#include <cmath>

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;

	_fixedPoint = 0;
}

Fixed::Fixed(const int input) {

	std::cout << "Int constructor called" << std::endl;

	_fixedPoint = input << _fractionalBits;
}

Fixed::Fixed(const float input) {

	std::cout << "Float constructor called" << std::endl;

	//_fixedPoint = static_cast<int>(roundf(input * 256));
	_fixedPoint = static_cast<int>(roundf(input * (1 << _fractionalBits)));

}

Fixed::~Fixed () {

	std::cout << "Destructor called" << std::endl;
}



Fixed::Fixed(const Fixed &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = other._fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_fixedPoint = other._fixedPoint;

	return (*this);
}



int Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits ( int const raw ) {

	_fixedPoint = raw;
}


float Fixed::toFloat( void ) const {

	//return (_fixedPoint / 256.0f);
	return ( _fixedPoint / static_cast<float>(1 << _fractionalBits));
}

int Fixed::toInt( void ) const{

	//return _fixedPoint >> 8;
	return (_fixedPoint >> _fractionalBits);
}
