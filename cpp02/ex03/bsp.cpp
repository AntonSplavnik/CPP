/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:18:38 by asplavni          #+#    #+#             */
/*   Updated: 2025/03/31 15:38:08 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Binary Space Partitioning
#include "point.hpp"
#include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	//area = abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0)

	Fixed areaABC = fixed_abs(
	((a.getX())*(b.getY() - c.getY())
	+ b.getX()*(c.getY() - a.getY())
	+ c.getX()*(a.getY() - b.getY()))
	/ Fixed(2)
	);

	Fixed areaPBC = fixed_abs(
	(point.getX() * (b.getY() - c.getY())
	+ b.getX() * (c.getY() - point.getY())
	+ c.getX() * (point.getY() - b.getY()))
	/ Fixed(2)
	);

	Fixed areaAPC = fixed_abs(
	(a.getX() * (point.getY() - c.getY())
	+ point.getX() * (c.getY() - a.getY())
	+ c.getX() * (a.getY() - point.getY()))
	/ Fixed(2)
	);

	Fixed areaABP = fixed_abs(
	(a.getX() * (b.getY() - point.getY())
	+ b.getX() * (point.getY() - a.getY())
	+ point.getX() * (a.getY() - b.getY()))
	/ Fixed(2)
	);

	if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
		return false; // Point is on edge or vertex

	return (areaABC == areaPBC + areaAPC + areaABP);
}
