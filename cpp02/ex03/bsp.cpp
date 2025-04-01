/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:18:38 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/01 12:13:38 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Binary Space Partitioning
#include "Point.hpp"
#include <cmath>

Fixed triangle_area(Point const& p1, Point const& p2, Point const& p3) {

	//area = abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0)

	return (fixed_abs(
		(p1.getX() * (p2.getY() - p3.getY())
		+ p2.getX() * (p3.getY() - p1.getY())
		+ p3.getX() * (p1.getY() - p2.getY()))
		/ Fixed(2)
	));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed areaABC = triangle_area(a, b, c);
	Fixed areaPBC = triangle_area(point, b, c);
	Fixed areaAPC = triangle_area(a, point, c);
	Fixed areaABP = triangle_area(a, b, point);

	if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
		return false; // Point is on edge or vertex

	return (areaABC == areaPBC + areaAPC + areaABP);
}
