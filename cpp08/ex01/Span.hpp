/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:24:02 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/09 16:09:32 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span{

	public:
		Span(int spanLen);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(unsigned int inputNumber);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void printSpan();

		template<typename T>
		void addRange(T start, T end){
			for (T it = start; it != end; ++it)
				addNumber(*it);
		}

	private:
		unsigned int _n;
		std::vector<unsigned int> _span;

};

#endif
