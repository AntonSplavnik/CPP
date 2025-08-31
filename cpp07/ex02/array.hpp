/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:01:40 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 20:07:24 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		T& operator[](size_t index);
		const T& operator[](size_t index) const;

		~Array();
		unsigned int size() const;

		class IndexOutOfBounds : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Index is out of bounds!";
			}
		};

	private:
		T* data;
		size_t _size;
};

#include "array.tpp"

#endif
