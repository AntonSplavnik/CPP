/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:58:00 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/28 13:13:35 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

class FixedPoint {

public:

	FixedPoint();
	FixedPoint(const FixedPoint &other);
	FixedPoint &operator=(const FixedPoint &other);
	~FixedPoint();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:

	int _fixedPoint;
	static const int _fractionalBits = 8;
};

#endif
