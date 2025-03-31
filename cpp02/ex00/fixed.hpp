/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:58:00 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/31 14:38:50 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
