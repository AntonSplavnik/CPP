/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:58:00 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/30 19:42:11 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

class Fixed {

public:

	Fixed();
	~Fixed();

	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:

	int _fixedPoint;
	static const int _fractionalBits = 8;
};

#endif
