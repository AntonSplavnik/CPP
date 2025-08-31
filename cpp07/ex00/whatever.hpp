/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:21:45 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 16:50:19 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b){

	T buff = a;
	a = b;
	b = buff;
}

template <typename T>
const T& min(const T& a, const T& b){
	if(a == b) return b;
	return (a < b)? a : b;

}

template <typename T>
const T& max(const T& a, const T& b){
	if(a == b) return b;
	return (a > b)? a : b;

}

#endif
