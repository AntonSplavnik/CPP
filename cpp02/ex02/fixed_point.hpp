/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:58:00 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/30 23:03:05 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>

class Fixed {

public:

	Fixed operator+( const Fixed &other ) const;
	Fixed operator-( const Fixed &other) const;
	Fixed operator*( const Fixed &other ) const;
	Fixed operator/( const Fixed &other ) const;

	bool operator<( const Fixed &other ) const;
	bool operator>( const Fixed &other ) const;
	bool operator>=( const Fixed &other ) const;
	bool operator<=( const Fixed &other ) const;
	bool operator==( const Fixed &other ) const;
	bool operator!=( const Fixed &other ) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	~Fixed();

	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed& min(Fixed& number1, Fixed& number2);
	static const Fixed& min(const Fixed& number1, const Fixed& number2);

	static Fixed& max(Fixed& number1, Fixed& number2);
	static const Fixed& max(const Fixed& number1, const Fixed& number2);

private:

	int _fixedPoint;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif
