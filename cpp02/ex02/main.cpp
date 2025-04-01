/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:52:54 by asplavni          #+#    #+#             */
/*   Updated: 2025/04/01 12:06:02 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	return 0;
}

/*
int main() {
	std::cout << "🔹 Constructors & << operator:" << std::endl;
	Fixed a;                          // default
	Fixed b(5);                       // int constructor
	Fixed c(3.14f);                   // float constructor
	Fixed d(b);                       // copy constructor
	a = c;                            // copy assignment
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n🔹 Arithmetic operators:" << std::endl;
	Fixed add = b + c;
	Fixed sub = b - c;
	Fixed mul = b * c;
	Fixed div = b / c;
	std::cout << "b + c = " << add << std::endl;
	std::cout << "b - c = " << sub << std::endl;
	std::cout << "b * c = " << mul << std::endl;
	std::cout << "b / c = " << div << std::endl;

	std::cout << "\n🔹 Comparison operators:" << std::endl;
	std::cout << "b < c? " << (b < c) << std::endl;
	std::cout << "b > c? " << (b > c) << std::endl;
	std::cout << "b == d? " << (b == d) << std::endl;
	std::cout << "b != c? " << (b != c) << std::endl;

	std::cout << "\n🔹 Increment / Decrement:" << std::endl;
	Fixed inc;
	std::cout << "inc = " << inc << std::endl;
	std::cout << "++inc = " << ++inc << std::endl;
	std::cout << "inc++ = " << inc++ << std::endl;
	std::cout << "inc = " << inc << std::endl;
	std::cout << "--inc = " << --inc << std::endl;
	std::cout << "inc-- = " << inc-- << std::endl;
	std::cout << "inc = " << inc << std::endl;

	std::cout << "\n🔹 Min / Max:" << std::endl;
	Fixed x(10);
	Fixed y(42.42f);
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

	const Fixed cx(0.25f);
	const Fixed cy(0.75f);
	std::cout << "min(const) = " << Fixed::min(cx, cy) << std::endl;
	std::cout << "max(const) = " << Fixed::max(cx, cy) << std::endl;

	std::cout << "\n🔹 Division by zero (edge case):" << std::endl;
	Fixed zero;
	Fixed result = b / zero; // should trigger your safe fallback
	std::cout << "b / 0 = " << result << std::endl;

	return 0;
}
 */