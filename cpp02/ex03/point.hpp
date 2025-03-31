/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:54:33 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/31 15:26:47 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "fixed.hpp"

class Point {

public:

	Point();
	Point(const float x, const float y);
	Point(Point const& other);
	Point& operator=(Point const& other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;


private:

	Fixed const _x;
	Fixed const _y;

};

Fixed fixed_abs(Fixed const& value);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif