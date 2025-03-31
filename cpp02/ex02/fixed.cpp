/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:13:35 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/31 14:38:03 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed Fixed::operator+( const Fixed &other ) const {

	Fixed object;

	object._fixedPoint = this->_fixedPoint + other._fixedPoint;
	return (object);
}

Fixed Fixed::operator-( const Fixed &other) const {

	Fixed object;

	object._fixedPoint = this->_fixedPoint - other._fixedPoint;
	return (object);
}

Fixed Fixed::operator*( const Fixed &other ) const {

	Fixed object;

	long raw = static_cast<long>(this->_fixedPoint) * other._fixedPoint;
	object.setRawBits(static_cast<int>(raw >> object._fractionalBits));
	return (object);
}

Fixed Fixed::operator/( const Fixed &other ) const {

	Fixed object;

	if (other._fixedPoint == 0) {
		std::cout << "division by 0 is unavalable" << std::endl;
		return (1);
	}
	long raw = (static_cast<long>(this->_fixedPoint) << other._fractionalBits) / other._fixedPoint;
	object.setRawBits(static_cast<int>(raw));
	return (object);
}

bool Fixed::operator<( const Fixed &other ) const{

	return (this->_fixedPoint < other._fixedPoint);
}

bool Fixed::operator>( const Fixed &other ) const{

	return (this->_fixedPoint > other._fixedPoint);
}

bool Fixed::operator>=( const Fixed &other ) const{

	return (this->_fixedPoint >= other._fixedPoint);
}

bool Fixed::operator<=( const Fixed &other ) const{

	return (this->_fixedPoint <= other._fixedPoint);
}

bool Fixed::operator==( const Fixed &other ) const{

	return (this->_fixedPoint == other._fixedPoint);
}

bool Fixed::operator!=( const Fixed &other ) const{

	return (this->_fixedPoint != other._fixedPoint);
}


Fixed& Fixed::operator++() {

	this->_fixedPoint += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {

	Fixed object = *this;
	this->_fixedPoint += 1;
	return (object);
}

Fixed& Fixed::operator--() {

	this->_fixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {

	Fixed object = *this;

	object._fixedPoint -= 1;
	return (object);
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

Fixed& Fixed::min(Fixed &number1, Fixed &number2) {

	return (number1 < number2)? (number1) : (number2);
}

const Fixed& Fixed::min(const Fixed& number1, const Fixed& number2) {

	return (number1 < number2)? (number1) : (number2);
}

Fixed& Fixed::max(Fixed& number1, Fixed& number2) {

	return (number1 > number2)? (number1) : (number2);

}

const Fixed& Fixed::max(const Fixed& number1, const Fixed& number2) {

	return (number1 > number2)? (number1) : (number2);
}
