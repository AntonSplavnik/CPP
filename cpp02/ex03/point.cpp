/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:55:50 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/31 16:18:48 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "point.hpp"

Point::Point()
	 : _x(0), _y(0)
{}

Point::Point(const float x, const float y)
	 : _x(x), _y(y)
{}


Point::Point(Point const& other)
	 : _x(other._x), _y(other._y)
{}

// Point& Point::operator=(Point const& other) {}

Point::~Point(){}

Fixed Point::getX() const{

	return (this->_x);
}

Fixed Point::getY() const{

	return (this->_y);
}

Fixed fixed_abs(Fixed const& value) {

	return ((value < Fixed(0))? Fixed(-value.toFloat()) : value);
}