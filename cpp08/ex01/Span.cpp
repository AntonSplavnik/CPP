/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:24:00 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/09/10 18:02:58 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>

Span::Span(int spanLen)
	:_n(spanLen){}

Span::Span(const Span& other)
	: _n(other._n), _span(other._span) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_span = other._span;
	}
	return *this;
}
Span::~Span(){}

void Span::addNumber(unsigned int inputNumber){
	if(_span.size() >= _n)
		throw std::out_of_range("The span in full");
	else
		_span.push_back(inputNumber);
}

unsigned int Span::shortestSpan(){

	if(_span.size() < 2)
		throw std::out_of_range("Not enough elements");

	std::sort(_span.begin(), _span.end());
	unsigned int minSpan = *((_span.begin()) + 1) - *(_span.begin());

	for(std::vector<unsigned int>::iterator it = _span.begin(); it != _span.end() - 1; ++it){
		unsigned int currentSpan = *(it + 1) - *it;
		if(currentSpan < minSpan)
			minSpan = currentSpan;
	}

	return minSpan;
}

unsigned int Span::longestSpan(){

	if(_span.size() < 2)
		throw std::out_of_range("The span is full");

	std::vector<unsigned int>::iterator min = std::min_element(_span.begin(), _span.end());
	std::vector<unsigned int>::iterator max = std::max_element(_span.begin(), _span.end());
	unsigned int longestSpan = *max - *min;

	std::cout << "The longest span is: " << longestSpan << std::endl;

	return longestSpan;
}

void Span::printSpan(){

	for(std::vector<unsigned int>::iterator it = _span.begin(); it != _span.end(); ++it)
		std::cout << *it << std::endl;
}
