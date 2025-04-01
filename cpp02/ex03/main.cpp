/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:52:54 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/01 12:15:46 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main() {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	// Clearly inside
	Point p1(5.0f, 5.0f);
	std::cout << "p1 is inside? " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;

	// Clearly outside
	Point p2(15.0f, 5.0f);
	std::cout << "p2 is inside? " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;

	// On edge AB
	Point p3(5.0f, 0.0f);
	std::cout << "p3 is inside? " << (bsp(a, b, c, p3) ? "Yes" : "No") << std::endl;

	// At vertex C
	Point p4(5.0f, 10.0f);
	std::cout << "p4 is inside? " << (bsp(a, b, c, p4) ? "Yes" : "No") << std::endl;

	return 0;
}
