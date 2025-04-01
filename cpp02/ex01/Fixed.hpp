/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:58:00 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/01 11:33:58 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	public:

	Fixed();
	Fixed(const int input);
	Fixed(const float input);
	~Fixed();

	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	private:

	int _fixedPoint;
	static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
